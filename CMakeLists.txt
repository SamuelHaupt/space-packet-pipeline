cmake_minimum_required(VERSION 3.20)
project(SpacePacketPipeline CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(SpacePacketPipeline
    src/main.cpp
)
target_include_directories(SpacePacketPipeline PRIVATE include)

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.7.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(unit_tests
  tests/domain/test_apid.cpp
)
target_include_directories(unit_tests PRIVATE include)
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

enable_testing()
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)