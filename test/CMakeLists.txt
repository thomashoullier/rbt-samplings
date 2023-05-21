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
