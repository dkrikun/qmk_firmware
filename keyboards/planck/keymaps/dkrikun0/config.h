#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2


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
