/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
//#define SPLIT_USB_DETECT
//#define SPLIT_USB_TIMEOUT 1000
//#define NO_USB_STARTUP_CHECK
#ifdef COMBO_ENABLE
  #define COMBO_COUNT 2
#endif

#define TAPPING_TERM 170
#define PERMISSIVE_HOLD
#define LEADER_PER_KEY_TIMING
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TOGGLE 2
#define LEADER_TIMEOUT 300

#undef MK_3_SPEED
#define MK_MOMENTARY_ACCEL

#define MK_C_OFFSET_0 1
#define MC_C_INTERVAL_0 16
#define MC_C_OFFSET_1 4
#define MK_C_INTERVAL_1 16
#define MK_C_OFFSET_UNMOD 8
#define MK_C_INTERVAL_UNMOD 16
#define MC_C_OFFSET_2 16
#define MK_C_INTERVAL_2 16
