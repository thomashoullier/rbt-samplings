#include "point_sampling_test.h"

TEST_CASE("point_sampling methods", "[point_sampling]") {
  SECTION("Scaling") {
    // We scale the sampling and check the first point.
    disk_uniform du_unit(3);
    auto ref_point = du_unit.points.front();
    du_unit.scale(2.0);
    SUCCEED("scale called.");
    auto scaled_point = du_unit.points.front();
    REQUIRE(scaled_point(0) == Catch::Approx(ref_point(0) * 2.0));
    REQUIRE(scaled_point(1) == Catch::Approx(ref_point(1) * 2.0));
  }

  SECTION("Conversion to ray bundle.") {
    // We check the first point for correctness.
    Vec3 direction(0.0, 0.0, 1.0);
    disk_uniform du(3);
    auto ref_point = du.points.front();
    auto bundle = du.to_ray_bundle(direction);
    auto first_ray = bundle.rays.front();
    REQUIRE(ref_point(0) == first_ray.p(0));
    REQUIRE(ref_point(1) == first_ray.p(1));
    REQUIRE(first_ray.p(2) == 0.0);
    REQUIRE(first_ray.v(0) == direction(0));
    REQUIRE(first_ray.v(1) == direction(1));
    REQUIRE(first_ray.v(2) == direction(2));
  }
}
