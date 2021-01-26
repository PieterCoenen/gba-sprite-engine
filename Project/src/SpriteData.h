//
// Created by Pieter Coenen on 11/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SPRITEDATA_H
#define GBA_SPRITE_ENGINE_PROJECT_SPRITEDATA_H

//{{BLOCK(ball)

//======================================================================
//
//	ball, 8x8@8,
//	+ 1 tiles not compressed
//	Total size: 64 = 64
//
//	Time-stamp: 2018-08-08, 13:34:09
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int ballTiles[16] __attribute__((aligned(4)))=
        {
                0x05050503,0x03030303,0x04040405,0x03030305,0x04040405,0x03030305,0x05050503,0x03030303,
                0x03030303,0x03030303,0x03030303,0x03030303,0x03030303,0x03030303,0x03030303,0x03030303,
        };

//}}BLOCK(ball)

//{{BLOCK(paletteShared)

//======================================================================
//
//	paletteShared, 16x16@8,
//	+ palette 7 entries, not compressed
//	Total size: 14 = 14
//
//	Time-stamp: 2018-08-08, 13:34:09
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short paletteSharedPal[8] __attribute__((aligned(4)))=
        {
                0x0B50,0x0000,0x00BB,0x7FFF,0x1E7F,0x7FFF,0x39CE,
        };

//}}BLOCK(paletteShared)

//{{BLOCK(block_red)

//======================================================================
//
//	block_red, 16x8@8,
//	+ 2 tiles not compressed
//	Total size: 128 = 128
//
//	Time-stamp: 2018-08-08, 13:34:09
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int block_redTiles[32] __attribute__((aligned(4)))=
        {
                0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,
                0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x02020202,0x01010101,0x01010101,
                0x02020202,0x01020202,0x02020202,0x01020202,0x02020202,0x01020202,0x02020202,0x01020202,
                0x02020202,0x01020202,0x02020202,0x01020202,0x02020202,0x01020202,0x01010101,0x01010101,
        };

//}}BLOCK(block_red)

const unsigned short sharedPal[84] __attribute__((aligned(4)))=
        {
                0x0000,0x3AE2,0x7BBD,0x4042,0x008C,0x3614,0x633B,0x1151,
                0x36FD,0x4AB8,0x21B2,0x77BE,0x3E56,0x0D0F,0x1971,0x56FA,
                0x6B7D,0x2DD3,0x7FFF,0x04EE,0x1550,0x1593,0x4697,0x677C,
                0x52D9,0x5B1A,0x112F,0x1DF5,0x08EE,0x31F4,0x3635,0x08EF,
                0x739D,0x7BDF,0x371D,0x29B3,0x4677,0x00CD,0x2192,0x5F1A,
                0x1950,0x675B,0x1130,0x77DE,0x4276,0x3214,0x04CE,0x4EB8,
                0x4A97,0x56F9,0x25B2,0x3A35,0x5F3B,0x635B,0x3615,0x73BE,
                0x2DF4,0x1D91,0x25B3,0x6F9D,0x4ED8,0x6B5C,0x1530,0x56D9,

                0x6B7C,0x29D3,0x04CD,0x3A36,0x7BFF,0x00AD,0x4277,0x675C,
                0x1D71,0x73BD,0x5F1B,0x4256,0x1951,0x5AFA,0x7BDE,0x4A98,
                0x6F7D,0x2DF3,0x090F,
        };

#endif //GBA_SPRITE_ENGINE_PROJECT_SPRITEDATA_H
