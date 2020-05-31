#include <catch.hpp>
#include <rexx/metafunctions/remove_if.hpp>

TEST_CASE( "remove_if metafunction tests", "[metafunction]" ) {

    using t1 = std::tuple<const int, double, volatile char>;

    REQUIRE(std::is_same_v<typename rexx::metafunctions::remove_if<t1, std::is_floating_point>::type, std::tuple<const int, volatile char>>);
    REQUIRE(std::is_same_v<typename rexx::metafunctions::remove_if<t1, std::is_const>::type, std::tuple<double, volatile char>>);
    REQUIRE(std::is_same_v<typename rexx::metafunctions::remove_if<t1, std::is_volatile>::type, std::tuple<const int, double>>);
    REQUIRE(std::is_same_v<typename rexx::metafunctions::remove_if<std::tuple<>, std::is_volatile>::type, std::tuple<>>);

}