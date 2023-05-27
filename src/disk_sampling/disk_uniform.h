/** @file */
#ifndef DISK_UNIFORM_H
#define DISK_UNIFORM_H

#include "disk_sampling.h"
#include "../square_sampling/grid_square.h"

/** @brief Point sampling of the unit disk following a uniform repartition.
 *
 * It is generated thanks to a grid_square mapped onto the unit disk
 * by disk_sampling::fill_from_square_map. */
class disk_uniform : public disk_sampling {
  public:
    /** @brief Default constructor. */
    disk_uniform ();
    /** @brief Initialization constructor. */
    disk_uniform (unsigned int n);
    virtual void fill () override;
    /** @brief Set parameter \p n. */
    void set_n (unsigned int n);

  private:
    virtual disk_uniform* clone_impl() const override;
    /** @brief The number of points on the side of the generating square grid.
     *
     * The total number of points in the sampling is n x n. */
    unsigned int n;

    virtual std::string print_type () const override;
};

#endif // DISK_UNIFORM_H
