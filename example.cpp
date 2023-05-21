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
}
