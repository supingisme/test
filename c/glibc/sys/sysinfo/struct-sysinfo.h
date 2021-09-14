#ifdef __rtoax_debug

//Until Linux 2.3.16, sysinfo() used to return information in the following structure:
struct sysinfo {
   long uptime;             /* Seconds since boot */
   unsigned long loads[3];  /* 1, 5, and 15 minute load averages */
   unsigned long totalram;  /* Total usable main memory size */
   unsigned long freeram;   /* Available memory size */
   unsigned long sharedram; /* Amount of shared memory */
   unsigned long bufferram; /* Memory used by buffers */
   unsigned long totalswap; /* Total swap space size */
   unsigned long freeswap;  /* swap space still available */
   unsigned short procs;    /* Number of current processes */
   char _f[22];             /* Pads structure to 64 bytes */
};

//and the sizes were given in bytes.
//
//Since Linux 2.3.23 (i386), 2.3.48 (all architectures) the structure is:

struct sysinfo {
   long uptime;             /* Seconds since boot */
   unsigned long loads[3];  /* 1, 5, and 15 minute load averages */
   unsigned long totalram;  /* Total usable main memory size */
   unsigned long freeram;   /* Available memory size */
   unsigned long sharedram; /* Amount of shared memory */
   unsigned long bufferram; /* Memory used by buffers */
   unsigned long totalswap; /* Total swap space size */
   unsigned long freeswap;  /* swap space still available */
   unsigned short procs;    /* Number of current processes */
   unsigned long totalhigh; /* Total high memory size */
   unsigned long freehigh;  /* Available high memory size */
   unsigned int mem_unit;   /* Memory unit size in bytes */
   char _f[20-2*sizeof(long)-sizeof(int)]; /* Padding to 64 bytes */
};

#endif //__rtoax_debug