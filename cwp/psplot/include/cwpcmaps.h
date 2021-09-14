/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:48 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:49 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:07 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

#ifndef CWP_CMAPS_H
#define CWP_CMAPS_H

/* define hue, saturation, lightness values */

# define HSV_BLACK	{  0.0, 0.00, 0.00}
# define HSV_GRAY	{  0.0, 0.00, 0.50}
# define HSV_WHITE	{  0.0, 0.00, 1.00}

# define HSV_HUE1	{240.0, 1.00, 0.50}
# define HSV_HUE2	{120.0, 1.00, 0.50}
# define HSV_HUE3	{  0.0, 1.00, 0.50}

# define HSV_DRED	{  0.0, 1.00, 0.50}
# define HSV_BROWN	{ 30.0, 1.00, 0.30}
# define HSV_GREEN	{140.0, 1.00, 0.50}
# define HSV_BLUE	{240.0, 1.00, 0.70}

# define HSV_YELLOW	{ 70.0, 1.00, 0.50}

float c_hsv [][3][3]  =	{
	{ HSV_WHITE,  HSV_GRAY,   HSV_BLACK },
	{ HSV_HUE1,   HSV_HUE2,   HSV_HUE3  },
	{ HSV_HUE3,   HSV_HUE2,   HSV_HUE1  },
	{ HSV_BROWN,  HSV_GREEN,  HSV_BLUE  },
	{ HSV_DRED,  HSV_WHITE,  HSV_BLUE  },
	{ HSV_BLUE,  HSV_WHITE,  HSV_DRED  },
	{ HSV_WHITE,  HSV_DRED,  HSV_BLUE  },
	{ HSV_WHITE,  HSV_GREEN,  HSV_BLUE  },
	{ HSV_BLUE,  HSV_DRED,  HSV_WHITE  },
	{ HSV_BLUE,  HSV_GREEN,  HSV_WHITE  },
	{ HSV_BLUE,  HSV_WHITE,  HSV_GREEN  },
	{ HSV_YELLOW,  HSV_DRED,  HSV_BROWN  },
	{ HSV_BROWN,  HSV_DRED,  HSV_YELLOW  },
	{ HSV_DRED,  HSV_YELLOW,  HSV_BROWN  }
	};

/* define red, green, blue values */

# define RGB_BLACK	{0x00, 0x00, 0x00}
# define RGB_WHITE	{0xff, 0xff, 0xff}
# define RGB_GRAY	{0x80, 0x80, 0x80}

# define RGB_ORANGE	{0xff, 0x80, 0x00}

# define RGB_RED	{0xe0, 0x00, 0x50}
# define RGB_BLUE	{0x00, 0x40, 0xc0}
# define RGB_GREEN	{0x06, 0x5b, 0x3f}
# define RGB_BROWN	{0x72, 0x5b, 0x3f}
# define RGB_REDBROWN	{0xa0, 0x40, 0x00}

# define RGB_GRAY2	{0xb0, 0xb0, 0xb0}

# define RGB_LGRAY	{0xf0, 0xf0, 0xf0}
# define RGB_LBLUE	{0x55, 0x9c, 0xe0}
# define RGB_YELLOW	{0xd0, 0xb0, 0x20}

	float c_rgb [][3][3]  =	{
	{ RGB_BLACK,    RGB_GRAY,   RGB_WHITE  },

	{ RGB_RED,      RGB_LGRAY,  RGB_BLUE  },
	{ RGB_RED,      RGB_LGRAY,  RGB_GREEN },
	{ RGB_BROWN,    RGB_LGRAY,  RGB_BLUE  },
	{ RGB_BROWN,    RGB_LGRAY,  RGB_GREEN },
	{ RGB_REDBROWN, RGB_LGRAY,  RGB_BLUE  },
	{ RGB_REDBROWN, RGB_LGRAY,  RGB_GREEN },
	{ RGB_ORANGE,   RGB_LGRAY,  RGB_BLUE  },
	{ RGB_ORANGE,   RGB_LGRAY,  RGB_GREEN },
	{ RGB_BROWN,    RGB_GRAY2,  RGB_GREEN },
	{ RGB_BROWN,    RGB_GRAY2,  RGB_BLUE  },
	{ RGB_BROWN,    RGB_YELLOW, RGB_BLUE  }
	};


#endif
