## Catch2 dependency
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.2.0
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(Catch2)

set(RBT_SAMPLINGS_TEST_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE RBT_SAMPLINGS_TEST_SRC "${RBT_SAMPLINGS_TEST_DIR}/*.cpp")
add_executable(rbt-samplings-test "${RBT_SAMPLINGS_TEST_DIR}/test_main.cpp"
               ${RBT_SAMPLINGS_TEST_SRC})
target_link_libraries(rbt-samplings-test PRIVATE
                      rbt-samplings Catch2::Catch2WithMain)

if(rbt-samplings-coverage)
  include(CodeCoverage)
  add_executable(rbt_samplings_coverage
                 ${RBT_SAMPLINGS_SOURCES} ${RBT_SAMPLINGS_TEST_SRC})
  target_link_libraries(rbt_samplings_coverage PRIVATE
                        rbt-samplings Catch2::Catch2WithMain)
  set_target_properties(rbt_samplings_coverage PROPERTIES COMPILE_FLAGS
	"${CMAKE_CXX_FLAGS} -O0 -Wall -fprofile-arcs -ftest-coverage")
  setup_target_for_coverage_lcov(
    NAME rbt_samplings_coverage_report
    EXECUTABLE rbt_samplings_coverage
    BASE_DIRECTORY "${RBT_SAMPLINGS_DIR}/src/"
    EXCLUDE "${RBT_SAMPLINGS_DIR}/test/*" "${RBT_SAMPLINGS_DIR}/build/_deps/*"
            "/usr/*")
endif()
