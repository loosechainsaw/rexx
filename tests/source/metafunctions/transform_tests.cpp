#include <catch.hpp>
#include <rexx/metafunctions/transform.hpp>

TEST_CASE( "transform metafunction tests", "[metafunction]" ) {
    REQUIRE(std::is_same_v<rexx::metafunctions::transform<std::tuple<>, std::add_const>::type, std::tuple<>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::transform<std::tuple<int, float>, std::add_const>::type, std::tuple<const int, const float>>);
}