/** @file */
#ifndef TRIANGLE_DATA_H
#define TRIANGLE_DATA_H

#include <array>
#include <vector>
#include <iostream>


/** @brief Represents a triangular facet.
 *
 * Each element of the array is a point index. */
typedef std::array<int, 3> triangle_data;

/** @brief Triangulation set */
typedef std::vector<triangle_data> triangulation;

/** @brief triangle_data printer */
std::ostream& operator<< (std::ostream &out, const triangle_data &td);

/** @brief triangulation printer */
std::ostream& operator<< (std::ostream &out, const triangulation &tri);

#endif // TRIANGLE_DATA_H
