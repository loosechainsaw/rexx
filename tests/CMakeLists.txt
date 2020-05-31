cmake_minimum_required(VERSION 3.14)
project(tests)

set(SOURCES
        source/main.cpp
        source/metafunctions/any_of_tests.cpp
        source/metafunctions/all_of_tests.cpp
        source/metafunctions/prepend_tests.cpp
        source/metafunctions/append_tests.cpp
        source/metafunctions/remove_tests.cpp
        source/metafunctions/transform_tests.cpp
        source/metafunctions/skip_tests.cpp
        source/metafunctions/front_tests.cpp
        source/metafunctions/back_tests.cpp
        source/metafunctions/concat_tests.cpp
        source/metafunctions/remove_if_tests.cpp

        source/constexpr/front.cpp

        )
set(COMPILER_OPTIONS)
set(LINKER_OPTIONS)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    list(APPEND COMPILER_OPTIONS "-fsanitize=address")
    list(APPEND LINKER_OPTIONS "-fsanitize=address")
endif()
add_executable(tests ${SOURCES})
set_target_properties(tests PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        )
target_compile_options(tests PUBLIC ${COMPILER_OPTIONS})
target_include_directories(tests PUBLIC include)
target_link_libraries(tests
    PUBLIC
        rexx
        ${LINKER_OPTIONS}
    )