cmake_minimum_required(VERSION 3.10)

project(rbt-samplings)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
set(CMAKE_CXX_STANDARD 17)

# Loading external libraries
Include(FetchContent)
## robintrace
FetchContent_Declare(
  robintrace
  GIT_REPOSITORY https://github.com/thomashoullier/robintrace.git
  GIT_TAG        master
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(robintrace)
## qhull
FetchContent_Declare(
    qhull
    GIT_REPOSITORY https://github.com/qhull/qhull.git
    GIT_TAG master
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(qhull)
## TODO: is this line required?
include_directories(${qhull_SOURCE_DIR}/src/)

# Create the rbt-samplings library
set(RBT_SAMPLINGS_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE RBT_SAMPLINGS_SOURCES "${RBT_SAMPLINGS_DIR}/src/*.cpp")
add_library(rbt-samplings STATIC ${RBT_SAMPLINGS_SOURCES})
target_include_directories(rbt-samplings PUBLIC
                           "$<BUILD_INTERFACE:${RBT_SAMPLINGS_DIR}/src>")
## TODO: is qhullcpp required?
target_link_libraries(rbt-samplings PUBLIC robintrace qhullcpp qhullstatic_r)

# Targets
## Example
option(rbt-samplings-example "Build rbt-samplings example" OFF)
if (rbt-samplings-example)
add_executable(rbt-samplings-example ./example.cpp)
target_link_libraries(rbt-samplings-example PRIVATE rbt-samplings)
set_target_properties(rbt-samplings-example PROPERTIES COMPILE_FLAGS
                      "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra -march=native")
endif()

## Tests
option(rbt-samplings-test "Build rbt-samplings-test" OFF)
option(rbt-samplings-coverage "Build rbt-samplings-coverage" OFF)
if (rbt-samplings-test)
include("./test/CMakeLists.txt")
endif()
