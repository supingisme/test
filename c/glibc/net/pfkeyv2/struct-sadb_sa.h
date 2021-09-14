/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:16 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/**
 *	9.8.4 19.4 Creating a Static Security Association (SA)
 *	The most straightforward method of adding an SA is to send an SADB_ADD message with all parameters filled in, presumably manually specified. Although manual specification of keying material does not lead easily to key changes, which are crucial to avoid cryptanalysis attacks, it is quite easy to configure: Alice and Bob agree on a key and algorithms to use out-of-band, and proceed to use them. We show the steps needed to create and send an SADB_ADD message.
 *	The SADB_ADD message requires three extensions: SA, address and key. It can also optionally contain other extensions: lifetime, identity, and sensitivity. We describe the required extensions first. The SA extension is described by the sadb_sa structure, shown in Figure 19.6.
 *	Figure 19.6 SA Extension.
 */

struct sadb_sa {
	u_int16_t sadb_sa_len; /* length of extension / 8 */
	u_int16_t sadb_sa_exttype; /* SADB_EXT_SA */
	u_int32_t sadb_sa_spi; /* Security Parameters Index (SPI) */
	u_int8_t sadb_sa_replay; /* replay window size, or zero */
	u_int8_t sadb_sa_state; /* SA state, see Figure 19.7 */
	u_int8_t sadb_sa_auth; /* authentication algorithm, see Figure 19.8 */
	u_int8_t sadb_sa_encrypt; /* encryption algorithm, see Figure 19.8 */
	u_int32_t sadb_sa_flags; /* bitmask of flags */
};
