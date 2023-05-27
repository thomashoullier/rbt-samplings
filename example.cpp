#include <iostream>

#include "rbt_samplings.h"

int main () {
  std::cout << "# rbt-samplings example #" << std::endl;

  std::cout << "## grid_square sampling" << std::endl;
  grid_square gs(3);
  std::cout << gs << std::endl;

  std::cout << "## disk_uniform sampling" << std::endl;
  disk_uniform du(3);
  std::cout << du << std::endl;

  std::cout << "## Clone a point_sampling" << std::endl;
  std::unique_ptr<point_sampling> du_clone = du.clone();
  std::cout << *du_clone << std::endl;

  std::cout << "## Scale a point_sampling" << std::endl;
  du_clone->scale(2);
  std::cout << *du_clone << std::endl;

  std::cout << "## Convert to a ray bundle" << std::endl;
  bun du_b = du.to_ray_bundle(Vec3(0, 0, 1));
  std::cout << du_b << std::endl;

  std::cout << "## Triangulate the sampling" << std::endl;
  triangulation du_tri = du.triangulate();
  std::cout << du_tri << std::endl;

  std::cout << "## Plot the sampling" << std::endl;
  du.plot();

  std::cout << "## Plot to a file" << std::endl;
  du.plot_tofile("disk_uniform_3.png");
}
