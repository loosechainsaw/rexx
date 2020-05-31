#include <catch.hpp>
#include <rexx/metafunctions/any_of.hpp>

TEST_CASE( "any_of metafunction tests", "[metafunction]" ) {

    using t1 = std::tuple<int, float, const double>;

    REQUIRE(rexx::metafunctions::any_of<t1, std::is_const>::value);
    REQUIRE_FALSE(rexx::metafunctions::any_of<t1, std::is_enum>::value);
    REQUIRE_FALSE(rexx::metafunctions::any_of<std::tuple<>, std::is_enum>::value);
    REQUIRE(rexx::metafunctions::any_of<std::tuple<float>, std::is_floating_point>::value);
}