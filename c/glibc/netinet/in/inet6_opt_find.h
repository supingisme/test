/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:18 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:27 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 08:57:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:57:39 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:52:32 CST. */
#include <netinet/in.h>

int inet6_opt_init(void *extbuf, socklen_t extlen) ;
//Returns: number of bytes required to hold empty extension header, -1 on error
int inet6_opt_append(void *extbuf, socklen_t extlen, int offset, uint8_t type, 
						socklen_t len, uint_t align, void **databufp) ;
//Returns: updated length of overall extension header after adding option, -1 on error
int inet6_opt_finish(void *extbuf, socklen_t extlen, int offset) ;
//Returns: updated length of finished extension header, –1 on error
int inet6_opt_set_val(void *databuf, int offset, const void *val, socklen_t vallen) ;
//Returns: new offset inside databuf

int inet6_opt_next(const void *extbuf, socklen_t extlen, int offset, 
					uint8_t *typep, socklen_t *lenp, void **databufp) ;
//Returns: offset of next option, -1 on end of options or error
int inet6_opt_find(const void *extbuf, socklen_t extlen, int offset, 
					uint8_t type, socklen_t *lenp, void **databufp) ;
//Returns: offset of next option, -1 on end of options or error
int inet6_opt_get_val(const void *databuf, int offset, void *val, socklen_t vallen) ;
//Returns: new offset inside databuf


//inet6_opt_init returns the number of bytes required to hold an empty extension header. If the extbuf argument is not NULL, it initializes the extension header. It failsand returns -1 if the extbuf argument is supplied but the extlen argument is not a multiple of 8. (All IPv6 hop-by-hop and destination options headers must be multiples of 8 bytes.)
//inet6_opt_append returns the updated total length of the extension header after appending the specified option. If the extbuf argument is not NULL, it also initializes the option and inserts any necessary padding. It fails and returns -1 if the new option does not fit in the supplied buffer. The offset argument is the current running total length, and must be the return value from a previous call to inet6_opt_init or inet6_opt_append. The type and len arguments are the type and length of the option, and are copied directly into the option header. The align argument specifies the alignment requirement, that is, x from the function xn + y. The value of y is derived from align and len, so it does not need to be explicitly specified. The databufp argument is the address to a pointer that will be filled in with the location of the option value; the caller can then copy the option value into this location using the inet6_opt_set_val function or any other method.
//inet6_opt_finish is called to complete an extension header, adding any needed padding to make the overall header a multiple of 8 bytes. As before, if the extbuf argument is non-NULL, the padding is actually inserted into the buffer; otherwise, the function simply computes the updated length. As with inet6_opt_append, the offset argument is the current running total length, the return value from a previous inet6_opt_init or inet6_opt_append. inet6_opt_finish returns the total length of the completed header, or -1 if the required padding will not fit in the supplied buffer.
//inet6_opt_set_val copies an option value into the data buffer returned by inet6_opt_append. The databuf argument is the pointer returned from inet6_opt_append. offset is a running length within this option; it must be initialized to 0 for each option and then will be the return value from the previous inet6_opt_set_val as the option is built up. The val and vallen arguments specify the value to copy into the option value buffer.
//The expected use of these functions is to make two passes through the list of options you intend to insert: the first to calculate the desired length, and the second to actually build the option into an appropriately sized buffer. During the first pass, we call inet6_opt_init, inet6_opt_append once for each option we will append, and inet6_opt_finish, passing NULL and 0 for the extbuf and extlen arguments, respectively. We then dynamically allocate the option buffer using the size returned by inet6_opt_finish, and we will pass this buffer as the extbuf argument during the second pass. During the second pass, we call inet6_opt_init and inet6_opt_append, either copying the data manually or using inet6_opt_set_val for each option value. Finally, we call inet6_opt_finish. Alternately, we can pre-allocate a buffer that should be large enough for our desired options and skip the
//first pass; however, this is vulnerable to failure if a change in the desired options would over-run the pre-allocated buffer.
//inet6_opt_next processes the next option in a buffer. extbuf and extlen specify the buffer containing the header. As with inet6_opt_append, offset is a running offset into the buffer. It is 0 for the first call to inet6_opt_next, and then it is the return value from the previous call for future calls. typep, lenp, and databufp return the type, length, and value of the option, respectively. inet6_opt_next returns -1 if the header is malformed or if it has reached the end of the buffer.
//inet6_opt_find is similar to the previous function, but it lets the caller specify the option type to search for (the type argument) instead of always returning the next option.
//inet6_opt_get_val is used to extract values from an option, using the databuf pointer returned by a previous inet6_opt_next or inet6_opt_find call. As with inet6_opt_set_val, the offset argument must start at 0 for each option, then must be the return value of a previous call to inet6_opt_get_val.
