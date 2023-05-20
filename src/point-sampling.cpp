#include "point-sampling.h"

/** The z component of the ray position is set to zero. */
bun point-sampling::to_ray_bundle (const Vec3 &direction) const {
  bun ray_bundle;
  for (const auto &point : points) {
    Vec3 position = Vec2_to_Vec3(point);
    ray r(position, direction);
    ray_bundle.push_back(r);
  }
  return ray_bundle;
}

/** This is an homothety around point (0, 0) by the given \p factor. */
void point-sampling::scale (double factor) {
  for (auto &point : points) {
    point = point * factor;
  }
}

friend std::ostream& operator<< (std::ostream &out,
                                 const point-sampling &ps) {
  out << "<point-sampling of type '" << print_type() << "'" << std::endl;
  for (const auto &point : points) {
    out << point << std::endl;
  }
  out << ">";
  return out;
}
