#include <catch.hpp>
#include <rexx/metafunctions/concat.hpp>

TEST_CASE( "concat metafunction tests", "[metafunction]" ) {

    using t1 = std::tuple<int, double, char>;
    using t2 = std::tuple<float, long, short>;

    REQUIRE(std::is_same_v<rexx::metafunctions::concat<t1,t2>::type,
                           std::tuple<int,double,char,float,long,short>>);

    REQUIRE(std::is_same_v<rexx::metafunctions::concat<t1,std::tuple<>>::type,
                    std::tuple<int,double,char>>);

    REQUIRE(std::is_same_v<rexx::metafunctions::concat<std::tuple<>,t2>::type,
                    std::tuple<float,long,short>>);

    REQUIRE(std::is_same_v<rexx::metafunctions::concat<std::tuple<>,std::tuple<>>::type,
                    std::tuple<>>);
}