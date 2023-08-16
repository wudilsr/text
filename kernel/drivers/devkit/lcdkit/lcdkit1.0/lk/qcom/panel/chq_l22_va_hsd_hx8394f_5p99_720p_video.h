/* Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*-------------------------------------------------------------------------
 * This file is autogenerated file using gcdb parser. Please do not edit it.
 * Update input XML file to add a new entry or update variable in this file
 * VERSION = 1.1
 *-----------------------------------------------------------------------*/

#ifndef _PANEL_CHQ_L22_VA_HSD_HX8394F_5P99_720P_VIDEO_H_

#define _PANEL_CHQ_L22_VA_HSD_HX8394F_5P99_720P_VIDEO_H_
/*-----------------------------------------------------------------------*/
/* HEADER files                                                          */
/*-----------------------------------------------------------------------*/
#include "panel.h"

#include "lcdkit_bias_ic_common.h"

#include "lcd_bl.h"

/*-----------------------------------------------------------------------*/
/* Panel configuration                                                   */
/*-----------------------------------------------------------------------*/
static struct panel_config chq_l22_va_hsd_hx8394f_5p99_720p_video_panel_data = {
        "lcdkit_chq_l22_va_hsd_hx8394f_5p99_720p_video", "dsi:0:", 
        "hsd-hx8394f-5p99-720p-video", 10, 0, "DISPLAY_1", 0, 433060000, 
        60, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* Panel resolution                                                      */
/*-----------------------------------------------------------------------*/
static struct panel_resolution chq_l22_va_hsd_hx8394f_5p99_720p_video_panel_res = {
        720, 1440, 40, 40, 20, 0, 9, 16, 2, 0, 0, 0, 0, 0, 0, 0, 0, 
        0 
};

/*-----------------------------------------------------------------------*/
/* Panel color information                                               */
/*-----------------------------------------------------------------------*/
static struct color_info chq_l22_va_hsd_hx8394f_5p99_720p_video_color = {
        24, 0, 0x00, 0, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* Panel on/off command                                                  */
/*-----------------------------------------------------------------------*/
static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd0[] = {
    0x04, 0x00, 0x39, 0xC0,
    0xB9, 0xFF, 0x83, 0x94,
   };


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd1[] = {
    0x0B, 0x00, 0x39, 0xC0,
    0xB1, 0x48, 0x13, 0x73,
    0x09, 0x32, 0x84, 0x91,
    0x51, 0x6D, 0x43, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd2[] = {
    0x07, 0x00, 0x39, 0xC0,
    0xBA, 0x63, 0x03, 0x68,
    0x7B, 0xB2, 0xC0, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd3[] = {
    0x06, 0x00, 0x39, 0xC0,
    0xB2, 0x00, 0x80, 0x78,
    0x0C, 0x07, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd4[] = {
    0x16, 0x00, 0x39, 0xC0,
    0xB4, 0x04, 0x6F, 0x04,
    0x6F, 0x04, 0x6F, 0x01,
    0x0C, 0x7C, 0x35, 0x00,
    0x3F, 0x01, 0x6B, 0x01,
    0x6B, 0x01, 0x6B, 0x01,
    0x0C, 0x7C, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd5[] = {
    0x22, 0x00, 0x39, 0xC0,
    0xD3, 0x00, 0x00, 0x0B,
    0x0B, 0x3C, 0x1C, 0x00,
    0x00, 0x32, 0x10, 0x09,
    0x00, 0x09, 0x32, 0x15,
    0xAD, 0x05, 0xAD, 0x32,
    0x00, 0x00, 0x00, 0x00,
    0x37, 0x03, 0x0B, 0x0B,
    0x37, 0x00, 0x00, 0x00,
    0x0C, 0x40, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd6[] = {
    0x2D, 0x00, 0x39, 0xC0,
    0xD5, 0x19, 0x19, 0x18,
    0x18, 0x1B, 0x1B, 0x1A,
    0x1A, 0x00, 0x01, 0x02,
    0x03, 0x04, 0x05, 0x06,
    0x07, 0x20, 0x21, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x24,
    0x25, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0xFF, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd7[] = {
    0x2D, 0x00, 0x39, 0xC0,
    0xD6, 0x18, 0x18, 0x19,
    0x19, 0x1B, 0x1B, 0x1A,
    0x1A, 0x07, 0x06, 0x05,
    0x04, 0x03, 0x02, 0x01,
    0x00, 0x25, 0x24, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x21,
    0x20, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0xFF, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd8[] = {
    0x3B, 0x00, 0x39, 0xC0,
    0xE0, 0x00, 0x09, 0x13,
    0x18, 0x1B, 0x1E, 0x21,
    0x1F, 0x3E, 0x4C, 0x4B,
    0x47, 0x4a, 0x5b, 0x58,
    0x60, 0x6a, 0x60, 0x64,
    0x70, 0x7f, 0x39, 0x47,
    0x56, 0x5C, 0x5D, 0x65,
    0x75, 0x7F, 0x00, 0x09,
    0x13, 0x18, 0x1B, 0x1E,
    0x21, 0x1F, 0x3E, 0x4B,
    0x69, 0x67, 0x74, 0x85,
    0x90, 0x90, 0xa0, 0xae,
    0xa2, 0xb3, 0xc5, 0x67,
    0x57, 0x51, 0x56, 0x5E,
    0x67, 0x76, 0x7F, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd9[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xCC, 0x0B, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd10[] = {
    0x03, 0x00, 0x39, 0xC0,
    0xC0, 0x1F, 0x31, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd11[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xD4, 0x02, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd12[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x01, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd13[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xB1, 0x00, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd14[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x00, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd15[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xD2, 0x66, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd16[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xC6, 0xED, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd17[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x00, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd18[] = {
    0x2C, 0x00, 0x39, 0xC0,
    0xC1, 0x01, 0x00, 0x08,
    0x10, 0x18, 0x20, 0x26,
    0x2E, 0x35, 0x3D, 0x44,
    0x4A, 0x51, 0x58, 0x5F,
    0x67, 0x6F, 0x78, 0x80,
    0x88, 0x90, 0x99, 0xA0,
    0xA8, 0xB0, 0xB8, 0xC1,
    0xCA, 0xD3, 0xDB, 0xE3,
    0xEC, 0xF5, 0xFF, 0x00,
    0x07, 0x47, 0xFB, 0x15,
    0x36, 0xEE, 0xBB, 0xC0,
   };


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd19[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x01, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd20[] = {
    0x2B, 0x00, 0x39, 0xC0,
    0xC1, 0x00, 0x08, 0x10,
    0x18, 0x21, 0x27, 0x30,
    0x37, 0x3F, 0x46, 0x4C,
    0x54, 0x5B, 0x62, 0x6A,
    0x72, 0x7A, 0x83, 0x8B,
    0x93, 0x9B, 0xA2, 0xAA,
    0xB2, 0xBA, 0xC3, 0xCC,
    0xD4, 0xDC, 0xE4, 0xED,
    0xF6, 0xFF, 0x1B, 0x33,
    0x48, 0x06, 0xC0, 0xBB,
    0xD7, 0xA0, 0xC0, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd21[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x02, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd22[] = {
    0x2B, 0x00, 0x39, 0xC0,
    0xC1, 0x00, 0x08, 0x10,
    0x18, 0x21, 0x28, 0x30,
    0x38, 0x40, 0x46, 0x4D,
    0x55, 0x5C, 0x63, 0x6C,
    0x74, 0x7D, 0x85, 0x8D,
    0x95, 0x9E, 0xA5, 0xAD,
    0xB6, 0xBE, 0xC7, 0xD0,
    0xD8, 0xE0, 0xE8, 0xF0,
    0xF8, 0xFF, 0x1B, 0x0A,
    0x39, 0x62, 0x1B, 0x7C,
    0xA2, 0x01, 0xC0, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd23[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x00, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd24[] = {
    0x02, 0x00, 0x39, 0xC0,
    0x35, 0x00, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd25[] = {
    0x02, 0x00, 0x39, 0xC0,
    0x11, 0x00, 0xFF, 0xFF};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd26[] = {
    0x02, 0x00, 0x39, 0xC0,
    0x29, 0x00, 0xFF, 0xFF};




static struct mipi_dsi_cmd chq_l22_va_hsd_hx8394f_5p99_720p_video_on_command[] = {
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd0, 0x00},
{0x10, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd1, 0x00},
{0xc, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd2, 0x00},
{0xc, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd3, 0x00},
{0x1c, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd4, 0x00},
{0x28, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd5, 0x00},
{0x34, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd6, 0x00},
{0x34, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd7, 0x00},
{0x40, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd8, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd9, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd10, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd11, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd12, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd13, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd14, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd15, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd16, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd17, 0x00},
{0x30, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd18, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd19, 0x00},
{0x30, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd20, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd21, 0x00},
{0x30, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd22, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd23, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd24, 0x00},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd25, 0x78},
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_on_cmd26, 0x14}
};
#define CHQ_L22_VA_HSD_HX8394F_5P99_720P_VIDEO_ON_COMMAND 27


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_off_cmd0[] = {
    0x28, 0x00, 0x05, 0x80};


static char chq_l22_va_hsd_hx8394f_5p99_720p_video_off_cmd1[] = {
    0x10, 0x00, 0x05, 0x80};




static struct mipi_dsi_cmd chq_l22_va_hsd_hx8394f_5p99_720p_video_off_command[] = {
{0x4, chq_l22_va_hsd_hx8394f_5p99_720p_video_off_cmd0, 0x32},
{0x4, chq_l22_va_hsd_hx8394f_5p99_720p_video_off_cmd1, 0x78}
};
#define CHQ_L22_VA_HSD_HX8394F_5P99_720P_VIDEO_OFF_COMMAND 2


static struct command_state chq_l22_va_hsd_hx8394f_5p99_720p_video_state = {
        0, 1 
};

/*-----------------------------------------------------------------------*/
/* Command mode panel                                                    */
/*-----------------------------------------------------------------------*/
static struct commandpanel_info chq_l22_va_hsd_hx8394f_5p99_720p_video_command_panel = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* Video mode panel                                                      */
/*-----------------------------------------------------------------------*/
static struct videopanel_info chq_l22_va_hsd_hx8394f_5p99_720p_video_video_panel = {
        1, 0, 0, 0, 1, 1, 2, 0, 0x9 
};

/*-----------------------------------------------------------------------*/
/* Lane configuration                                                    */
/*-----------------------------------------------------------------------*/
static struct lane_configuration chq_l22_va_hsd_hx8394f_5p99_720p_video_lane_config = {
        4, 0, 1, 1, 1, 1, 0 
};

/*-----------------------------------------------------------------------*/
/* Panel timing                                                          */
/*-----------------------------------------------------------------------*/
static const uint32_t chq_l22_va_hsd_hx8394f_5p99_720p_video_timings[]= {
        0x1E, 0x1B, 0x04, 0x06, 0x02, 0x03, 0x04, 0xA0,
					0x1E, 0x1B, 0x04, 0x06, 0x02, 0x03, 0x04, 0xA0,
					0x1E, 0x1B, 0x04, 0x06, 0x02, 0x03, 0x04, 0xA0,
					0x1E, 0x1B, 0x04, 0x06, 0x02, 0x03, 0x04, 0xA0,
					0x1E, 0x0D, 0x04, 0x05, 0x02, 0x03, 0x04, 0xA0 
};

static struct panel_timing chq_l22_va_hsd_hx8394f_5p99_720p_video_timing_info = {
        0, 4, 0x0A, 0x1D 
};

/*-----------------------------------------------------------------------*/
/* Panel reset sequence                                                  */
/*-----------------------------------------------------------------------*/
static struct panel_reset_sequence chq_l22_va_hsd_hx8394f_5p99_720p_video_reset_seq = {
    { 1, 0, 1, }, { 2, 2, 15, }, 2
};

/*-----------------------------------------------------------------------*/
/* Backlight setting                                                     */
/*-----------------------------------------------------------------------*/
static struct backlight chq_l22_va_hsd_hx8394f_5p99_720p_video_backlight = {
        2, 11, 1023, 1, 2, 0 
};

/*-----------------------------------------------------------------------*/
/* Labibb setting                                                        */
/*-----------------------------------------------------------------------*/
static struct labibb_desc chq_l22_va_hsd_hx8394f_5p99_720p_video_labibb = {
        0, 1, 5500000, 5500000, 5500000, 5500000, 3, 0, 3, 1, 0 
};

/*-----------------------------------------------------------------------*/
/* turn on backlight delay                                               */
/*-----------------------------------------------------------------------*/
int chq_l22_va_hsd_hx8394f_5p99_720p_video_mdp_pipe_type  = MDSS_MDP_PIPE_TYPE_RGB;

int chq_l22_va_hsd_hx8394f_5p99_720p_video_dsi_pll_type  = DSI_PLL_TYPE_THULIUM;

int chq_l22_va_hsd_hx8394f_5p99_720p_video_mipi_signature  = 0xffff;

static const uint32_t chq_l22_va_hsd_hx8394f_5p99_720p_video_regulator_setting[]= {
        0x1d, 0x1d, 0x1d, 0x1d, 0x1d 
};

/*-----------------------------------------------------------------------*/
/* platform Config                                                       */
/*-----------------------------------------------------------------------*/
static struct lcdkit_platform_config chq_l22_va_hsd_hx8394f_5p99_720p_video_panel_platform_config = {
        0, 0, 0, 0, 0x10002, 0x10000, 0x200, 0x20, 64, 0, 0, 61, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5500000, 5500000, 100, 20, 0, 
        0, 0, 0, 0, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* misc Information                                                      */
/*-----------------------------------------------------------------------*/
static struct lcdkit_misc_info chq_l22_va_hsd_hx8394f_5p99_720p_video_panel_misc_info = {
        0, 0, 0, 0x01, 0x01, 0x01, 0x01, 0, 1, 0, 1, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* delay ctrl                                                            */
/*-----------------------------------------------------------------------*/
static struct lcdkit_delay_ctrl chq_l22_va_hsd_hx8394f_5p99_720p_video_panel_delay_ctrl = {
        0, 10, 0, 3, 3, 0, 3, 5, 0, 0, 0, 0, 20, 0, 50 
};

static char chq_l22_va_hsd_hx8394f_5p99_720p_video_backlight_cmd0[] = {
    0x02, 0x00, 0x39, 0xC0,
    0x51, 0x00, 0xFF, 0xFF};




static struct mipi_dsi_cmd chq_l22_va_hsd_hx8394f_5p99_720p_video_backlight_command[] = {
{0x8, chq_l22_va_hsd_hx8394f_5p99_720p_video_backlight_cmd0, 0x00}
};
#define CHQ_L22_VA_HSD_HX8394F_5P99_720P_VIDEO_BACKLIGHT_COMMAND 1



static struct lcd_bias_voltage_info * chq_l22_va_hsd_hx8394f_5p99_720p_video_bias_ic_array[0];
 
#define CHQ_L22_VA_HSD_HX8394F_5P99_720P_VIDEO_BIAS_IC_ARRAY 0


static struct backlight_ic_info * chq_l22_va_hsd_hx8394f_5p99_720p_video_backlight_ic_array[0];
 
#define CHQ_L22_VA_HSD_HX8394F_5P99_720P_VIDEO_BACKLIGHT_IC_ARRAY 0


#endif /*_PANEL_CHQ_L22_VA_HSD_HX8394F_5P99_720P_VIDEO_H_*/