#pragma once

#include "bug.hpp"
#include "container.hpp"

#include <vector>
#include <fstream>

/**
 * @brief The Landscape where the bugs will be placed
 * 
 */
class Landscape
{
public:
  /**
     * @brief Construct a new Landscape object
     * 
     * @param bugpattern It will be used as a pattern of the bugs that might be present.
     */
  explicit Landscape(BugPattern const &bugpattern)
      : m_bugpattern(bugpattern) {}

  /**
     * @brief Figure out how many bugs are placed in the Landscape
     * 
     * @param in The file stream representation of the landscape
     * @return int The amount of bugs
     */
  int find_bugs(std::istream &in) const noexcept;

private:
  /**
     * @brief Verify if the is a bug at the specific column in the buffer
     * 
     * @param circbuf 
     * @param last_line_col 
     * @return true 
     * @return false 
     */
  bool verify_bug(CircularBuffer &circbuf, int const col) const noexcept;

  /**
     * @brief Clear bug at the specific column in the buffer
     * 
     * @param circbuf 
     * @param col 
     */
  void clear_bug(CircularBuffer &circbuf, int const col) const noexcept;

  /**
     * @brief It will be used as a pattern of the bugs that might be present.
     * 
     */
  BugPattern const m_bugpattern;
};
