#include <catch.hpp>
#include <rexx/metafunctions/skip.hpp>

TEST_CASE( "skip function tests", "[metafunction]" ) {

    using t1 = std::tuple<int, double, float, char, size_t>;

    REQUIRE(std::is_same_v<rexx::metafunctions::skip<t1, 3>::type, std::tuple<char, size_t>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::skip<t1, 4>::type, std::tuple<size_t>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::skip<t1, 5>::type, std::tuple<>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::skip<t1, 0>::type, t1>);
    REQUIRE(std::is_same_v<rexx::metafunctions::skip<t1, 6>::type, std::tuple<>>);
}