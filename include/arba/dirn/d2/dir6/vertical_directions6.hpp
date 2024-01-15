#pragma once

#include <arba/dirn/dual_directions.hpp>
#include "vertical_direction6.hpp"

#include <string_view>

inline namespace arba
{
namespace dirn::inline d2
{

class vertical_directions6 : public dual_directions<vertical_direction6>
{
private:
    using base_ = dual_directions<vertical_direction6>;

public:
    using typename base_::direction;

public:
    inline static constexpr direction up = base_::valid_directions[0];
    inline static constexpr direction up_right = base_::valid_directions[1];
    inline static constexpr direction down_right = base_::valid_directions[2];
    inline static constexpr direction down = base_::valid_directions[3];
    inline static constexpr direction down_left = base_::valid_directions[4];
    inline static constexpr direction up_left = base_::valid_directions[5];

    inline static char to_char(direction dir)
    {
        static constexpr std::string_view chars("?%URKDJL");
        return chars.at(dir.index() + 2);
    }

    inline static std::string_view to_short_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{
            "~?", "%~", "UP", "UR", "DR", "DN", "DL", "UL"
        };
        return sv_array.at(dir.index() + 2);
    }

    inline static std::string_view to_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{
            "UNDEFINED", "BAD", "UP", "UP_RIGHT", "DOWN_RIGHT", "DOWN", "DOWN_LEFT", "UP_LEFT"
        };
        return sv_array.at(dir.index() + 2);
    }
};

}
}
