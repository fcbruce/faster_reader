
option(test "Build all tests" OFF)

set(PROJECT_NAME faster_reader)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES
  src/*.cxx
  src/*.h
)

add_library(objfr OBJECT ${SOURCES})


############################
# Testing
############################
if (test)
  add_subdirectory(googletest)
  enable_testing()

  file(GLOB_RECURSE TEST_SOURCES "test/*.cxx")

  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  add_executable(testfasterreader ${TEST_SOURCES} $<TARGET_OBJECTS:objfr>)
  target_link_libraries(testfasterreader gtest gtest_main)

  add_test(TestFasterReader testfasterreader)
endif()