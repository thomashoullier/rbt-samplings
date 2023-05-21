#include "disk_sampling.h"

/** The points from the square sampling are copied and mapped onto the unit
 * disk.
 * The map function is due to
 * https://psgraphics.blogspot.com/2011/01/improved-code-for-concentric-map.html
 * */
void disk_sampling::fill_from_square_map (const square_sampling &ss) {
  points = ss.points;
  for (auto &point : points) {
    if (not (point(0) == 0.0 && point(1) == 0.0)) {
      double phi = 0;
      double rad = 0;
      if (std::abs(point(0)) > std::abs(point(1))) {
        rad = point(0);
        phi = M_PI / 4 * point(1) / point(0);
      }
      else {
        rad = point(1);
        phi = M_PI / 2 - M_PI / 4 * point(0) / point(1);
      }
      point(0) = std::cos(phi) * rad;
      point(1) = std::sin(phi) * rad;
    }
  }
}
