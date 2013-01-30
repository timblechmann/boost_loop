#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>

#include "../../../boost/loop/loop.hpp"

int test1 = 0;

void runme1(int)
{
    test1 += 1;
}

int test2 = 0;

void runme2()
{
    test2 += 1;
}

BOOST_AUTO_TEST_CASE( loop_test )
{
    boost::loop(10, runme1);
    boost::loop(10, runme2);

    int test3 = 0;
    boost::loop(10, [&](int i) {
        test3 += 1;
    });

    int test4 = 0;
    boost::loop(10, [&]() {
        test4 += 1;
    });

    BOOST_REQUIRE_EQUAL(test1, 10);
    BOOST_REQUIRE_EQUAL(test2, 10);
    BOOST_REQUIRE_EQUAL(test3, 10);
    BOOST_REQUIRE_EQUAL(test4, 10);
}
