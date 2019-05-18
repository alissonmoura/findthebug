#define CATCH_CONFIG_MAIN

#include "bug.hpp"
#include "fileutil.hpp"

#include <catch.hpp>

TEST_CASE("bug.txt", "BugParser")
{
    std::ifstream ifs = path_to_stream("../../tests/res/bug.txt");
    BugPattern bugpattern = find_bugpattern(ifs);

    SECTION("parse")
    {
        REQUIRE(bugpattern.m_bugpoints[0].col == 0);
        REQUIRE(bugpattern.m_bugpoints[0].row == 0);
        REQUIRE(bugpattern.m_bugpoints[0].character == '|');

        REQUIRE(bugpattern.m_bugpoints[1].col == 2);
        REQUIRE(bugpattern.m_bugpoints[1].row == 0);
        REQUIRE(bugpattern.m_bugpoints[1].character == '|');

        REQUIRE(bugpattern.m_bugpoints[2].col == 0);
        REQUIRE(bugpattern.m_bugpoints[2].row == 1);
        REQUIRE(bugpattern.m_bugpoints[2].character == '#');

        REQUIRE(bugpattern.m_bugpoints[3].col == 1);
        REQUIRE(bugpattern.m_bugpoints[3].row == 1);
        REQUIRE(bugpattern.m_bugpoints[3].character == '#');

        REQUIRE(bugpattern.m_bugpoints[4].col == 2);
        REQUIRE(bugpattern.m_bugpoints[4].row == 1);
        REQUIRE(bugpattern.m_bugpoints[4].character == '#');

        REQUIRE(bugpattern.m_bugpoints[5].col == 3);
        REQUIRE(bugpattern.m_bugpoints[5].row == 1);
        REQUIRE(bugpattern.m_bugpoints[5].character == 'O');

        REQUIRE(bugpattern.m_bugpoints[6].col == 0);
        REQUIRE(bugpattern.m_bugpoints[6].row == 2);
        REQUIRE(bugpattern.m_bugpoints[6].character == '|');

        REQUIRE(bugpattern.m_bugpoints[7].col == 2);
        REQUIRE(bugpattern.m_bugpoints[7].row == 2);
        REQUIRE(bugpattern.m_bugpoints[7].character == '|');
    }

    SECTION("first char of last line")
    {
        REQUIRE(bugpattern.last_char() == '|');
    }

    SECTION("height")
    {
        REQUIRE(bugpattern.height() == 3);
    }
}

TEST_CASE("bug_first_line_blank.txt", "BugParser")
{
    std::ifstream ifs = path_to_stream("../../tests/res/bug_first_line_blank.txt");
    BugPattern bugpattern = find_bugpattern(ifs);

    SECTION("parse")
    {
        REQUIRE(bugpattern.m_bugpoints[0].col == 0);
        REQUIRE(bugpattern.m_bugpoints[0].row == 1);
        REQUIRE(bugpattern.m_bugpoints[0].character == '|');

        REQUIRE(bugpattern.m_bugpoints[1].col == 2);
        REQUIRE(bugpattern.m_bugpoints[1].row == 1);
        REQUIRE(bugpattern.m_bugpoints[1].character == '|');

        REQUIRE(bugpattern.m_bugpoints[2].col == 0);
        REQUIRE(bugpattern.m_bugpoints[2].row == 2);
        REQUIRE(bugpattern.m_bugpoints[2].character == '#');

        REQUIRE(bugpattern.m_bugpoints[3].col == 1);
        REQUIRE(bugpattern.m_bugpoints[3].row == 2);
        REQUIRE(bugpattern.m_bugpoints[3].character == '#');

        REQUIRE(bugpattern.m_bugpoints[4].col == 2);
        REQUIRE(bugpattern.m_bugpoints[4].row == 2);
        REQUIRE(bugpattern.m_bugpoints[4].character == '#');

        REQUIRE(bugpattern.m_bugpoints[5].col == 3);
        REQUIRE(bugpattern.m_bugpoints[5].row == 2);
        REQUIRE(bugpattern.m_bugpoints[5].character == 'O');

        REQUIRE(bugpattern.m_bugpoints[6].col == 0);
        REQUIRE(bugpattern.m_bugpoints[6].row == 3);
        REQUIRE(bugpattern.m_bugpoints[6].character == '|');

        REQUIRE(bugpattern.m_bugpoints[7].col == 2);
        REQUIRE(bugpattern.m_bugpoints[7].row == 3);
        REQUIRE(bugpattern.m_bugpoints[7].character == '|');
    }

    SECTION("first char of last line")
    {
        REQUIRE(bugpattern.last_char() == '|');
    }

    SECTION("height")
    {
        REQUIRE(bugpattern.height() == 4);
    }
}
