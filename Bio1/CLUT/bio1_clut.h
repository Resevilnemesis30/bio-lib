/*
*
*	Resident Evil
*
*	Color Look-Up Table
*
*	CAPCOM Co., Ltd.
*
*/


#pragma once


#include <cstdint>


// 8bpp - ITEM_ALL.PIX, ITEM_MIX.PIX, MEDAL.PIX
extern std::uint8_t bio1_status_clut02[0x200];


// 4bpp - FONT, normal (Trial Edition)
extern std::uint8_t bio1_trial_font_normal[0x20];

// 4bpp - FONT, normal
extern std::uint8_t bio1_dc_font_normal[0x20];

// 4bpp - FONT, green
extern std::uint8_t bio1_dc_font_green[0x20];

// 4bpp - FONT, green
extern std::uint8_t bio1_dc_font_red[0x20];

// 4bpp - FONT, grey
extern std::uint8_t bio1_dc_font_grey[0x20];