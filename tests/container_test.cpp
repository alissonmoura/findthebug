#define CATCH_CONFIG_MAIN

#include "container.hpp"

#include <catch.hpp>

TEST_CASE("push", "CircularBuffer")
{
    CircularBuffer circ_buffer(3);
    circ_buffer.push("a");
    circ_buffer.push("b");
    circ_buffer.push("c");

    SECTION("check full")
    {
        REQUIRE(circ_buffer.is_full());
    }

    SECTION("check elements")
    {
        REQUIRE(circ_buffer.at(0) == "a");
        REQUIRE(circ_buffer.at(1) == "b");
        REQUIRE(circ_buffer.at(2) == "c");
    }

    circ_buffer.push("d");

    SECTION("check elements + 1")
    {
        REQUIRE(circ_buffer.at(0) == "b");
        REQUIRE(circ_buffer.at(1) == "c");
        REQUIRE(circ_buffer.at(2) == "d");
    }
}
