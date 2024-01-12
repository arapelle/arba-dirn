#pragma once

#include <arba/dirn/dual_directions.hpp>
#include "direction4.hpp"

#include <string_view>

inline namespace arba
{
namespace dirn::inline d2
{

class directions4 : public dual_directions<direction4>
{
private:
    using base_ = dual_directions<direction4>;

public:
    using typename base_::direction;

public:
    inline static constexpr direction up = base_::valid_directions[0];
    inline static constexpr direction right = base_::valid_directions[1];
    inline static constexpr direction down = base_::valid_directions[2];
    inline static constexpr direction left = base_::valid_directions[3];

    inline static char to_char(direction dir)
    {
        static constexpr std::string_view chars("?%URDL");
        return chars.at(dir.index() + 2);
    }

    inline static std::string_view to_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{ "undefined", "bad",  "up",
                                                                                        "right",     "down", "left" };
        return sv_array.at(dir.index() + 2);
    }
};

}
}
