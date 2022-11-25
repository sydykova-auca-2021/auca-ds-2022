#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <sstream>
#include <string>
#include <stdexcept>
#include <ctype.h>
#include <vector>

#include "BigInt.hpp"
using namespace std;

TEST_CASE("Default constructor")
{
    BigInt x;
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0");

    vector<BigInt> v(5);
    for (const auto &e : v)
    {
        ostringstream sout2;
        sout2 << e;
        REQUIRE(sout2.str() == "0");
    }
}
TEST_CASE("Constructor with a string parameter")
{
    ostringstream sout;
    SUBCASE("positive number")
    {
        BigInt x("122344556");
        sout << x;
        REQUIRE(sout.str() == "122344556");
    }
    SUBCASE("negative number")
    {
        BigInt x("-1234");
        sout << x;
        REQUIRE(sout.str() == "-1234");
    }
    SUBCASE("number with sign")
    {
        BigInt x("-123");
        sout << x;
        REQUIRE(sout.str() == "-123");

        sout.str("");
        BigInt y("+123");
        sout << y;
        REQUIRE(sout.str() == "123");

        // sout.str("");
        // BigInt z("-0");
        // sout << z;
        // REQUIRE(sout.str() == "0");
    }

    // SUBCASE("leading zeroes")
    // {
    //     BigInt x("-0000123");
    //     sout << x;
    //     REQUIRE(sout.str() == "-123");

    //     sout.str("");
    //     BigInt y("+00000000");
    //     sout << y;
    //     REQUIRE(sout.str() == "0");
    // }
    // SUBCASE("just sign")
    // {
    //     REQUIRE_THROWS_AS(BigInt("+"), runtime_error);
    //     REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    // }
    SUBCASE("empty space")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
        REQUIRE_THROWS_WITH(BigInt(""), "Cannot be empty");
    }
    SUBCASE("String containning letters")
    {
        REQUIRE_THROWS_AS(BigInt("12hjgjhgyj3"), runtime_error);
    }
    SUBCASE("Invalid string with spaces")
    {
        REQUIRE_THROWS_AS(BigInt("123 456"), runtime_error);
    }
}

TEST_CASE("Constructor with int parameter")
{
    ostringstream sout;
    SUBCASE("positive int")
    {
        BigInt x(12345);
        sout << x;
        REQUIRE(sout.str() == "12345");
    }
}
