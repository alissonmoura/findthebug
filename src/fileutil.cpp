#include "fileutil.hpp"

std::ifstream path_to_stream(std::string const &file_path)
{
    std::ifstream ifs(file_path, std::ifstream::in);
    if (!ifs.good())
    {
        throw std::runtime_error(file_path);
    }
    return ifs;
}
