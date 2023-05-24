#include "point_sampling.h"

/** @param direction The direction vector of the rays in the bundle.
 *
 *  The z component of the ray position is set to zero.
 *  The rays in the bundle are in the same order as the points in the sampling.
 *  */
bun point_sampling::to_ray_bundle (const Vec3 &direction) const {
  bun ray_bundle;
  for (const auto &point : points) {
    Vec3 position = Vec2_to_Vec3(point);
    ray r(position, direction);
    ray_bundle.rays.push_back(r);
  }
  return ray_bundle;
}

/** We use the Qhull library to create a Delaunay triangulation of the points.
 * */
triangulation point_sampling::triangulate() const {
  // See the libqhull documentation:
  // https://docs.ros.org/en/fuerte/api/libqhull/html/index.html
  // Convert the points to the Qhull format.
  RboxPoints qcoords;
  for (const auto &in_point : points) {
    double coords[2] = {in_point(0), in_point(1)};
    QhullPoint qpoint(2, coords);
    qcoords.append(qpoint);
  }
  // Perform a Delaunay triangulation
  Qhull qhull;
  qhull.runQhull(qcoords, "d Qt"); // 'Qt' forces facets to be triangles.
  // Extract the facets
  triangulation tri_facets;
  std::vector<QhullFacet> facets = qhull.facetList().toStdVector();
  for (const auto &facet : facets) {
    QhullVertexSet facet_vertices = facet.vertices();
    triangle_data point_list = {facet_vertices.at(0).point().id(),
                                     facet_vertices.at(1).point().id(),
                                     facet_vertices.at(2).point().id()};
    tri_facets.push_back(point_list);
  }
  return tri_facets;
}

/** @param factor The scaling factor.
 *
 * This is an homothety around point (0, 0) by the given \p factor. */
void point_sampling::scale (double factor) {
  for (auto &point : points) {
    point = point * factor;
  }
}

/** The coordinates of the points in the sampling are printed. */
std::ostream& operator<< (std::ostream &out,
                          const point_sampling &ps) {
  out << "<point-sampling of type '" << ps.print_type() << "'" << std::endl;
  for (const auto &point : ps.points) {
    out << point << std::endl;
  }
  out << ">";
  return out;
}
