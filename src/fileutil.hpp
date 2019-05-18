#pragma once

#include <fstream>

/**
 * @brief transform strin to ifstream and returning it by moving the data
 * 
 * @param file_path 
 * @return std::ifstream 
 */
std::ifstream path_to_stream(std::string const &file_path);
