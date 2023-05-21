#include "vec2_test.h"

TEST_CASE("Vec2 tests", "[vec2]") {
  SECTION("constructors") {
    Vec2 v_def(1.2, 1.3);
    SUCCEED("Constructor.");
  }
  SECTION("methods") {
    Vec2 v_def(1.2, 1.3);
    auto v3 = Vec2_to_Vec3(v_def);
    SUCCEED("Call to Vec2_to_Vec3.");
    REQUIRE(v3(2) == 0.0);
  }
  SECTION("printer") {
    Vec2 v_def(1.2, 1.3);
    boost::iostreams::stream<boost::iostreams::null_sink>
      nullOstream((boost::iostreams::null_sink()));
    nullOstream << v_def;
    SUCCEED("Printing Vec2.");
  }
}
