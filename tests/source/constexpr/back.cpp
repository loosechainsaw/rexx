#include <catch.hpp>
#include <rexx/constexpr/back.hpp>

namespace rexx::tests::back {
    constexpr auto t1 = std::make_tuple(5, 6.0, 'c');
    constexpr auto& r1 = rexx::cexpr::back(t1);
    constexpr auto r2 = rexx::cexpr::back(std::make_tuple(1, 2.0, 'c'));
}

TEST_CASE( "back constexpr tests", "[constexpr]" ) {

    SECTION("ensure lvalue and rvalue expressions are dealth with correctly at compile time") {
        REQUIRE(std::is_same_v<decltype(rexx::tests::back::r1), char const&> );
        REQUIRE(std::is_same_v<decltype(rexx::tests::back::r2), const char> );

        REQUIRE(rexx::tests::back::r1 == 'c');
        REQUIRE(rexx::tests::back::r2 == 'c');
    }

    SECTION("ensure lvalue and rvalue expressions are dealth with correctly at runtime") {
        constexpr auto t1 = std::make_tuple(5, 6.0, 'c');
        REQUIRE(rexx::cexpr::back(t1) == 'c');
        REQUIRE(rexx::cexpr::back(std::make_tuple(1,2.0,'c')) == 'c');
    }
}