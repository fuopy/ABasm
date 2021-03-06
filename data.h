#ifndef _DATA_H
#define _DATA_H

// 53 x 6
const unsigned char gfx_iconmenu[] PROGMEM = {
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x03, 0x35, 0x03,
	0x3f, 0x01, 0x17, 0x0f, 0x27, 0x1b, 0x27, 0x23,
	0x1f, 0x23, 0x3b, 0x01, 0x3b, 0x3f, 0x3f, 0x03,
	0x35, 0x03, 0x3f, 0x01, 0x17, 0x2f, 0x3f, 0x03,
	0x35, 0x03, 0x3f, 0x13, 0x13, 0x0b, 0x3f, 0x07,
	0x3b, 0x07, 0x3b, 0x07, 0x3f, 0x1f, 0x3f, 0x1f,
	0x3f, 0x1f, 0x3f, 0x3f, 0x3f,
};

// 61 x 27
/*
const unsigned char gfx_iconmenu[] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xf5, 0xc3,
	0xff, 0xc1, 0xd7, 0xcf, 0xe7, 0xdb, 0xe7, 0xe3,
	0xdf, 0xe3, 0xfb, 0xc1, 0xfb, 0xff, 0xff, 0xc3,
	0xf5, 0xc1, 0xff, 0xc1, 0xd5, 0xeb, 0xff, 0xc3,
	0xf5, 0xc3, 0xff, 0xd3, 0xd3, 0xcb, 0xff, 0xc7,
	0xfb, 0xc7, 0xfb, 0xc7, 0xff, 0xdf, 0xff, 0xdf,
	0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xfb,
	0xff, 0xfb, 0x7f, 0x7b, 0x7f, 0x7b, 0x7f, 0xfb,
	0xff, 0xfb, 0x7f, 0x7b, 0xff, 0xfb, 0xff, 0xfb,
	0xff, 0x7b, 0xff, 0xfb, 0xff, 0xfb, 0xff, 0xfb,
	0xff, 0xfb, 0xff, 0x7b, 0xff, 0xfb, 0xff, 0xfb,
	0xff, 0xfb, 0x7f, 0xfb, 0xff, 0xfb, 0xff, 0xfb,
	0xff, 0xfb, 0xff, 0xfb, 0xff, 0xfb, 0xff, 0xfb,
	0xff, 0xfb, 0xff, 0xfb, 0xff, 0xfb, 0xff, 0xfb,
	0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0x70,
	0xb4, 0x72, 0x74, 0x70, 0xff, 0xff, 0x78, 0xb7,
	0xb7, 0xff, 0xf9, 0x76, 0xf0, 0xff, 0x70, 0x7f,
	0xf9, 0xf6, 0x76, 0x3f, 0x78, 0xf7, 0x70, 0xff,
	0x70, 0xff, 0xf9, 0x76, 0xf0, 0xff, 0x3e, 0xf0,
	0xfe, 0xff, 0xf9, 0x36, 0xb9, 0x7f, 0xf0, 0xfd,
	0x7e, 0x7f, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff,
	0x7f, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x03, 0x06, 0x03, 0x07,
	0x03, 0x07, 0x07, 0x04, 0x03, 0x03, 0x07, 0x04,
	0x03, 0x04, 0x07, 0x00, 0x07, 0x00, 0x07, 0x07,
	0x00, 0x07, 0x07, 0x00, 0x06, 0x07, 0x07, 0x04,
	0x03, 0x04, 0x07, 0x00, 0x07, 0x07, 0x07, 0x07,
	0x00, 0x06, 0x06, 0x07, 0x04, 0x03, 0x00, 0x07,
	0x00, 0x07, 0x00, 0x07, 0x04, 0x01, 0x02, 0x07,
	0x00, 0x07, 0x07, 0x07,
};
*/

// 68 x 27
const unsigned char gfx_editmenu[] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xdd, 0xc1, 0xdd,
	0xc3, 0xfb, 0xc7, 0xff, 0xd3, 0xd3, 0xcb, 0xff,
	0xe7, 0xcb, 0xd7, 0xff, 0xc3, 0xf7, 0xfb, 0xfb,
	0xc1, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x6e, 0x60, 0xee, 0xe1, 0xfd, 0xe3, 0xff,
	0xe9, 0x69, 0xe5, 0xff, 0xf3, 0xe5, 0xeb, 0xff,
	0x61, 0xfb, 0xfd, 0xfd, 0xe0, 0xfd, 0xff, 0xfb,
	0xf1, 0xfb, 0xff, 0xe0, 0xfd, 0xfb, 0xfd, 0xe0,
	0xf3, 0xed, 0xf3, 0xf1, 0xef, 0xf1, 0xf3, 0xe5,
	0xeb, 0xff, 0xef, 0xf2, 0xff, 0xf1, 0xef, 0xf1,
	0xff, 0xe1, 0xfd, 0xe3, 0xfd, 0xe1, 0xff, 0xe1,
	0xf5, 0xf9, 0xff, 0xe9, 0xe9, 0xe5, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0xb7, 0x78,
	0xff, 0xf9, 0x72, 0xf5, 0xff, 0x30, 0xff, 0xf9,
	0x72, 0xf5, 0xff, 0x7e, 0x30, 0x7e, 0xff, 0xf9,
	0x72, 0xf5, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x3f,
	0x7f, 0xff, 0x7f, 0x3f, 0xff, 0x7f, 0xff, 0x7f,
	0xff, 0x7f, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xbf,
	0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0x7f, 0xff,
	0x7f, 0x7f, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
	0x7f, 0xff, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x00, 0x03, 0x04, 0x07, 0x04, 0x01, 0x02,
	0x07, 0x00, 0x07, 0x04, 0x01, 0x02, 0x07, 0x07,
	0x00, 0x07, 0x07, 0x04, 0x01, 0x02, 0x07, 0x06,
	0x04, 0x06, 0x07, 0x00, 0x07, 0x06, 0x07, 0x00,
	0x04, 0x03, 0x04, 0x04, 0x03, 0x04, 0x04, 0x01,
	0x02, 0x07, 0x03, 0x04, 0x07, 0x04, 0x03, 0x04,
	0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00,
	0x05, 0x06, 0x02, 0x02, 0x01, 0x07, 0x07, 0x07,
};

// 62 x 46
const unsigned char gfx_aboutdialog[] PROGMEM = {
	0x00, 0xfe, 0x02, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa,
	0xfa, 0x7a, 0x1a, 0xda, 0x1a, 0x7a, 0xba, 0x5a,
	0xba, 0xfa, 0xfa, 0xfa, 0x3a, 0x1a, 0x9a, 0x1a,
	0x3a, 0xfa, 0x1a, 0x1a, 0x7a, 0x7a, 0xfa, 0xfa,
	0x1a, 0xda, 0xda, 0xda, 0x9a, 0x5a, 0xda, 0xda,
	0x5a, 0x5a, 0x1a, 0x5a, 0xda, 0xda, 0xda, 0xba,
	0xba, 0x9a, 0xda, 0xda, 0xba, 0x7a, 0xfa, 0xfa,
	0xfa, 0xfa, 0xfa, 0x02, 0xfe, 0x00, 0x00, 0xff,
	0x00, 0xff, 0xff, 0xe3, 0xeb, 0x49, 0xbe, 0x6f,
	0x59, 0xdf, 0x5f, 0x79, 0xbe, 0xc9, 0xeb, 0xe3,
	0xff, 0xff, 0x10, 0xd0, 0x3c, 0xf0, 0x70, 0xbf,
	0x70, 0xf0, 0x72, 0xf0, 0x78, 0xff, 0x70, 0xb7,
	0x77, 0xf2, 0x1b, 0xfb, 0x76, 0xb5, 0x71, 0xf5,
	0x35, 0xb7, 0x76, 0xf5, 0x73, 0xb7, 0x77, 0xf5,
	0x33, 0x79, 0xb7, 0xf7, 0xf6, 0xf5, 0xf3, 0xf7,
	0xff, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0xff,
	0xff, 0xff, 0xfe, 0xfd, 0xfe, 0xff, 0xfc, 0xfd,
	0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x04, 0xd5, 0xee, 0xff, 0x1e, 0xdc, 0xfd, 0x9f,
	0x2e, 0x5d, 0xfe, 0x9f, 0x7e, 0x9c, 0xfd, 0x17,
	0xfc, 0x9f, 0x2e, 0x5d, 0xfe, 0x9f, 0x78, 0xbd,
	0x7e, 0x9f, 0xfe, 0xfc, 0xfd, 0x77, 0x04, 0x7f,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
	0xff, 0x00, 0x00, 0xff, 0x00, 0xff, 0xfb, 0xfb,
	0xfb, 0x3b, 0xdb, 0x2b, 0xab, 0xab, 0xdb, 0x3b,
	0xfb, 0xfb, 0xfb, 0xdb, 0xeb, 0x1b, 0xfb, 0x1b,
	0xeb, 0x1b, 0xfb, 0xdb, 0x0b, 0xfb, 0xfb, 0x1b,
	0x6b, 0xdb, 0xfb, 0xfb, 0xfb, 0xfb, 0x1b, 0x6b,
	0xdb, 0xfb, 0x1b, 0xfb, 0x1b, 0xfb, 0x3b, 0xdb,
	0x3b, 0xfb, 0x1b, 0xdb, 0x3b, 0xfb, 0x1b, 0xfb,
	0x1b, 0xfb, 0xfb, 0xfb, 0xff, 0x00, 0xff, 0x00,
	0x00, 0xff, 0x00, 0xff, 0x5f, 0x5f, 0x1f, 0xfe,
	0x1d, 0xda, 0x1a, 0xfa, 0xbd, 0xfe, 0xbf, 0x1f,
	0xff, 0xf9, 0x1a, 0x7b, 0x1f, 0xfc, 0xfb, 0xfc,
	0xff, 0x5b, 0x58, 0x1b, 0xff, 0x1c, 0xdb, 0x1c,
	0xff, 0xbf, 0x1f, 0xff, 0xf8, 0x1f, 0x5f, 0x5f,
	0xfc, 0xfb, 0x1c, 0xdf, 0x1c, 0xfb, 0x1c, 0x5f,
	0x58, 0xfe, 0xff, 0x5f, 0x5d, 0x1a, 0xfc, 0x5f,
	0x5f, 0x1f, 0xff, 0x00, 0xff, 0x00, 0x00, 0x1f,
	0x10, 0x17, 0x14, 0x15, 0x15, 0x17, 0x14, 0x15,
	0x14, 0x17, 0x16, 0x17, 0x15, 0x14, 0x15, 0x17,
	0x17, 0x17, 0x14, 0x17, 0x17, 0x17, 0x17, 0x14,
	0x15, 0x15, 0x17, 0x14, 0x15, 0x14, 0x17, 0x15,
	0x14, 0x15, 0x17, 0x14, 0x15, 0x14, 0x17, 0x17,
	0x14, 0x15, 0x14, 0x17, 0x14, 0x15, 0x14, 0x17,
	0x17, 0x14, 0x15, 0x15, 0x17, 0x15, 0x15, 0x14,
	0x17, 0x10, 0x1f, 0x00,
};

// 65 x 27
const unsigned char gfx_runmenu[] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xd5, 0xed,
	0xff, 0xe7, 0xdb, 0xc3, 0xff, 0xe3, 0xdf, 0xe3,
	0xff, 0xe7, 0xcb, 0xd7, 0xff, 0xff, 0xff, 0xf9,
	0xff, 0xc3, 0xfb, 0xc7, 0xff, 0xf9, 0xff, 0xff,
	0xff, 0xc1, 0xf5, 0xcb, 0xff, 0xe3, 0xdf, 0xe3,
	0xff, 0xc3, 0xfb, 0xc7, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x60, 0x7a,
	0xe5, 0xff, 0xf1, 0xef, 0xf1, 0xff, 0xe1, 0xfd,
	0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
	0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30,
	0xbd, 0x72, 0xf8, 0xf7, 0x78, 0xf0, 0xfe, 0x71,
	0x7f, 0x7f, 0xf0, 0x73, 0xf0, 0x7b, 0xfd, 0x7e,
	0x79, 0x76, 0xf9, 0xff, 0x70, 0xf5, 0xfa, 0xf1,
	0xfb, 0xfd, 0xf9, 0xf2, 0xf5, 0xff, 0xf9, 0xf6,
	0xf0, 0xff, 0xf0, 0xfd, 0xf2, 0xff, 0xf0, 0xfa,
	0xf9, 0xf9, 0xf6, 0xf9, 0xff, 0xf1, 0xf0, 0xfe,
	0xf1, 0xfe, 0xf0, 0xfe, 0xf4, 0xf4, 0xf2, 0xff,
	0xff, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x00, 0x06, 0x01, 0x07, 0x04, 0x01, 0x02, 0x07,
	0x02, 0x02, 0x01, 0x07, 0x00, 0x03, 0x04, 0x07,
	0x00, 0x06, 0x00, 0x07, 0x04, 0x01, 0x02, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07,
};


// 39 x 48
const unsigned char gfx_filemenu[] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xfd, 0xc3,
	0xff, 0xe7, 0xcb, 0xd7, 0xff, 0xc7, 0xcf, 0xc7,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x71, 0x6e, 0xf1, 0xff,
	0xe1, 0xf5, 0xf3, 0xff, 0xf3, 0xe5, 0xeb, 0xff,
	0xe1, 0xfd, 0xe3, 0xff, 0x6f, 0xff, 0xef, 0xff,
	0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xf0, 0xfd, 0xf2, 0xff, 0xf9,
	0xf2, 0xf5, 0xff, 0xf9, 0xf6, 0xf6, 0xff, 0xf9,
	0xf2, 0xf5, 0xff, 0xf1, 0xff, 0xf9, 0xf7, 0xf9,
	0xff, 0xf9, 0xf2, 0xf5, 0xff, 0xf7, 0xff, 0xf7,
	0xff, 0xf7, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xfe,
	0xff, 0xfe, 0xbf, 0x5e, 0xdf, 0xfe, 0x7f, 0x7e,
	0x7f, 0xfe, 0x7f, 0xfe, 0x7f, 0xfe, 0x7f, 0xbe,
	0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe,
	0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe,
	0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xdd, 0xad, 0x6e, 0xff, 0x3e, 0xbd, 0x3c,
	0xff, 0x3e, 0xfd, 0x3e, 0xff, 0x3e, 0x5c, 0xbd,
	0xff, 0x1f, 0xaf, 0x1f, 0xff, 0x9f, 0x5f, 0x5f,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x6e, 0x56, 0xb7, 0xff, 0x9f, 0x2e, 0x5e, 0xff,
	0x1f, 0xde, 0x3f, 0xff, 0x9f, 0x5e, 0x06, 0xff,
	0x7e, 0xff, 0x7e, 0xff, 0x7e, 0xfe, 0xfe, 0xff,
	0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff,
	0xff, 0xff,
};

// 128 x 8

const unsigned char gfx_menubar[] PROGMEM = {
	0xfc, 0xfe, 0xff, 0xff, 0xff, 0xd7, 0xe3, 0xc9,
	0xe3, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xc1, 0xd5, 0xdd, 0xff, 0xcf, 0xd7, 0xc1,
	0xff, 0xc5, 0xff, 0xfb, 0xc1, 0xfb, 0xff, 0xff,
	0xff, 0xff, 0xc1, 0xf5, 0xc9, 0xff, 0xe3, 0xdf,
	0xc3, 0xff, 0xc3, 0xfb, 0xc7, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc,
};

/*
const unsigned char gfx_menubar[] PROGMEM = {
	0xfc, 0xfe, 0xff, 0xff, 0xff, 0xd7, 0xe3, 0xc9,
	0xe3, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xc1, 0xf5, 0xfd, 0xff, 0xc5, 0xff, 0xc1,
	0xff, 0xe7, 0xcb, 0xd7, 0xff, 0xff, 0xff, 0xff,
	0xc1, 0xd5, 0xdd, 0xff, 0xcf, 0xd7, 0xc1, 0xff,
	0xc5, 0xff, 0xfb, 0xc1, 0xfb, 0xff, 0xff, 0xff,
	0xff, 0xc1, 0xf5, 0xc9, 0xff, 0xe3, 0xdf, 0xc3,
	0xff, 0xc3, 0xfb, 0xc7, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc,
};
*/

// 96 x 48
const unsigned char gfx_rundialog[] PROGMEM = {
	0xff, 0x01, 0xfd, 0xfd, 0xfd, 0x1d, 0xdd, 0xdd,
	0xdd, 0xdd, 0x1d, 0x1d, 0x1d, 0x9d, 0x9d, 0x1d,
	0x1d, 0x1d, 0x1d, 0x1d, 0xfd, 0xfd, 0xfd, 0xfd,
	0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0x7d, 0xbd, 0xbd,
	0xbd, 0xfd, 0xfd, 0x7d, 0x7d, 0x7d, 0xfd, 0x7d,
	0xfd, 0xfd, 0x7d, 0xfd, 0xfd, 0x7d, 0x7d, 0xfd,
	0xfd, 0xfd, 0xfd, 0xfd, 0x7d, 0x7d, 0xfd, 0xfd,
	0xfd, 0xfd, 0xfd, 0x3d, 0xfd, 0xfd, 0xbd, 0xfd,
	0xfd, 0x3d, 0xfd, 0xfd, 0xfd, 0x7d, 0x7d, 0x7d,
	0xfd, 0xfd, 0xfd, 0x7d, 0x7d, 0x7d, 0xfd, 0x7d,
	0xfd, 0x7d, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0x3d,
	0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0x01, 0xff,
	0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xfc,
	0xdf, 0x1f, 0x20, 0x5e, 0x41, 0x22, 0x20, 0x11,
	0x0e, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf6, 0xf6,
	0xf9, 0xff, 0xf8, 0xf7, 0xfb, 0xf0, 0xff, 0xf8,
	0xf7, 0xfb, 0xfc, 0xff, 0xf8, 0xf5, 0xf5, 0xf6,
	0xff, 0xff, 0xff, 0xf8, 0xf5, 0xf5, 0xf6, 0xff,
	0xf9, 0xf6, 0xf6, 0xf8, 0xf7, 0xff, 0xf0, 0xff,
	0xfe, 0xf0, 0xfe, 0xff, 0xf6, 0xf5, 0xf5, 0xfb,
	0xff, 0xff, 0xf8, 0xf7, 0xfb, 0xf0, 0xff, 0xf0,
	0xfe, 0xff, 0xf0, 0xff, 0xf9, 0x76, 0x76, 0x78,
	0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff,
	0xff, 0x00, 0xff, 0xff, 0xff, 0xf0, 0xf7, 0xf7,
	0xf5, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
	0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xfd, 0xfe,
	0xfe, 0xff, 0xf0, 0xef, 0xef, 0xf0, 0xef, 0xff,
	0xe0, 0xfd, 0xfe, 0xe1, 0xff, 0xff, 0xff, 0x80,
	0xee, 0xee, 0xf1, 0xff, 0xe0, 0xfd, 0xfe, 0xfe,
	0xff, 0xf1, 0xee, 0xee, 0xf1, 0xff, 0xb1, 0xae,
	0xae, 0xc1, 0xff, 0xe0, 0xfd, 0xfe, 0xff, 0xf1,
	0xee, 0xf6, 0xe0, 0xff, 0xe0, 0xfd, 0xfe, 0xe1,
	0xfd, 0xfe, 0xe1, 0xff, 0xfe, 0xff, 0xe9, 0xfd,
	0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff,
	0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
	0x7f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
	0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
	0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x7f,
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x9f, 0x9f,
	0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f,
	0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f,
	0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x9f, 0x9f,
	0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff,
	0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc1, 0x3e,
	0x7f, 0xe3, 0xdd, 0xdd, 0xff, 0xe7, 0xd7, 0xc7,
	0xff, 0xc7, 0xf7, 0xcf, 0xff, 0xef, 0xd7, 0xd7,
	0xff, 0xe7, 0xcb, 0xd7, 0xff, 0xc1, 0xff, 0x7f,
	0x3e, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xc1, 0x00, 0x3e, 0xc1, 0xbe,
	0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x63, 0x5d,
	0x63, 0x7f, 0x41, 0x77, 0x49, 0x7f, 0x7f, 0x7f,
	0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xbe, 0xc1,
	0x3e, 0x00, 0xc1, 0xff, 0xff, 0xff, 0x00, 0xff,
	0xff, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
	0xbf, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe,
	0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe,
	0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbf,
	0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
	0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
	0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
	0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbe, 0xbc, 0xbc,
	0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9,
	0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9,
	0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xbc, 0xbc,
	0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xff,
};

//28 x 11
const unsigned char gfx_invertbutton[] PROGMEM = {
	0xf8, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xfe, 0xfe, 0xf8, 0x00, 0x03, 0x03, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x00,
};


// from '0' to 'Z'
// 3x5
const unsigned char gfx_font[] PROGMEM = {
	0x1e, 0x11, 0x0f, 0x12, 0x1f, 0x10, 0x12, 0x19,
	0x17, 0x11, 0x15, 0x1b, 0x06, 0x04, 0x1f, 0x17,
	0x13, 0x0d, 0x0e, 0x15, 0x1d, 0x19, 0x05, 0x03,
	0x1a, 0x15, 0x0b, 0x12, 0x15, 0x0e, 0x00, 0x0a,
	0x00, 0x00, 0x10, 0x00, 0x00, 0x17, 0x00, 0x18,
	0x04, 0x03, 0x09, 0x04, 0x12, 0x01, 0x15, 0x07,
	0x00, 0x04, 0x00, 0x1e, 0x05, 0x1e, 0x1f, 0x15,
	0x0a, 0x0e, 0x11, 0x11, 0x1f, 0x11, 0x0e, 0x1f,
	0x15, 0x11, 0x1f, 0x05, 0x01, 0x0e, 0x11, 0x1d,
	0x1f, 0x04, 0x1f, 0x11, 0x1f, 0x11, 0x11, 0x0f,
	0x01, 0x1f, 0x04, 0x1b, 0x1f, 0x10, 0x10, 0x1f,
	0x07, 0x1f, 0x1f, 0x01, 0x1e, 0x0e, 0x11, 0x0e,
	0x1f, 0x05, 0x06, 0x0f, 0x09, 0x17, 0x1f, 0x05,
	0x1b, 0x16, 0x15, 0x0d, 0x01, 0x1f, 0x01, 0x1f,
	0x10, 0x0f, 0x07, 0x18, 0x07, 0x1f, 0x18, 0x1f,
	0x1b, 0x04, 0x1b, 0x03, 0x1c, 0x03, 0x19, 0x15,
	0x13,
};


// 8 of 'em
// 8x8
const unsigned char gfx_registers[] PROGMEM = {
	0x1c, 0x08, 0x04, 0x00, 0x1e, 0x11, 0x0f, 0x00,
	0x1c, 0x08, 0x04, 0x00, 0x12, 0x1f, 0x10, 0x00,
	0x1c, 0x08, 0x04, 0x00, 0x12, 0x19, 0x16, 0x00,
	0x1c, 0x08, 0x04, 0x00, 0x11, 0x15, 0x1f, 0x00,
	0x1c, 0x08, 0x04, 0x00, 0x07, 0x04, 0x1f, 0x00,
	0x1c, 0x08, 0x04, 0x00, 0x17, 0x13, 0x0d, 0x00,
	0x1c, 0x08, 0x04, 0x00, 0x0e, 0x15, 0x09, 0x00,
	0x1c, 0x08, 0x04, 0x00, 0x19, 0x05, 0x03, 0x00,
};

// 8 of 'em
// 8x8
const unsigned char gfx_buttons[] PROGMEM = {
	0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00,
	0x00, 0x4e, 0x1f, 0x5f, 0x1f, 0x4e, 0x00, 0x00,
	0x00, 0x4e, 0x11, 0x51, 0x11, 0x4e, 0x00, 0x00,
	0x00, 0x44, 0x08, 0x5f, 0x08, 0x44, 0x00, 0x00,
	0x00, 0x44, 0x0e, 0x55, 0x04, 0x44, 0x00, 0x00,
	0x00, 0x44, 0x04, 0x55, 0x0e, 0x44, 0x00, 0x00,
	0x00, 0x44, 0x02, 0x5f, 0x02, 0x44, 0x00, 0x00,
	0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa,
};


// 32 of 'em
// 38 x 8
const unsigned char gfx_opcodes[] PROGMEM = {
	0x1f, 0x01, 0x1e, 0x00, 0x0c, 0x12, 0x0c, 0x00,
	0x0e, 0x11, 0x0e, 0x00, 0x1e, 0x0a, 0x0c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x05,
	0x01, 0x1a, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x16,
	0x15, 0x0d, 0x00, 0x1c, 0x14, 0x00, 0x1c, 0x08,
	0x04, 0x00, 0x0c, 0x1a, 0x14, 0x00, 0x0c, 0x1a,
	0x14, 0x00, 0x1c, 0x04, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1f, 0x11, 0x0e, 0x00,
	0x1c, 0x08, 0x04, 0x00, 0x0c, 0x14, 0x1c, 0x00,
	0x1c, 0x18, 0x1c, 0x00, 0x1f, 0x05, 0x06, 0x00,
	0x1a, 0x00, 0x14, 0x08, 0x14, 0x00, 0x0c, 0x1a,
	0x14, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0e, 0x11, 0x1d, 0x00, 0x0c, 0x1a,
	0x14, 0x00, 0x02, 0x1f, 0x02, 0x00, 0x1f, 0x05,
	0x06, 0x00, 0x1a, 0x00, 0x14, 0x08, 0x14, 0x00,
	0x0c, 0x1a, 0x14, 0x00, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x1f, 0x05, 0x06, 0x00, 0x1f, 0x00, 0x0c, 0x14,
	0x1c, 0x00, 0x12, 0x14, 0x0e, 0x00, 0x01, 0x1f,
	0x01, 0x0c, 0x12, 0x0c, 0x00, 0x1e, 0x02, 0x1c,
	0x00, 0x0c, 0x1a, 0x14, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x18,
	0x1f, 0x00, 0x0c, 0x14, 0x1c, 0x00, 0x1d, 0x02,
	0x1f, 0x02, 0x00, 0x1f, 0x05, 0x19, 0x14, 0x08,
	0x1e, 0x04, 0x02, 0x00, 0x1f, 0x05, 0x1d, 0x08,
	0x04, 0x0c, 0x14, 0x1c, 0x00, 0x1c, 0x0c, 0x1c,
	0x00, 0x0c, 0x1a, 0x14, 0x16, 0x15, 0x0d, 0x00,
	0x1f, 0x04, 0x1a, 0x00, 0x1a, 0x00, 0x1e, 0x0a,
	0x0c, 0x00, 0x11, 0x1f, 0x11, 0x04, 0x1e, 0x05,
	0x00, 0x1f, 0x11, 0x0e, 0x00, 0x0c, 0x12, 0x0c,
	0x00, 0x0e, 0x10, 0x0c, 0x10, 0x0e, 0x00, 0x1e,
	0x02, 0x1c, 0x16, 0x15, 0x0d, 0x00, 0x1f, 0x04,
	0x1a, 0x00, 0x1a, 0x00, 0x1e, 0x0a, 0x0c, 0x00,
	0x11, 0x1f, 0x11, 0x04, 0x1e, 0x05, 0x00, 0x1f,
	0x10, 0x0f, 0x00, 0x1e, 0x0a, 0x0c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x11, 0x0f, 0x01, 0x00, 0x0e, 0x10, 0x1e, 0x00,
	0x1e, 0x0c, 0x1c, 0x00, 0x1e, 0x0a, 0x0c, 0x00,
	0x01, 0x1f, 0x01, 0x0c, 0x12, 0x0c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x0f,
	0x01, 0x00, 0x0e, 0x10, 0x1e, 0x00, 0x1e, 0x0c,
	0x1c, 0x00, 0x1e, 0x0a, 0x0c, 0x00, 0x00, 0x07,
	0x18, 0x07, 0x00, 0x1a, 0x00, 0x0c, 0x14, 0x1c,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1f, 0x01, 0x1e, 0x00,
	0x0c, 0x12, 0x0c, 0x00, 0x0e, 0x11, 0x0e, 0x00,
	0x1e, 0x0a, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0x01, 0x1e, 0x00, 0x0c, 0x12,
	0x0c, 0x00, 0x0e, 0x11, 0x0e, 0x00, 0x1e, 0x0a,
	0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x1f, 0x05, 0x06, 0x00, 0x1e, 0x04, 0x02, 0x00,
	0x1d, 0x00, 0x1e, 0x02, 0x1c, 0x00, 0x02, 0x1f,
	0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10,
	0x0f, 0x1e, 0x0a, 0x0c, 0x18, 0x14, 0x1f, 0x0c,
	0x14, 0x1c, 0x04, 0x1f, 0x04, 0x0c, 0x1a, 0x14,
	0x00, 0x1f, 0x11, 0x0e, 0x1d, 0x00, 0x16, 0x1a,
	0x00, 0x1e, 0x0a, 0x0c, 0x1f, 0x0c, 0x14, 0x1c,
	0x00, 0x12, 0x14, 0x0e, 0x1f, 0x01, 0x1e, 0x00,
	0x0c, 0x12, 0x0c, 0x00, 0x0e, 0x11, 0x0e, 0x00,
	0x1e, 0x0a, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0x15, 0x11, 0x00, 0x14, 0x08,
	0x14, 0x00, 0x1d, 0x00, 0x02, 0x1f, 0x02, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x16, 0x15, 0x09, 0x00, 0x0c, 0x1a, 0x16, 0x00,
	0x02, 0x1f, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x16, 0x15,
	0x09, 0x00, 0x0c, 0x1a, 0x16, 0x00, 0x02, 0x1f,
	0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0x1e, 0x05, 0x1e, 0x00,
	0x18, 0x14, 0x1f, 0x00, 0x18, 0x14, 0x1f, 0x00,
	0x00, 0x00, 0x01, 0x1f, 0x01, 0x0c, 0x12, 0x0c,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x1e, 0x05, 0x1e, 0x00, 0x18, 0x14,
	0x1f, 0x00, 0x18, 0x14, 0x1f, 0x00, 0x00, 0x00,
	0x01, 0x1f, 0x01, 0x0c, 0x12, 0x0c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0x16, 0x15, 0x0d, 0x0e, 0x10, 0x1e, 0x00, 0x1f,
	0x14, 0x18, 0x02, 0x1f, 0x02, 0x1e, 0x04, 0x02,
	0x10, 0x00, 0x01, 0x1f, 0x01, 0x0c, 0x12, 0x0c,
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x16, 0x15,
	0x0d, 0x0e, 0x10, 0x1e, 0x00, 0x1f, 0x14, 0x18,
	0x02, 0x1f, 0x02, 0x1e, 0x04, 0x02, 0x10, 0x00,
	0x01, 0x1f, 0x01, 0x0c, 0x12, 0x0c, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0x1f, 0x03, 0x1f, 0x00,
	0x0e, 0x10, 0x1e, 0x00, 0x1f, 0x00, 0x02, 0x1f,
	0x02, 0x1d, 0x00, 0x1e, 0x0a, 0x0c, 0x1f, 0x12,
	0x14, 0x1e, 0x01, 0x1f, 0x0d, 0x12, 0x0c, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x1f, 0x03, 0x1f, 0x00, 0x0e, 0x10,
	0x1e, 0x00, 0x1f, 0x00, 0x02, 0x1f, 0x02, 0x1d,
	0x00, 0x1e, 0x0a, 0x0c, 0x1f, 0x12, 0x14, 0x1e,
	0x01, 0x1f, 0x0d, 0x12, 0x0c, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0x1f, 0x11, 0x0e, 0x00, 0x1d, 0x00, 0x0c, 0x10,
	0x0c, 0x00, 0x1d, 0x00, 0x18, 0x14, 0x1f, 0x00,
	0x0c, 0x1a, 0x14, 0x01, 0x1f, 0x01, 0x0c, 0x12,
	0x0c, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x03,
	0x1f, 0x08, 0x14, 0x08, 0x18, 0x14, 0x1f, 0x0c,
	0x10, 0x1c, 0x00, 0x1f, 0x00, 0x0c, 0x10, 0x1c,
	0x08, 0x14, 0x08, 0x01, 0x1f, 0x01, 0x0c, 0x12,
	0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0x16, 0x15, 0x0d, 0x00,
	0x1f, 0x04, 0x1a, 0x00, 0x1d, 0x00, 0x1e, 0x0a,
	0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x1a,
	0x0e, 0x0b, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x16, 0x15, 0x0d, 0x00, 0x1f, 0x04,
	0x1a, 0x00, 0x1d, 0x00, 0x1e, 0x0a, 0x0c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0a, 0x1a, 0x0e, 0x0b,
	0x0a, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0x16, 0x15, 0x0d, 0x00, 0x1f, 0x04, 0x1a, 0x00,
	0x1d, 0x00, 0x1e, 0x0a, 0x0c, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x00,
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x16, 0x15,
	0x0d, 0x00, 0x1f, 0x04, 0x1a, 0x00, 0x1d, 0x00,
	0x1e, 0x0a, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x04, 0x0a, 0x11, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0x16, 0x15, 0x0d, 0x00,
	0x1f, 0x04, 0x1a, 0x00, 0x1d, 0x00, 0x1e, 0x0a,
	0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11,
	0x0a, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x16, 0x15, 0x0d, 0x00, 0x1f, 0x04,
	0x1a, 0x00, 0x1d, 0x00, 0x1e, 0x0a, 0x0c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0a, 0x0a, 0x0a, 0x0a,
	0x0a, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
};

#endif
