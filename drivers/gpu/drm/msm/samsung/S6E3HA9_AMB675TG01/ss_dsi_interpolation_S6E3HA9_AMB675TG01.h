/*
 * =================================================================
 *
 *       Filename:  ss_dsi_flash_dimming_S6E3HA9_AMB675TG01.c
 *
 *    Description:  Smart dimming algorithm implementation
 *
 *        Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2018, Samsung Electronics. All rights reserved.

 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef _SS_DSI_INTERPOLATION_S6E3HA9_AMB675TG01_H_
#define _SS_DSI_INTERPOLATION_S6E3HA9_AMB675TG01_H_

#include "ss_dsi_panel_common.h"

#define GAMMA_SIZE 34
#define AOR_SIZE 2
#define VINT_SIZE 1
#define ELVSS_SIZE 3
#define IRC_SIZE 28

#define IRC_START_OFFSET 2

enum IRC_MTP {
	IRC_0_V1,
	IRC_64_V1,
	IRC_128_V1,
	IRC_192_V1,
	IRC_255_V1,
	IRC_V1_MAX,
};

enum {
	V255_BLUE_BIT8,
	V255_BLUE_BIT9,
	V255_GREEN_BIT8,
	V255_GREEN_BIT9,
	V255_RED_BIT8,
	V255_RED_BIT9,
	V255_SIGN_BIT_MAX,
};

int table_parsing_data_S6E3HA9_AMB675TG01(struct samsung_display_driver_data *vdd);
int table_gamma_update_S6E3HA9_AMB675TG01(struct samsung_display_driver_data *vdd);

int init_interpolation_S6E3HA9_AMB675TG01(struct samsung_display_driver_data *vdd, enum INTERPOLATION_MODE mode);
int flash_gamma_support_S6E3HA9_AMB675TG01(struct samsung_display_driver_data *vdd);

/* Below formula could be changed for each panel */
void gen_hbm_interpolation_gamma_S6E3HA9_AMB675TG01(struct samsung_display_driver_data *vdd,
		struct ss_interpolation_brightness_table *normal_table, int normal_table_size);
void gen_hbm_interpolation_irc_S6E3HA9_AMB675TG01(struct samsung_display_driver_data *vdd,
		struct ss_interpolation_brightness_table *hbml_table, int hbm_table_size);
void gen_normal_interpolation_irc_S6E3HA9_AMB675TG01(struct samsung_display_driver_data *vdd,
		struct ss_interpolation_brightness_table *normal_table, int normal_table_size);

#endif
