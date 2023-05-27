#include "grid_square.h"

grid_square::grid_square () {
  set_n(0);
}

/** @param n The number of points on the side of the square grid. */
grid_square::grid_square (unsigned int n) {
  set_n(n);
  fill();
}

grid_square* grid_square::clone_impl() const {
  return new grid_square(*this);
}

void grid_square::fill () {
  points.clear();
  double step = 2.0 / (n - 1);
  for (unsigned int ix = 0 ; ix < n ; ix++) {
    double x = -1.0 + ix * step;
    for (unsigned int iy = 0 ; iy < n ; iy++) {
      double y = -1.0 + iy * step;
      points.push_back(Vec2(x, y));
    }
  }
}

void grid_square::set_n (unsigned int n) {
  this->n = n;
}

std::string grid_square::print_type () const {
  return "grid_square";
}
