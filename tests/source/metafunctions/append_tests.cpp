#include <catch.hpp>
#include <rexx/metafunctions/append.hpp>

TEST_CASE( "append metafunction tests", "[metafunction]" ) {
    REQUIRE(std::is_same_v<rexx::metafunctions::append<std::tuple<>, int>::type, std::tuple<int>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::append<std::tuple<float>, int>::type, std::tuple<float,int>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::append<std::tuple<float,double>, int>::type, std::tuple<float, double,int>>);
}