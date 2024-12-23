Arepo public version
====================

AREPO is a massively parallel code for gravitational n-body 
systems and hydrodynamics, both on Newtonian as well as 
cosmological background. It is a flexible code that can be 
applied to a variety of different types of simulations, offering 
a number of sophisticated simulation algorithms. An description 
of the numerical algorithms employed by the code is given in the 
original code papers (Springel 2010, MNRAS, 401, 791; 
Pakmor et al. 2011, MNRAS, 418, 1392; Pakmor and Springel 2013, 
MNRAS, 432, 176; Pakmor et al. 2016, MNRAS,455,1134) and the 
release paper of this version (Weinberger et al. 2019). 

A user guide can be found under `/documentation`, which also 
includes a 'getting started' section, which is recommended for 
new users. An html version of the user guide can be created using
sphinx (https://www.sphinx-doc.org) by typing

    cd ./documentation/
    make html
    
and displayed by opening `./documentation/build/html/index.html`.

A full version of the user guide is also available on the Arepo 
homepage.

---

This EOS Version (Master's Thesis 2024)
---------------------------------------

This version of AREPO attempted to extend the `ISOTHERM_EQS` flag to incorporate optional thermal evolution.

Key Features of the Attempt:
- **Thermal Evolution Models**:
  Introduced a `SoundSpeedOption` enum with the following options:
  - `NO`: Default behavior using a constant sound speed as per `param.txt`.
  - `CONSTANT`: Predefined constant values for sound speed.
  - `LINEAR`: Linearly evolving sound speed as a function of the scale factor.
  - `POLYNOMIAL_PIECEWISE`: Piecewise polynomial fit for sound speed evolution.

- **Configuration**:
  Configured in `allvars.c` for ease of modification. Default values/functions were derived from the CAMELS CV0 simulations.

- **Implementation**:
  - New files `sound_speed.c` and `sound_speed.h` implement the evolution logic.
  - Added `getSoundSpeedIso` function to compute sound speed based on the selected model.
  - Updated `allvars.h` to include the `SoundSpeedOption` enum.

Limitations:
This approach faced challenges, including instability in cosmological volume simulations, particularly with negative density values. It became evident that the `ISOTHERM_EQS` flag in its original implementation was unsuitable for the project's scientific goals. This led to a reevaluation and subsequent developments in a more robust version.

For details on the revised model, visit to the second repository [here](https://github.com/forusovam46/ArepoEOS2).
