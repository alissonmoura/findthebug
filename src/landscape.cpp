#include "landscape.hpp"

#include <algorithm>
#include <iostream>

int Landscape::find_bugs(std::istream &in) const noexcept
{
    char const breakline = '\n';
    std::size_t number_of_bugs = 0;
    char current_char;

    //Used a circular buffer to save memory.
    CircularBuffer circbuf(m_bugpattern.height());
    std::string *current_line = circbuf.push(std::string{});

    while (in.get(current_char))
    {
        if (current_char == breakline)
        {
            current_line = circbuf.push(std::string{});
            continue;
        }
        current_line->push_back(current_char);

        int last_line_col = current_line->size() - 1;
        if (circbuf.is_full() && verify_bug(circbuf, last_line_col))
        {
            ++number_of_bugs;
        }
    }
    return number_of_bugs;
}

bool Landscape::verify_bug(CircularBuffer &circbuf, int const col) const noexcept
{
    char current_char = circbuf.last_char();
    if (current_char == m_bugpattern.last_char())
    {
        if (std::all_of(m_bugpattern.m_bugpoints.cbegin(),
                        m_bugpattern.m_bugpoints.cend(),
                        [&](BugPoint const &bugpoint) {
                            int offset = col - m_bugpattern.last_char_col();
                            if (offset >= 0)
                            {
                                // comparing from the most left to the right
                                return circbuf.has_char_at(bugpoint.row, offset + bugpoint.col, bugpoint.character);
                            }
                            else
                            {
                                return false;
                            }
                        }))
        {
            //it is done to avoid overlapped bugs to be considered different
            clear_bug(circbuf, col);
            return true;
        }
    }
    return false;
}

void Landscape::clear_bug(CircularBuffer &circbuf, int const col) const noexcept
{
    for (auto &bugpoint : m_bugpattern.m_bugpoints)
    {
        int offset = col - m_bugpattern.last_char_col();
        if (offset >= 0)
        {
            // from the most left to the right
            circbuf.put_char_at(bugpoint.row, offset + bugpoint.col, ' ');
        }
    }
}