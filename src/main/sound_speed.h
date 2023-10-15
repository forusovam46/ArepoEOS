/* 
 * Extension of AREPO code's ISOTHERM_EQS flag by optional thermal evolution
 * as part of my master's thesis
 * Magdalena Forusova 2024
 */

#ifndef SOUND_SPEED_H
#define SOUND_SPEED_H

// Enum for thermal evolution options
typedef enum {
    NO,                    // Default option - uses the value defined in parameters as originally i.e. no thermal evolution
    CONSTANT,              // Uses predefined constant values defined in sound_speed.c
    LINEAR,                // Uses predefined linear values defined in sound_speed.c
    POLYNOMIAL_PIECEWISE   // Uses predefined polynomial piecewise values defined in sound_speed.c
} SoundSpeedOption;

// Function to get the sound speed based on the chosen option
double getSoundSpeedIso(SoundSpeedOption option, double isoSoundSpeed, double time);

#endif