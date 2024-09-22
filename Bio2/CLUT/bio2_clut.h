/*
*
*	Resident Evil 2
*
*	Color Look-Up Table
*
*	CAPCOM Co., Ltd.
*
*/


#pragma once


#include <cstdint>


// 4bpp - *.CPT
extern std::uint8_t bio2_ds_cpt[0x20];


// 8bpp - ITPS.ITP, ITEMALL.PIX, MIX.PIX
extern std::uint8_t bio2_ds_ST0_texture00_clut01[0x200];


// 4bpp - ST0.TIM
extern std::uint8_t bio2_ds_ST0_texture01_clut[0x2A0];