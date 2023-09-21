#pragma once

#include "directions4_base.hpp"
#include <string_view>
#include <functional>
#include <cstdint>
#include <cassert>

inline namespace arba
{
namespace dirn:: inline d2
{

class directions4 : public directions4_base
{
public:
    inline static constexpr direction4 up = directions[0];
    inline static constexpr direction4 right = directions[1];
    inline static constexpr direction4 down = directions[2];
    inline static constexpr direction4 left = directions[3];

    inline static char to_char(direction4 dir)
    {
        static constexpr std::string_view chars("?%URDL");
        return chars.at(dir.index() + 2);
    }

    inline static std::string_view to_string_view(direction4 dir)
    {
        static constexpr std::array<std::string_view, count + 2> sv_array{ "Undefined", "Bad", "Up", "Right", "Down", "Left" };
        return sv_array.at(dir.index() + 2);
    }
};

}
}
