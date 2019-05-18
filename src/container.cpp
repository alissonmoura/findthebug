#include "container.hpp"

bool CircularBuffer::is_empty() const noexcept
{
    return m_container.empty();
}

bool CircularBuffer::is_full() const noexcept
{
    return m_container.size() == m_fixed_size;
}

std::string *CircularBuffer::push(std::string const &data) noexcept
{
    if (is_full())
    {
        m_container.pop_front();
    }
    m_container.push_back(data);
    return &m_container.back();
}

char CircularBuffer::last_char() const noexcept
{
    if (m_container.empty())
    {
        return 0;
    }
    else
    {
        std::string const &last_line = m_container.back();
        return last_line.back();
    }
}

bool CircularBuffer::has_char_at(std::size_t row, std::size_t col, char const &character) const noexcept
{
    if (is_valid_range(row))
    {
        std::string const &line = m_container[row];
        return line.size() > col && line[col] == character;
    }
    else
    {
        return false;
    }
}

void CircularBuffer::put_char_at(std::size_t row, std::size_t col, char const &character) noexcept
{
    if (is_valid_range(row))
    {
        std::string &line = m_container[row];
        if (line.size() > col)
        {
            line[col] = character;
        }
    }
}

std::string const &CircularBuffer::at(std::size_t index) const
{
    return m_container.at(index);
}

bool CircularBuffer::is_valid_range(int const index) const noexcept
{
    return index >= 0 && (std::size_t)index < m_container.size();
}