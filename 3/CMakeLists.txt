cmake_minimum_required(VERSION 3.10)
project(geometry)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/include)


add_library(geometry_lib
    src/square.cpp
    src/rectangle.cpp
    src/trapezoid.cpp
)


add_executable(geometry_app src/main.cpp)
target_link_libraries(geometry_app geometry_lib)


enable_testing()
add_executable(tests tests/tests.cpp)
target_link_libraries(tests
    geometry_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)