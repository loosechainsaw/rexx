#include <catch.hpp>
#include <rexx/metafunctions/all_of.hpp>

TEST_CASE( "all_of metafunction tests", "[metafunction]" ) {

    using t1 = std::tuple<int, float, double>;
    using t2 = std::tuple<const float, float, double>;

    REQUIRE(rexx::metafunctions::all_of<t1, std::is_arithmetic>::value);
    REQUIRE_FALSE(rexx::metafunctions::all_of<t1, std::is_floating_point>::value);
    REQUIRE(rexx::metafunctions::all_of<t2, std::is_floating_point>::value);
    REQUIRE_FALSE(rexx::metafunctions::all_of<std::tuple<>, std::is_floating_point>::value);
    REQUIRE(rexx::metafunctions::all_of<std::tuple<float>, std::is_floating_point>::value);
}