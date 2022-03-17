#pragma once

#include "quantum.h"

// readability
#define ___ KC_NO

#define LAYOUT_epi_single_dox( \
  k01, k02, k03, k04, k05,    k06, k07, k08, k09, k0A, \
  k11, k12, k13, k14, k15,    k16, k17, k18, k19, k1A, \
  k21, k22, k23, k24, k25,    k26, k27, k28, k29, k2A, \
            k33, k34, k35,    k36, k37, k38            \
  ) \
  { \
    { k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A}, \
    { k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A}, \
    { k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A}, \
    { ___, ___, k33, k34, k35, k36, k37, k38, ___, ___} \
  }

#define LAYOUT LAYOUT_epi_single_dox
