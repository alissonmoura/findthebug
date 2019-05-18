#pragma once

#include <fstream>
#include <vector>

/**
 * @brief This strcut is used to store the points of the bug
 * 
 */
struct BugPoint
{
  /**
     * @brief Construct a new Bug Point object.
     * 
     * @param row The row where the character is located.
     * @param col The column where the character is located.
     * @param character  The character itself.
     */
  BugPoint(std::size_t const row, std::size_t const col, char const character) : row(row), col(col), character(character) {}

  std::size_t const row;
  std::size_t const col;
  char const character;
};

/**
 * @brief The Pattern that represents the bug
 * 
 */
struct BugPattern
{
  /**
     * @brief Construct a new Bug Pattern object
     * 
     * @param bugpoints All the points that represents the bug
     */
  explicit BugPattern(std::vector<BugPoint> bugpoints) : m_bugpoints(std::move(bugpoints)) {}

  /**
     * @brief The height of the bug related to the amount of rows
     * 
     * @return std::size_t 
     */
  std::size_t height() const noexcept;

  /**
     * @brief the last character of the bug
     * 
     * @return char 
     */
  char last_char() const noexcept;

  /**
     * @brief The last column of the last character
     * 
     * @return std::size_t 
     */
  std::size_t last_char_col() const noexcept;

  /**
     * @brief All the points that represents the bug
     * 
     */
  std::vector<BugPoint> const m_bugpoints;
};

/**
 * @brief Figure out the bug pattern that is contained in the file stream
 * 
 * @param in The file stream of the bug
 * @return BugPattern 
 */
BugPattern find_bugpattern(std::istream &in) noexcept;
