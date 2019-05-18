#pragma once

#include <deque>
#include <iostream>
#include <fstream>
/**
 * @brief It is a buffer that holds exactly the amount of string which is passed in the contructor
 * The main purpose of this buffer is to hold an specific amount of data.
 * When it is full it removes the oldest data pushed before some new data is pushed
 * 
 */
class CircularBuffer
{
public:
  /**
     * @brief Construct a new Circular Buffer object
     * 
     * @param fixed_size The specific amount of string that the object holds
     */
  explicit CircularBuffer(int const fixed_size) : m_fixed_size(fixed_size) {}

  bool is_empty() const noexcept;

  /**
     * @brief Check if it is full according to the fixed_size
     * 
     * @return true 
     * @return false 
     */
  bool is_full() const noexcept;

  /**
     * @brief Push new data to the buffer
     * 
     * @param data 
     * @return std::string* The data pushed is returned so it can be manipulated from outside 
     */
  std::string *push(std::string const &data) noexcept;

  /**
     * @brief The last char of the last line
     * 
     * @return char 
     */
  char last_char() const noexcept;

  /**
     * @brief Check if the is the character in the specific position
     * 
     * @param row 
     * @param col 
     * @param character
     * @return true 
     * @return false 
     */
  bool has_char_at(std::size_t row, std::size_t col, char const &character) const noexcept;

  /**
     * @brief Put a character in the specific position
     * 
     * @param row 
     * @param col 
     * @param character 
     */
  void put_char_at(std::size_t row, std::size_t col, char const &character) noexcept;

  /**
     * @brief Access the string in a specic row
     * 
     * @param index 
     * @return std::string const& 
     */
  std::string const &at(std::size_t index) const;

private:
  bool is_valid_range(int const index) const noexcept;

  std::size_t const m_fixed_size;
  std::deque<std::string> m_container;
};