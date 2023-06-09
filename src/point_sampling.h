/** @file */
#ifndef POINT_SAMPLING_H
#define POINT_SAMPLING_H

#include "robintrace.h"
#include "Vec2/Vec2.h"
#include "triangle_data/triangle_data.h"
#include <vector>
#include <array>
#include <memory>
#include <string>

// libqhull for triangulation.
#include <libqhullcpp/Qhull.h>
#include <libqhullcpp/QhullPoint.h>
#include <libqhullcpp/QhullFacetList.h>
#include <libqhullcpp/QhullVertexSet.h>
#include <libqhullcpp/RboxPoints.h>
using namespace orgQhull;

// matplotplusplus for plotting.
#include <matplot/matplot.h>

/** @brief Top-level class for rbt-samplings. All point samplings are of this
 * type. It implements general methods over point samplings. */
class point_sampling {
  public:
    /** @brief Vector of 2D points storing the sampling. */
    std::vector<Vec2> points;

    /** @brief Clone the point_sampling */
    std::unique_ptr<point_sampling> clone () const;

    /** @brief Fill the sampling with points according to specific input
     * parameters.
     * 
     * This function is virtual and depends on which specialization is used. */
    virtual void fill () = 0;

    /** @brief Convert to a ray bundle with a given direction. */
    bun to_ray_bundle (const Vec3 &direction) const;
    
    /** @brief Triangulate the points into a mesh structure over points. */
    triangulation triangulate() const;
    
    /** @brief Plot the points in a window. */
    void plot() const;
    /** @brief Plot to a file */
    void plot_tofile(std::string filename) const;

    /** @brief Scale the sampling. */
    void scale (double factor);
    
  private:
    /** @brief Clone implementation in derived classes */
    virtual point_sampling* clone_impl() const = 0;
    /** @brief Specialization-dependent string indicating the point sampling
     * type. */
    virtual std::string print_type () const = 0;
    /** @brief Internal initialization of the plot. */
    void plot_init () const;
      
    /** @brief Printer. */
    friend std::ostream& operator<< (std::ostream &out,
                                     const point_sampling &ps);
};

#endif // POINT_SAMPLING_H
