#define CATCH_CONFIG_MAIN

#include "landscape.hpp"
#include "fileutil.hpp"

#include <catch.hpp>

TEST_CASE("landscape", "Landscape")
{
    std::ifstream bug_ifs = path_to_stream("../../tests/res/bug.txt");
    BugPattern const &bugpattern = find_bugpattern(bug_ifs);
    Landscape landscape(bugpattern);

    SECTION("basic test")
    {
        std::ifstream landscape_ifs = path_to_stream("../../tests/res/landscape.txt");
        std::size_t bugs = landscape.find_bugs(landscape_ifs);
        REQUIRE(bugs == 3);
    }

    SECTION("test corners")
    {
        std::ifstream landscape_ifs = path_to_stream("../../tests/res/landscape_corners.txt");
        std::size_t bugs = landscape.find_bugs(landscape_ifs);
        REQUIRE(bugs == 4);
    }

    SECTION("test close but not the same")
    {
        std::ifstream landscape_ifs = path_to_stream("../../tests/res/landscape_close.txt");
        std::size_t bugs = landscape.find_bugs(landscape_ifs);
        REQUIRE(bugs == 3);
    }

    SECTION("test overllaped")
    {
        std::ifstream landscape_ifs = path_to_stream("../../tests/res/landscape_overlapped.txt");
        std::size_t bugs = landscape.find_bugs(landscape_ifs);
        REQUIRE(bugs == 1);
    }
}

TEST_CASE("landscape bug other", "Landscape")
{
    std::ifstream bug_ifs = path_to_stream("../../tests/res/bug_other.txt");
    BugPattern const &bugpattern = find_bugpattern(bug_ifs);
    Landscape landscape(bugpattern);

    SECTION("test corners")
    {
        std::ifstream landscape_ifs = path_to_stream("../../tests/res/landscape_bug_other.txt");
        std::size_t bugs = landscape.find_bugs(landscape_ifs);
        REQUIRE(bugs == 4);
    }
}