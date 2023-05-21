/** @file */
#ifndef POINT_SAMPLING_H
#define POINT_SAMPLING_H

#include "robintrace.h"
#include "Vec2/Vec2.h"
#include <vector>
#include <string>

/** @brief Top-level class for rbt-samplings. All point samplings are of this
 * type. It implements general methods over point samplings. */
class point_sampling {
  public:
    /** @brief Vector of 2D points storing the sampling. */
    std::vector<Vec2> points;

    /** @brief Fill the sampling with points according to specific input
     * parameters.
     * 
     * This function is virtual and depends on which specialization is used. */
    virtual void fill () = 0;

    /** @brief Convert to a ray bundle with a given direction. */
    bun to_ray_bundle (const Vec3 &direction) const;
    
    // TODO: Triangulate
    // TODO: Plot

    /** @brief Scale the sampling. */
    void scale (double factor);
    
  private:
    /** @brief Specialization-dependent string indicating the point sampling
     * type. */
    virtual std::string print_type () const = 0;
      
    /** @brief Printer. */
    friend std::ostream& operator<< (std::ostream &out,
                                     const point_sampling &ps);
};

#endif // POINT_SAMPLING_H
