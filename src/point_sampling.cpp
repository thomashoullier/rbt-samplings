#include "point_sampling.h"

/** The z component of the ray position is set to zero. */
bun point_sampling::to_ray_bundle (const Vec3 &direction) const {
  bun ray_bundle;
  for (const auto &point : points) {
    Vec3 position = Vec2_to_Vec3(point);
    ray r(position, direction);
    ray_bundle.rays.push_back(r);
  }
  return ray_bundle;
}

/** This is an homothety around point (0, 0) by the given \p factor. */
void point_sampling::scale (double factor) {
  for (auto &point : points) {
    point = point * factor;
  }
}

std::ostream& operator<< (std::ostream &out,
                          const point_sampling &ps) {
  out << "<point-sampling of type '" << ps.print_type() << "'" << std::endl;
  for (const auto &point : ps.points) {
    out << point << std::endl;
  }
  out << ">";
  return out;
}
