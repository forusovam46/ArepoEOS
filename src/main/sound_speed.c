/* 
 * Extension of AREPO code's ISOTHERM_EQS flag by optional thermal evolution
 * as part of my master's thesis
 * Magdalena Forusova 2024
 */

#include "sound_speed.h"

double getSoundSpeedIso(SoundSpeedOption option, double isoSoundSpeed, double time) {
    double csnd;
    double a_0 = 0.14;

    switch (option) {
        case CONSTANT:
            // Option a) constant
            // cs(a) = { 33.00 }
            csnd = 33;
            break;

        case LINEAR:
            // Option b) linear
            // cs(a) = { 1.54 + 62.71*a^1 }
            csnd = 1.54 + 62.71 * time;
            break;

        case POLYNOMIAL_PIECEWISE:
            // Option c) polynomial piecewise fit
            // cs(a) = { 0.04 if a < 0.1 else -35.81 + 520.34*a^1 + -1959.49*a^2 + 3725.42*a^3 + -3204.75*a^4 + 1015.11*a^5 }
            if (time <= a_0) {
                csnd = 0.04;
            } else {
                csnd = -35.81 +
                       520.34 * pow(time - a_0, 1) +
                       -1959.49 * pow(time - a_0, 2) +
                       3725.42 * pow(time - a_0, 3) +
                       -3204.75 * pow(time - a_0, 4) +
                       1015.11 * pow(time - a_0, 5);
            }
            break;

        default:
            csnd = isoSoundSpeed;
            break;
    }

    return csnd;
}
