#include <catch.hpp>
#include <rexx/constexpr/front.hpp>

namespace rexx::tests::front {
    constexpr auto t1 = std::make_tuple(5, 6.0, 'c');
    constexpr auto &r1 = rexx::cexpr::front(t1);
    constexpr auto r2 = rexx::cexpr::front(std::make_tuple(1, 2.0, 'c'));
}

TEST_CASE( "front constexpr tests", "[constexpr]" ) {

    SECTION("ensure lvalue and rvalue expressions are dealth with correctly at compile time") {
        REQUIRE(std::is_same_v<decltype(rexx::tests::front::r1), int const&> );
        REQUIRE(std::is_same_v<decltype(rexx::tests::front::r2), const int> );

        REQUIRE(rexx::tests::front::r1 == 5);
        REQUIRE(rexx::tests::front::r2 == 1);
    }

    SECTION("ensure lvalue and rvalue expressions are dealth with correctly at runtime") {
        constexpr auto t1 = std::make_tuple(5, 6.0, 'c');
        REQUIRE(rexx::cexpr::front(t1) == 5);
        REQUIRE(rexx::cexpr::front(std::make_tuple(1,2.0,'c')) == 1);
    }
}