#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <sstream>

#include "BigInt.hpp"

using namespace std;

TEST_CASE("Default constructor")
{
    BigInt x;
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0");

    vector<BigInt> v(10);
    for (const auto &e : v)
    {
        ostringstream sout2;
        sout2 << e;
        REQUIRE(sout2.str() == "0");
    }
};

TEST_CASE("Constructor with a string parameter")
{
    ostringstream sout;

    SUBCASE("Just long correct positive number")
    {
        BigInt x("123123123");
        sout << x;
        REQUIRE(sout.str() == "123123123");
    }

};
