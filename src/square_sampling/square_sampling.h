#ifndef SQUARE_SAMPLING_H
#define SQUARE_SAMPLING_H

#include "point_sampling.h"

/** @brief Point sampling of the unit square. */
class square_sampling : public point_sampling {
  public:
    virtual void fill () = 0;

  private:
    virtual std::string print_type () const = 0;
};

#endif // SQUARE_SAMPLING_H
