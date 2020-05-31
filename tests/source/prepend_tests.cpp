#include <catch.hpp>
#include <rexx/metafunctions/prepend.hpp>

TEST_CASE( "prepend metafunction tests", "[metafunction]" ) {
    REQUIRE(std::is_same_v<rexx::metafunctions::prepend<std::tuple<>, int>::type, std::tuple<int>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::prepend<std::tuple<float>, int>::type, std::tuple<int, float>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::prepend<std::tuple<float,double>, int>::type, std::tuple<int, float, double>>);
}