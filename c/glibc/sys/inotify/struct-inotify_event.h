/* Structure describing an inotify event.  */
struct inotify_event
{
  int wd;		/* Watch descriptor.  */
  uint32_t mask;	/* Watch mask.  */
  uint32_t cookie;	/* Cookie to synchronize two events.  */
  uint32_t len;		/* Length (including NULs) of name.  */
  char __flexarr name ;	/* Name.  */
};

