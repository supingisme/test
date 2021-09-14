struct __sysctl_args {
   int    *name;    /* integer vector describing variable */
   int     nlen;    /* length of this vector */
   void   *oldval;  /* 0 or address where to store old value */
   size_t *oldlenp; /* available room for old value,
                       overwritten by actual size of old value */
   void   *newval;  /* 0 or address of new value */
   size_t  newlen;  /* size of new value */
};

