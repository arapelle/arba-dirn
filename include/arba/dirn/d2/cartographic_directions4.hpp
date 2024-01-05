#pragma once

#include "directions4_base.hpp"

#include <cassert>
#include <cstdint>
#include <functional>
#include <string_view>

inline namespace arba
{
namespace dirn::inline d2
{

class cartographic_directions4 : public directions4_base
{
public:
    inline static constexpr direction4 north = directions[0];
    inline static constexpr direction4 east = directions[1];
    inline static constexpr direction4 south = directions[2];
    inline static constexpr direction4 west = directions[3];

    inline static char to_char(direction4 dir)
    {
        static constexpr std::string_view chars("?%NESW");
        return chars.at(dir.index() + 2);
    }

    inline static std::string_view to_string_view(direction4 dir)
    {
        static constexpr std::array<std::string_view, count + 2> sv_array{ "Undefined", "Bad",   "North",
                                                                           "East",      "South", "West" };
        return sv_array.at(dir.index() + 2);
    }
};

}
}
