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



#endif //GBA_SPRITE_ENGINE_PROJECT_SPRITEDATA_H
