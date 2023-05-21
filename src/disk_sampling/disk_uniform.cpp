#include "disk_uniform.h"

disk_uniform::disk_uniform () {
  set_n(0);
}

disk_uniform::disk_uniform (unsigned int n) {
  set_n(n);
  fill();
}

void disk_uniform::fill () {
  grid_square gs(n);
  this->fill_from_square_map(gs);
}

void disk_uniform::set_n (unsigned int n) {
  this->n = n;
}

std::string disk_uniform::print_type () const {
  return "disk_uniform";
}
