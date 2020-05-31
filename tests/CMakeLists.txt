cmake_minimum_required(VERSION 3.14)
project(tests)

set(SOURCES
        source/main.cpp
        source/any_of_tests.cpp
        source/all_of_tests.cpp
        source/prepend_tests.cpp
        source/append_tests.cpp
        source/remove_tests.cpp
        source/transform_tests.cpp
        source/skip_tests.cpp
        source/front_tests.cpp
        source/back_tests.cpp
        source/concat_tests.cpp source/remove_if_tests.cpp)

add_executable(tests ${SOURCES})
set_target_properties(tests PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        )
target_include_directories(tests PUBLIC include)
target_link_libraries(tests PUBLIC rexx)