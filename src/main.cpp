#include "landscape.hpp"
#include "fileutil.hpp"

#include <iostream>
#include <string>
#include <vector>

static void show_usage(std::string const &name)
{
    std::cerr << "Usage: " << name << " <bug_file_path> <landscape_file_path>" << std::endl;
}

static int process_cli(std::string const &bug_file_path, std::string const &landscape_file_path)
{
    std::ifstream bug_ifs;
    std::ifstream landscape_ifs;

    try
    {
        bug_ifs = path_to_stream(bug_file_path);
        landscape_ifs = path_to_stream(landscape_file_path);
    }
    catch (std::exception const &e)
    {
        std::cout << "There is a problem in " << e.what() << std::endl;
        return -1;
    }

    BugPattern const &bugpattern = find_bugpattern(bug_ifs);
    Landscape landscape(bugpattern);
    std::size_t bugs = landscape.find_bugs(landscape_ifs);
    std::cout << bugs << std::endl;
    // file is automatically closed when the ifstream object is destroyed.

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        show_usage(argv[0]);
        return -1;
    }

    int isok = process_cli(argv[1], argv[2]);
    return isok;
}