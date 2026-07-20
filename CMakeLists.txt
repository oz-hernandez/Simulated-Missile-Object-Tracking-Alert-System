cmake_minimum_required(VERSION 4.3.2)
project(ObjectTracker CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Main library (so both the app and tests can link against the same code) ---
add_library(tracker_lib
    src/Sensor.cpp
    src/TrackedObject.cpp
    src/Tracker.cpp
)
target_include_directories(tracker_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# --- Main executable ---
add_executable(object_tracker src/main.cpp)
target_link_libraries(object_tracker PRIVATE tracker_lib)

# --- Testing setup ---
enable_testing()
option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    # Avoid overriding parent project's compiler/linker settings on Windows
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_executable(unit_tests
        tests/test_sensor.cpp
        tests/test_tracked_object.cpp
        tests/test_tracker.cpp
    )
    target_link_libraries(unit_tests PRIVATE tracker_lib GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(unit_tests)
endif()