#include <catch.hpp>
#include <rexx/metafunctions/back.hpp>

TEST_CASE( "back metafunction tests", "[metafunction]" ) {

    using t1 = std::tuple<int, double, char>;

    REQUIRE(std::is_same_v<rexx::metafunctions::back<t1>::type, char>);
    REQUIRE(std::is_same_v<rexx::metafunctions::back<std::tuple<int>>::type, int>);
    REQUIRE(std::is_same_v<rexx::metafunctions::back<std::tuple<>>::type, rexx::utility::null_type>);
}