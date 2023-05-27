/** @file */
#ifndef GRID_SQUARE_H
#define GRID_SQUARE_H

#include "square_sampling.h"

/** @brief Point sampling of the unit square according to a regular cartesian
 *  grid with \p n points on its side. */
class grid_square : public square_sampling {
  public:
    /** @brief Default constructor. */
    grid_square ();
    /** @brief Initialization constructor. */
    grid_square (unsigned int n);

    /** @brief Generate the n x n grid of points. */
    virtual void fill () override;

    /** @brief Set the number of points \p n on the side of the square. */
    void set_n (unsigned int n);
  
  private:
    virtual grid_square* clone_impl() const override;
    /** @brief The number of points on the side of the square grid.
     * 
     * The total number of points in the sampling is then n x n. */
    unsigned int n;

    virtual std::string print_type () const override;
};

#endif // GRID_SQUARE_H
