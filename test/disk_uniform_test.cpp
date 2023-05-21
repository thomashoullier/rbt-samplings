#include "disk_uniform_test.h"

TEST_CASE("disk_uniform", "[disk_uniform]") {
  SECTION("constructors") {
    disk_uniform du1;
    SUCCEED("Default constructor.");
    disk_uniform du2(3);
    SUCCEED("Initialization constructor.");
  }

  SECTION("printer") {
    boost::iostreams::stream<boost::iostreams::null_sink>
      nullOstream((boost::iostreams::null_sink()));
    disk_uniform du_print(3);
    nullOstream << du_print;
    SUCCEED("disk_uniform printed.");
  }
}
