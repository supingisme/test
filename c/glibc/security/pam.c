/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 18日 星期二 08:56:19 CST. */


#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <stdio.h>

/**
 *	[rongtao@localhost security]$ gcc pam.c -lpam -lpam_misc
 *	[rongtao@localhost security]$ ./a.out 
 *	Password: 
 *	Authentication OK.
 *	[rongtao@localhost security]$ 
 */

int main ()
{
	pam_handle_t* pamh;
	struct pam_conv pamc;
	/* Set up the PAM conversation. */
	pamc.conv = &misc_conv;
	pamc.appdata_ptr = NULL;
	/* Start a new authentication session. */
	pam_start ("su", getenv ("USER"), &pamc, &pamh);
	/* Authenticate the user. */
	if (pam_authenticate (pamh, 0) != PAM_SUCCESS)
		fprintf (stderr, "Authentication failed!\n");
	else
		fprintf (stderr, "Authentication OK.\n");
	/* All done. */
	pam_end (pamh, 0);
	return 0;
}
