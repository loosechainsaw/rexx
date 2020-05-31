cmake_minimum_required(VERSION 3.14)
project(rexx)
set(HEADERS
        include/rexx/utility/compile_time_type_printer.hpp
        include/rexx/utility/null_type.hpp
        include/rexx/metafunctions/front.hpp
        include/rexx/metafunctions/back.hpp
        include/rexx/metafunctions/append.hpp
        include/rexx/metafunctions/prepend.hpp
        include/rexx/metafunctions/transform.hpp
        include/rexx/metafunctions/zip.hpp
        include/rexx/metafunctions/skip.hpp
        include/rexx/metafunctions/take.hpp
        include/rexx/metafunctions/all_of.hpp
        include/rexx/metafunctions/any_of.hpp
        include/rexx/metafunctions/none_of.hpp
        include/rexx/metafunctions/fill_n.hpp
        include/rexx/metafunctions/remove.hpp
        include/rexx/metafunctions/remove_if.hpp
        include/rexx/metafunctions/concat.hpp
        include/rexx/rexx.hpp)
add_library(${CMAKE_PROJECT_NAME} INTERFACE)
target_include_directories(${CMAKE_PROJECT_NAME}
    INTERFACE
        include/
)