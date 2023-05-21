#include "grid_square_test.h"

TEST_CASE("grid_square tests", "[grid_square]") {
  SECTION("constructors") {
    grid_square gs;
    SUCCEED("grid_square default constructor.");
  }
}
