/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:52 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:52 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:09 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/* SUXMAX: $Revision: 1.15 $ ; $Date: 2011/11/12 00:45:18 $		*/

#include "su.h"
#include "segy.h"
#include "header.h"
#include <signal.h>

/*********************** self documentation *****************************/
char *sdoc[] = {
" 									",
" SUXMAX - X-windows graph of the MAX, min, or absolute max value on	",
"	each trace of a SEGY (SU) data set				",
" 									",
"   suxmax <stdin [optional parameters]					",
" 									",
" Optional parameters: 							",
" mode=max		max value					",
" 			=min min value					",
" 			=abs absolute max value				",
" 									",
" n2=tr.ntr or number of traces in the data set (ntr is an alias for n2)",
"									",
" d1=tr.d1 or tr.dt/10^6	sampling interval in the fast dimension	",
"   =.004 for seismic 		(if not set)				",
"   =1.0 for nonseismic		(if not set)				",
" 							        	",
" d2=tr.d2			sampling interval in the slow dimension	",
"   =1.0 			(if not set)				",
" 							        	",
" f1=tr.f1 or tr.delrt/10^3 or 0.0  first sample in the fast dimension	",
" 							        	",
" f2=tr.f2 or tr.tracr or tr.tracl  first sample in the slow dimension	",
"   =1.0 for seismic		    (if not set)			",
"   =d2 for nonseismic		    (if not set)			",
" 									",
" verbose=0              =1 to print some useful information		",
"									",
" tmpdir=	 	if non-empty, use the value as a directory path	",
"		 	prefix for storing temporary files; else if the	",
"	         	the CWP_TMPDIR environment variable is set use	",
"	         	its value for the path; else use tmpfile()	",
" 									",
" Note that for seismic time domain data, the \"fast dimension\" is	",
" time and the \"slow dimension\" is usually trace number or range.	",
" Also note that \"foreign\" data tapes may have something unexpected	",
" in the d2,f2 fields, use segyclean to clear these if you can afford	",
" the processing time or use d2= f2= to over-ride the header values if	",
" not.									",
" 									",
" See the sumax selfdoc for additional parameter.			",
" See the xgraph selfdoc for the remaining parameters.			",
" 									",
NULL};

/* Credits:
 *
 *	CWP: John Stockwell, based on Jack Cohen's SU JACKet 
 *
 * Notes:
 *	When the number of traces isn't known, we need to count
 *	the traces for xgraph.  You can make this value "known"
 *	either by getparring n2 or by having the ntr field set
 *	in the trace header.  A getparred value takes precedence
 *	over the value in the trace header.
 *
 *	When we do have to count the traces, we use the "tmpfile"
 *	routine because on many machines it is implemented
 *	as a memory area instead of a disk file.
 */
/**************** end self doc *******************************************/

static void closefiles(void);

/* Globals (so can trap signal) defining temporary disk files	*/
char tracefile[BUFSIZ];	/* filename for trace storage file	*/
char headerfile[BUFSIZ];/* filename for the file of headers	*/
FILE *tracefp;		/* fp for trace storage file		*/
FILE *headerfp;		/* fp for header storage file		*/

segy tr;

int
main(int argc, char **argv)
{
	char plotcmd[BUFSIZ];	/* build command for popen		*/
	FILE *plotfp;		/* fp for plot data			*/
	float d1;		/* time/depth sample rate 		*/
	float d2;		/* trace/dx sample rate 		*/
	float f1;		/* tmin/zmin				*/
	float f2;		/* tracemin/xmin			*/
	int nt;			/* number of samples on trace		*/
	int ntr;		/* number of traces			*/
	int verbose;		/* verbose flag				*/
	cwp_Bool seismic;	/* is this seismic data?		*/
	cwp_Bool have_ntr=cwp_false;/* is ntr known from header or user?	*/
	cwp_String mode;	/* sumax mode parameter			*/
	char *tmpdir;		/* directory path for tmp files		*/
	cwp_Bool istmpdir=cwp_false;/* true for user given path		*/

	char *cwproot;		/* value of CWPROOT environment variable*/
	char *bindir;		/* directory path for tmp files		*/

	/* Initialize */
	initargs(argc, argv);
	requestdoc(1);
	
	/* Get info from first trace */
	if (!gettr(&tr)) err("can't get first trace");
	seismic = ISSEISMIC(tr.trid); 
	nt = tr.ns;
	ntr = tr.ntr;
	if (ntr) have_ntr = cwp_true; 

	if (!getparint("verbose", &verbose))	verbose=0;
	if (!getparfloat("d1", &d1)) {
		if      (tr.d1)  d1 = tr.d1;
		else if (tr.dt)  d1 = ((double) tr.dt)/1000000.0;
		else {
			if (seismic) {
				d1 = 0.004;
				warn("tr.dt not set, assuming dt=0.004");
			} else { /* non-seismic data */
				d1 = 1.0;
				warn("tr.d1 not set, assuming d1=1.0");
			}
		}
	}

	if (!getparfloat("d2", &d2)) d2 = (tr.d2) ? tr.d2 : 1.0;

	if (!getparfloat("f1", &f1)) {
		if      (tr.f1)     f1 = tr.f1;
		else if (tr.delrt)  f1 = (float) tr.delrt/1000.0;
		else                f1 = 0.0;
	}

	if (!getparfloat("f2", &f2)) {
		if      (tr.f2)     f2 = tr.f2;
		else if (tr.tracr)  f2 = (float) tr.tracr;
		else if (tr.tracl)  f2 = (float) tr.tracl;
		else if (seismic)   f2 = 1.0;
		else 		    f2 = 0.0;
	}
	
	if (getparint("n2", &ntr) || getparint("ntr", &ntr)) have_ntr = cwp_true;
	if (!getparstring("mode", &mode)) mode = "max";

	/* Look for user-supplied tmpdir */
	if (!getparstring("tmpdir",&tmpdir) &&
	    !(tmpdir = getenv("CWP_TMPDIR"))) tmpdir="";
	if (!STREQ(tmpdir, "") && access(tmpdir, WRITE_OK))
		err("you can't write in %s (or it doesn't exist)", tmpdir);

	/* See if CWPBIN environment variable is not set */
	if (!(bindir = getenv("CWPBIN"))) { /* construct bindir from CWPROOT */

		bindir = (char *) emalloc(BUFSIZ);

		/* Get value of CWPROOT environment variable */
		if (!(cwproot = getenv("CWPROOT"))) cwproot ="" ;
		if (STREQ(cwproot, "")) {
			warn("CWPROOT environment variable is not set! ");
			err("Set CWPROOT in shell environment as per instructions in CWP/SU Installation README files");
		}
		/* then bindir = $CWPROOT/bin */
		sprintf(bindir, "%s/bin", cwproot);
	}
	strcat(bindir,"/");   /* put / at the end of bindir */


	/* Allocate trace buffer */
	if (!have_ntr) {
		/* Store traces and headers in tmpfile while getting a count */
		if (verbose) {
			warn(" n2 not getparred or header field ntr not set");
			warn(" ....    counting traces");
		}

		/* Store traces and headers in tmpfile while getting a count */
		if (STREQ(tmpdir,"")) {
			tracefp = etmpfile();
			headerfp = etmpfile();
			if (verbose) warn("using tmpfile() call");
		} else { /* user-supplied tmpdir */
			char directory[BUFSIZ];
			strcpy(directory, tmpdir);
			strcpy(tracefile, temporary_filename(directory));
			strcpy(headerfile, temporary_filename(directory));
			/* Trap signals so can remove temp files */
			signal(SIGINT,  (void (*) (int)) closefiles);
			signal(SIGQUIT, (void (*) (int)) closefiles);
			signal(SIGHUP,  (void (*) (int)) closefiles);
			signal(SIGTERM, (void (*) (int)) closefiles);
			tracefp = efopen(tracefile, "w+");
			headerfp = efopen(headerfile, "w+");
			istmpdir=cwp_true;		
			if (verbose)
			     warn("putting temporary files in %s", directory);
		}

		/* Loop over input data and read to temporary file */
		ntr = 0;
		do {
			   ++ntr;
			   efwrite(&tr, 1, HDRBYTES, headerfp);
			   efwrite(tr.data, FSIZE, nt, tracefp);
		   } while (gettr(&tr));

	}

	/* System call to xgraph */
	sprintf(plotcmd, "%ssumax output=binary mode=%s | %sxgraph n=%d", 
			 bindir, mode, bindir, ntr);
	for (--argc, ++argv; argc; --argc, ++argv) {
		if ( 
			strncmp(*argv, "output=", 7)  &&
			strncmp(*argv, "mode=", 5)  &&
			strncmp(*argv, "n=", 2) &&
			strncmp(*argv, "n2=", 3) &&/*xgraph honors n2,nplot*/
			strncmp(*argv, "nplot=", 6) ) { 

			strcat(plotcmd, " ");   /* put a space between args */
			strcat(plotcmd, "\"");  /* user quotes are stripped */
			strcat(plotcmd, *argv); /* add the arg */
			strcat(plotcmd, "\"");  /* user quotes are stripped */
		}
	}


	/* Open pipe; write data to plotcmd */
	plotfp = epopen(plotcmd, "w");
	
	if (!have_ntr) {
		rewind(headerfp);
		rewind(tracefp);
		{ register int itr;
		for (itr = 0; itr < ntr; ++itr) {
			efread(&tr, 1, HDRBYTES, headerfp);
			efread(tr.data, FSIZE, nt, tracefp);
			fputtr(plotfp, &tr);
		}
		}
	} else { /* pump out traces and let sumax and psimage do the work */
                do {
                        fputtr(plotfp,&tr);
                } while (gettr(&tr));
        }


	/* Clean up */
	epclose(plotfp);
	efclose(headerfp);
	if (istmpdir) eremove(headerfile);
	if (!have_ntr) {
		efclose(tracefp);
		if (istmpdir) eremove(tracefile);
	}

	return EXIT_SUCCESS;
}

/* for graceful interrupt termination */
static void closefiles(void)
{
	efclose(headerfp);
	efclose(tracefp);
	eremove(headerfile);
	eremove(tracefile);
	exit(EXIT_FAILURE);
}
