#pragma once

#include "horizontal_direction6.hpp"

#include <arba/dirn/dual_directions.hpp>
#include <string_view>

inline namespace arba
{
namespace dirn::inline d2
{

class horizontal_directions6 : public dual_directions<horizontal_direction6>
{
private:
    using base_ = dual_directions<horizontal_direction6>;

public:
    using typename base_::direction;

public:
    inline static constexpr direction left = base_::valid_directions[0];
    inline static constexpr direction left_up = base_::valid_directions[1];
    inline static constexpr direction right_up = base_::valid_directions[2];
    inline static constexpr direction right = base_::valid_directions[3];
    inline static constexpr direction right_down = base_::valid_directions[4];
    inline static constexpr direction left_down = base_::valid_directions[5];

    inline static char to_char(direction dir)
    {
        static constexpr std::string_view chars("?%LUVRBD");
        return chars.at(dir.index() + 2);
    }

    inline static std::string_view to_short_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{ "~?", "~%", "LE", "LU",
                                                                                        "RU", "RI", "RD", "LD" };
        return sv_array.at(dir.index() + 2);
    }

    inline static std::string_view to_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{
            "undefined", "bad", "left", "left_up", "right_up", "right", "right_down", "left_down"
        };
        return sv_array.at(dir.index() + 2);
    }
};

}
}
