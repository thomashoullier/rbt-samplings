/** @file */
#ifndef DISK_SAMPLING_H
#define DISK_SAMPLING_H

#include "point_sampling.h"
#include "../square_sampling/square_sampling.h"
#define _USE_MATH_DEFINES
#include <cmath>

/** @brief Point sampling of the unit disk. */
class disk_sampling : public point_sampling {
  public:
    /** @brief Fill the sampling by mapping it from a square sampling. */
    void fill_from_square_map (const square_sampling &ss);
};

#endif // DISK_SAMPLING_H
