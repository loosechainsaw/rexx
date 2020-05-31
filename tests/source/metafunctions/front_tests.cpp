#include <catch.hpp>
#include <rexx/metafunctions/front.hpp>

TEST_CASE( "front metafunction tests", "[metafunction]" ) {

    using t1 = std::tuple<int, double, char>;

    REQUIRE(std::is_same_v<rexx::metafunctions::front<t1>::type, int>);
    REQUIRE(std::is_same_v<rexx::metafunctions::front<std::tuple<int>>::type, int>);
    REQUIRE(std::is_same_v<rexx::metafunctions::front<std::tuple<>>::type, rexx::utility::null_type>);
}