#pragma once

#include "direction4.hpp"
#include <arba/dirn/dual_directions.hpp>

#include <string_view>

inline namespace arba
{
namespace dirn::inline d2
{

class cartographic_directions4 : public dual_directions<direction4>
{
private:
    using base_ = dual_directions<direction4>;

public:
    using typename base_::direction;

public:
    inline static constexpr direction north = base_::valid_directions[0];
    inline static constexpr direction east = base_::valid_directions[1];
    inline static constexpr direction south = base_::valid_directions[2];
    inline static constexpr direction west = base_::valid_directions[3];

    inline static char to_char(direction dir)
    {
        static constexpr std::string_view chars("?%NESW");
        return chars.at(dir.index() + 2);
    }

    inline static std::string_view to_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{ "undefined", "bad",   "north",
                                                                                        "east",      "south", "west" };
        return sv_array.at(dir.index() + 2);
    }
};

} // namespace dirn::inline d2
} // namespace arba
