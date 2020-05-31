#include <catch.hpp>
#include <rexx/metafunctions/remove.hpp>

TEST_CASE( "remove metafunction tests", "[metafunction]" ) {
    REQUIRE(std::is_same_v<rexx::metafunctions::remove<std::tuple<>, int>::type, std::tuple<>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::remove<std::tuple<int, float>, int>::type, std::tuple<float>>);
    REQUIRE(std::is_same_v<rexx::metafunctions::remove<std::tuple<int, float, double>, double>::type, std::tuple<int, float>>);
}