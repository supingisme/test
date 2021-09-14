/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:47 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:36:24 CST. 
*/
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.            */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <errno.h>

#include <fcntl.h>      /* non-ANSI */
#include <unistd.h>     /* non-ANSI */
#include <sys/types.h>  /* non-ANSI */

#include "getpars.h"



/*  definitions of global variables */
int xargc; char **xargv;


/* global variables declared and used internally */
static pointer_table *argtbl;    /* parameter table        */
static int nargs;        /* number of args that parse    */
static int tabled = FALSE;    /* true when parameters tabled     */
static size_t targc;        /* total number of args        */
static char **targv;        /* pointer to arg strings    */
static char *argstr;        /* storage for command line    */

/* functions declared and used internally */
static int getparindex (int n, char *name);
static void getparinit(void);
static void tabulate (size_t argc, char **argv);
static char *getpfname (void);

static int ccount (char c, char *s);

#define PAR_NAMES_MAX 512

static char* par_names[PAR_NAMES_MAX];
static int   par_count=0;
static int parcheck = 0;


/* make command line args available to subroutines -- re-entrant version */
void initargs(int argc, char **argv)
{
    memset( par_names ,0 ,sizeof(par_names) );
    par_names[0] = "par";
    par_names[1] = "lheader";
    par_count=2;

    xargc = argc; xargv = argv;
    if(tabled==TRUE){
        free(argstr);
        free(targv);
        free(argtbl);
    }
    tabled =  FALSE;
    return;
}





void requestdoc(int flag)
{
        switch(flag) {
        case 1:
                if (xargc == 1 && isatty(fileno(stdin))) pagedoc();
        break;
        case 0:
                if (xargc == 1 && isatty(fileno(stdin)) && isatty(fileno(stdin))) pagedoc();
        break;
        default:
                if (xargc <= flag) pagedoc();
        break;
        }
        return;
}


void pagedoc(void)
{
        extern char *sdoc[];
        char **p = sdoc;
        FILE *fp;
        char *pager;
        char cmd[32];

        if ((pager=getenv("PAGER")) != (char *)NULL)
            sprintf(cmd,"%s 1>&2", pager);
        else 
            sprintf(cmd,"more 1>&2");


        fflush(stdout);
       /*  fp = popen("more -22 1>&2", "w"); */
       /*  fp = popen("more  1>&2", "w"); */
        fp = (FILE *) popen(cmd, "w");
    while(*p) (void)fprintf(fp, "%s\n", *p++);
        pclose(fp);

        exit(1);
}


/* functions to get values for the last occurrence of a parameter name */
int getparint (char *name, int *ptr)
{
    return getnpar(0,name,"i",ptr);
}
int getparuint (char *name, unsigned int *ptr)
{
    return getnpar(0,name,"p",ptr);
}
int getparshort (char *name, short *ptr)
{
    return getnpar(0,name,"h",ptr);
}
int getparushort (char *name, unsigned short *ptr)
{
    return getnpar(0,name,"u",ptr);
}
int getparlong (char *name, long *ptr)
{
    return getnpar(0,name,"l",ptr);
}
int getparulong (char *name, unsigned long *ptr)
{
    return getnpar(0,name,"v",ptr);
}
int getparfloat (char *name, float *ptr)
{
    return getnpar(0,name,"f",ptr);
}
int getpardouble (char *name, double *ptr)
{
    return getnpar(0,name,"d",ptr);
}
int getparstring (char *name, char **ptr)
{
    return getnpar(0,name,"s",ptr);
}
int getparstringarray (char *name, char **ptr)
{
    return getnpar(0,name,"a",ptr);
}
int getpar (char *name, char *type, void *ptr)
{
    return getnpar(0,name,type,ptr);
}

/* functions to get values for the n'th occurrence of a parameter name */
int getnparint (int n, char *name, int *ptr)
{
    return getnpar(n,name,"i",ptr);
}
int getnparuint (int n, char *name, unsigned int *ptr)
{
    return getnpar(n,name,"p",ptr);
}
int getnparshort (int n, char *name, short *ptr)
{
    return getnpar(n,name,"h",ptr);
}
int getnparushort (int n, char *name, unsigned short *ptr)
{
    return getnpar(n,name,"u",ptr);
}
int getnparlong (int n, char *name, long *ptr)
{
    return getnpar(n,name,"l",ptr);
}
int getnparulong (int n, char *name, unsigned long *ptr)
{
    return getnpar(n,name,"v",ptr);
}
int getnparfloat (int n, char *name, float *ptr)
{
    return getnpar(n,name,"f",ptr);
}
int getnpardouble (int n, char *name, double *ptr)
{
    return getnpar(n,name,"d",ptr);
}
int getnparstring (int n, char *name, char **ptr)
{
    return getnpar(n,name,"s",ptr);
}
int getnparstringarray (int n, char *name, char **ptr)
{
    return getnpar(n,name,"a",ptr);
}
int getnpar (int n, char *name, char *type, void *ptr)
{
    int i;            /* index of name in symbol table    */
    int j;          /* index for par_names[]        */
    int nval;        /* number of parameter values found    */
    char *aval;        /* ascii field of symbol        */

/*--------------------------------------------------------------------*\
   getpar gets called in loops reading traces in some programs.  So
   check for having seen this name before. Also make sure we don't
   walk off the end of the table.
\*--------------------------------------------------------------------*/

    if( parcheck && strcmp( "lheader" ,name ) ){
       fprintf( stderr ,"getpar() call after checkpars(): %s\n" ,name );
    }

    for( j=0; j<par_count; j++ ){
       if( !strcmp( par_names[j] ,name ) ){
        break;
       }
    }

    if( j >= par_count && par_count < PAR_NAMES_MAX ){
       par_names[par_count++] = name;
    }

    if(  par_count == PAR_NAMES_MAX ){
       fprintf( stderr, " %s exceeded PAR_NAMES_MAX %d \n" ,xargv[0] ,PAR_NAMES_MAX );
    }

    if (xargc == 1) return 0;
    if (!tabled) getparinit();/* Tabulate command line and parfile */
    i = getparindex(n,name);/* Get parameter index */
    if (i < 0) return 0;    /* Not there */

    if (0 == ptr) {
       fprintf(stderr, "%s: getnpar called with 0 pointer, type = %s", __FILE__,type);
       exit(0);
    }
      

    /*
     * handle string type as a special case, since a string
     * may contain commas.
     */
    if (type[0]=='s') 
    {
        *((char**)ptr) = argtbl[i].asciival;
        return 1;
    }

    /* convert vector of ascii values to numeric values */
    for (nval=0,aval=argtbl[i].asciival; *aval; nval++) 
    {
        switch (type[0]) {
            case 'i':
                *(int*)ptr = estrtoi(aval);
                ptr = (int*)ptr+1;
                break;
            case 'p':
                *(unsigned int*)ptr = estrtoui(aval);
                ptr = (unsigned int*)ptr+1;
                break;
            case 'h':
                *(short*)ptr = estrtoh(aval);
                ptr = (short*)ptr+1;
                break;
            case 'u':
                *(unsigned short*)ptr = estrtous(aval);
                ptr = (unsigned short*)ptr+1;
                break;
            case 'l':
                *(long*)ptr = estrtol(aval);
                ptr = (long*)ptr+1;
                break;
            case 'v':
                *(unsigned long*)ptr = estrtoul(aval);
                ptr = (unsigned long*)ptr+1;
                break;
            case 'f':
                *(float*)ptr = estrtof(aval);
                ptr = (float*)ptr+1;
                break;
            case 'd':
                *(double*)ptr = estrtod(aval);
                ptr = (double*)ptr+1;
                break;
            case 'a':
                { char *tmpstr="";
                   tmpstr = malloc(strlen(aval)+1);

                   strchop(aval,tmpstr);
                   *(char**)ptr = tmpstr;
                   ptr=(char **)ptr + 1;
                }
                   break;
            default:
                fprintf(stderr, "%s: invalid parameter type = %s",
                    __FILE__,type);
                exit(1);
        }
        while (*aval++ != ',') {
            if (!*aval) break;
        }
    }
    return nval;
}

void checkpars( void ){

   int i;
   int j;
   char buf[256];

   if( getparint( "verbose" ,&i ) && i == 1 ){

#ifdef SUXDR
      fprintf( stderr ,"Using Big Endian SU data format w/ XDR.\n" );
#else
      fprintf( stderr ,"Using native byte order SU data format w/o XDR.\n" );
#endif

   }

   for( j=1; j<xargc; j++){

    for( i=0; i<par_count; i++ ){
     sprintf( buf ,"%s=" ,par_names[i] );

     if( !strncmp( buf ,xargv[j] ,strlen(buf) ) ){
        break;
     }
    }
    if( i == par_count && strchr( xargv[j] ,'=' ) ){
     fprintf( stderr ,"Unknown %s argument %s\n" ,xargv[0] ,xargv[j] );
    }

   }

   parcheck = 1;
}

/* return number of occurrences of parameter name */
int countparname (char *name)
{
    int i,nname;

    if (xargc == 1) return 0;
    if (!tabled) getparinit();
    for (i=0,nname=0; i<nargs; ++i)
        if (!strcmp(name,argtbl[i].name)) ++nname;
    return nname;
}

/* return number of values in n'th occurrence of parameter name */
int countnparval (int n, char *name)
{
    int i;

    if (xargc == 1) return 0;
    if (!tabled) getparinit();
    i = getparindex(n,name);
    if (i>=0)
        return ccount(',',argtbl[i].asciival) + 1;
    else
        return 0;
}

/* return number of values in last occurrence of parameter name */
int countparval (char *name)
{
    return countnparval(0,name);
}



/*
 * Return the index of the n'th occurrence of a parameter name,
 * except if n==0, return the index of the last occurrence.
 * Return -1 if the specified occurrence does not exist.
 */
static int getparindex (int n, char *name)
{
    int i;
    if (n==0) {
        for (i=nargs-1; i>=0; --i)
            if (!strcmp(name,argtbl[i].name)) break;
        return i;
    } else {
        for (i=0; i<nargs; ++i)
            if (!strcmp(name,argtbl[i].name))
                if (--n==0) break;
        if (i<nargs)
            return i;
        else
            return -1;
    }
}

/* Initialize getpar */

static void getparinit (void)
{
    static char *pfname;    /* name of parameter file        */
    FILE *pffd=NULL;    /* file id of parameter file        */
    size_t pflen;        /* length of parameter file in bytes    */
/*    static size_t pfargc;*/    /* arg count from parameter file    */
    int parfile;        /* parfile existence flag        */
    int argstrlen=0;
    char *pargstr;        /* storage for parameter file args    */
    size_t nread=0;        /* bytes fread                */
    int i, j;        /* counters                */
    int start = TRUE;
    int debug = FALSE;
    int quote = FALSE;


    tabled = TRUE;        /* remember table is built        */


    /* Check if xargc was initiated */

    if(!xargc)
    {   
        fprintf(stderr, "%s: xargc=%d -- not initiated in main", __FILE__, xargc);
        exit(1);
    }

    /* Space needed for command lines */

    for (i = 1, argstrlen = 0; i < xargc; i++) {
        argstrlen += strlen(xargv[i]) + 1;
    }

    /* Get parfile name if there is one */

    if ((pfname = getpfname())) {
        parfile = TRUE;
    } else {
        parfile = FALSE;
    }

    if (parfile) {
         pffd = fopen(pfname, "r");

        /* Get the length */
        fseek(pffd, 0, 2);

        pflen = (long) ftell(pffd);

        rewind(pffd);
        argstrlen += pflen;
    } else {
        pflen = 0;
    }

/*--------------------------------------------------------------------*\
   Allocate space for command line and parameter file. The pointer
   table could be as large as the string buffer, but no larger.

   The parser logic has been completely rewritten to prevent bad
   input from crashing the program.

   Reginald H. Beardsley                rhb@acm.org
\*--------------------------------------------------------------------*/

    argstr = (char *) malloc(argstrlen+1);
    targv = (char **) malloc((argstrlen+1)/4*sizeof(char*));

    if (parfile) {
        /* Read the parfile */

        nread = fread(argstr, 1, pflen, pffd);
          if (nread != pflen) 
        {
               fprintf(stderr, "%s: fread only %d bytes out of %d from %s",
                      __FILE__,  nread, pflen, pfname);
            exit(1);
        }
        fclose(pffd);


/*    } else {
        pfargc = 0;
*/
    }


    /* force input to valid 7 bit ASCII */

    for( i=0; i<nread; i++ ){
        argstr[i] &= 0x7F;
    }

    /* tokenize the input */

    j = 0;

    for( i=0; i<nread; i++ ){

        /* look for start of token */

        if( start ){

 /* getpars.c:475: log_msg_vcm_warninging: subscript has type `char' */
        if( isgraph( (int)argstr[i] ) ){
            targv[j] = &(argstr[i]);
            start = !start;
            j++;

        }else{
            argstr[i] = 0;

        }

        /* terminate token */

/* getpars.c:487: log_msg_vcm_warninging: subscript has type `char' */
        }else if( !quote && isspace( (int)argstr[i] ) ){
        argstr[i] = 0;
        start = !start;

        }

        /* toggle quote semaphore */

        if( argstr[i] == '\'' || argstr[i] == '\"' ){
        quote = !quote;

        }

    }

    /* display all tokens */

    if( debug ){

        i=0;
        while( i < j && targv[i] != 0 ){
        if( strlen( targv[i] ) ){
            fprintf( stderr ,"%d -> %s\n" ,i ,targv[i] );
        }
        i++;

        }
    }

    /* discard non-parameter tokens */

    i=0;
    targc=0;
    while( i < j && targv[i] != 0 ){
        if( strchr( targv[i] ,'=' ) ){
        targv[targc] = targv[i];
        targc++;
        }
        i++;
    }

    /* Copy command line arguments */

    for (j = 1, pargstr = argstr + pflen + 1; j < xargc; j++) {
        strcpy(pargstr,xargv[j]);
        targv[targc++] = pargstr;
        pargstr += strlen(xargv[j]) + 1;
    }

    /* Allocate space for the pointer table */

    argtbl = (pointer_table*) malloc(targc*sizeof(pointer_table));

    /* Tabulate targv */

    tabulate(targc, targv);

    return;
}

/* Get name of parameter file */
static char *getpfname (void)
{
    int i;
    size_t pfnamelen;

    pfnamelen = strlen(PFNAME);
    for (i = xargc-1 ; i > 0 ; i--) {
        if(!strncmp(PFNAME, xargv[i], pfnamelen)
            && strlen(xargv[i]) != pfnamelen) {
            return xargv[i] + pfnamelen;
        }
    }
    return NULL;
}

void strchop(char *s, char *t)
{

    while ( (*s != ',') && (*s != '\0') ) 
    {
         *t++ = *s++;
    }
    *t='\0';
}


/* Install symbol table */
static void tabulate (size_t argc, char **argv)
{
    int i;
    char *eqptr;
    int debug=FALSE;

    for (i = 0, nargs = 0 ; i < argc; i++) {
        eqptr = strchr(argv[i], '=');
        if (eqptr) {
            argtbl[nargs].name = argv[i];
            argtbl[nargs].asciival = eqptr + 1;
            *eqptr = (char)0;

            /* Debugging dump */
            if( debug ){
                fprintf(stderr,
                "argtbl[%d]: name=%s asciival=%s\n",
                nargs,argtbl[nargs].name,argtbl[nargs].asciival);

            }
            nargs++;
        }
    }
    return;
}

/* Count characters in a string */
static int ccount (char c, char *s)
{
    int i, count;
    for (i = 0, count = 0; s[i] != 0; i++)
        if(s[i] == c) count++;
    return count;
}


/* estrtoh - convert string s to short integer {SHRT_MIN:SHRT_MAX} */
short estrtoh(char *s)
{
    long n = strtol(s, NULL, 10);
    
    if ( (n > SHRT_MAX) || (n < SHRT_MIN) || (errno == ERANGE) )
    {   
        fprintf(stderr, "%s: estrtoh: overflow", __FILE__);
        exit(1);
    }

    return (short) n;
}


/* estrtous - convert string s to unsigned short integer {0:USHRT_MAX} */
unsigned short estrtous(char *s)
{
    unsigned long n = strtoul(s, NULL, 10);

    if ( (n > USHRT_MAX) || (errno == ERANGE) )
    {   
        fprintf(stderr, "%s: estrtous: overflow", __FILE__);
        exit(1);
    }

    return (unsigned short) n;
}


/* estrtoi - convert string s to integer {INT_MIN:INT_MAX} */
int estrtoi(char *s)
{
    long n = strtol(s, NULL, 10);

    if ( (n > INT_MAX) || (n < INT_MIN) || (errno == ERANGE) )
    {   
        fprintf(stderr, "%s: estrtoi: overflow", __FILE__);
        exit(1);
    }

    return (int) n;
}


/* estrtoui - convert string s to unsigned integer {0:UINT_MAX} */
unsigned int estrtoui(char *s)
{
    unsigned long n = strtoul(s, NULL, 10);

    if ( (n > UINT_MAX) || (errno == ERANGE) )
    {   
        fprintf(stderr, "%s: estrtoui: overflow", __FILE__);
        exit(1);
    }

    return (unsigned int) n;
}


/* estrtol - convert string s to long integer {LONG_MIN:LONG_MAX} */
long estrtol(char *s)
{
    long n = strtol(s, NULL, 10);

    if (errno == ERANGE)
    {   
        fprintf(stderr, "%s: estrtol: overflow", __FILE__);
        exit(1);
    }

    return n;
}


unsigned long estrtoul(char *s)
{
    unsigned long n = strtoul(s, NULL, 10);

    if (errno == ERANGE)
    {   
        fprintf(stderr, "%s: estrtoul: overflow", __FILE__);
        exit(1);
    }
    return n;
}


/* estrtof - convert string s to float {-FLT_MAX:FLT_MAX} */
float estrtof(char *s)
{
    float x = strtod(s, NULL);

    if ( (x > FLT_MAX) || (x < -FLT_MAX) || (errno == ERANGE) )
    {   
        fprintf(stderr, "%s: estrtof: overflow", __FILE__);
        exit(1);
    }
    return (float) x;
}


/* estrtod - convert string s to double {-DBL_MAX:DBL_MAX} */
double estrtod(char *s)
{
    double x = strtod(s, NULL);

    /* errno == ERANGE suffices if compiler sets errno on overflow */
    if ( (errno == ERANGE) || (x > DBL_MAX) || (x < -DBL_MAX) )
    {   
        fprintf(stderr, "%s: estrtod: overflow", __FILE__);
        exit(1);
    }
    return x;
}


