cmake_minimum_required(VERSION 3.20)

set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.0.sdk")

project(untitled4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add all source files to the project
set(SOURCES
        main.cpp


        )

# Add all header files to the project
set(HEADERS

        )

find_package(Qt5 COMPONENTS Core REQUIRED)

add_executable(untitled4 ${SOURCES} ${HEADERS})

target_link_libraries(untitled4 Qt5::Core)

set(GTest_ROOT "/usr/local/Cellar/googletest/1.13.0" CACHE PATH "Path to Google Test installation")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create a target for the test executables
set(TEST_SOURCES
        test/run_tests.cpp

        )

add_executable(run_tests ${TEST_SOURCES})

# Add the Google Test library as a dependency for the run_tests executable
target_link_libraries(run_tests PRIVATE ${GTEST_BOTH_LIBRARIES} Qt5::Core)

# Include directories for source files
target_include_directories(run_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Specify C++ standard for run_tests
target_compile_features(run_tests PRIVATE cxx_std_17)

enable_testing()
add_test(NAME test COMMAND run_tests)
