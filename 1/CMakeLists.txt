cmake_minimum_required(VERSION 3.10)
project(replace_letters)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# тесты подрубаем
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)


add_executable(program main.cpp replace_letters.cpp)


add_executable(tests tests.cpp replace_letters.cpp)
target_link_libraries(tests gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)#сам ищи свои тесты!
