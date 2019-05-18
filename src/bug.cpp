#include "bug.hpp"

#include <algorithm>

BugPattern find_bugpattern(std::istream &in) noexcept
{
    char const whitespace = ' ';
    char const breakline = '\n';
    std::vector<BugPoint> bugpoints;

    size_t row = 0;
    size_t col = 0;
    char current_char;

    while (in.get(current_char))
    {
        if (current_char == breakline)
        {
            col = 0;
            ++row;
            continue;
        }

        if (current_char != whitespace)
        {
            bugpoints.emplace_back(BugPoint(row, col, current_char));
        }
        ++col;
    }

    return BugPattern(bugpoints);
}

std::size_t BugPattern::height() const noexcept
{
    if (m_bugpoints.empty())
    {
        return 0;
    }
    else
    {
        //since it starts from 0 it is necessary to add 1
        return (m_bugpoints.back().row + 1);
    }
}

char BugPattern::last_char() const noexcept
{
    if (m_bugpoints.empty())
    {
        return 0;
    }
    else
    {
        return m_bugpoints.back().character;
    }
}

std::size_t BugPattern::last_char_col() const noexcept
{
    if (m_bugpoints.empty())
    {
        return 0;
    }
    else
    {
        return m_bugpoints.back().col;
    }
}
