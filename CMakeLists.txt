
option(test "Build all tests" OFF)

set(PROJECT_NAME faster_reader)
project(${PROJECT_NAME})

include_directories(include)

add_library(objcommon OBJECT src/common/common.cxx)


############################
# Testing
############################
if (test)
  add_subdirectory(googletest)
  enable_testing()

  file(GLOB_RECURSE TEST_SOURCES "test/*.cxx")

  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  add_executable(testfasterreader ${TEST_SOURCES} $<TARGET_OBJECTS:objcommon>)
  target_link_libraries(testfasterreader gtest gtest_main)

  add_test(TestFasterReader testfasterreader)
endif()