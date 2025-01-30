#pragma once

#include "direction8.hpp"
#include <arba/dirn/dual_directions.hpp>

#include <string_view>

inline namespace arba
{
namespace dirn::inline d2
{

class directions8 : public dual_directions<direction8>
{
private:
    using base_ = dual_directions<direction8>;

public:
    using typename base_::direction;

public:
    inline static constexpr direction up = base_::valid_directions[0];
    inline static constexpr direction up_right = base_::valid_directions[1];
    inline static constexpr direction right = base_::valid_directions[2];
    inline static constexpr direction down_right = base_::valid_directions[3];
    inline static constexpr direction down = base_::valid_directions[4];
    inline static constexpr direction down_left = base_::valid_directions[5];
    inline static constexpr direction left = base_::valid_directions[6];
    inline static constexpr direction up_left = base_::valid_directions[7];

    inline static std::string_view to_short_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{ "~?", "~%", "UP", "UR", "RI",
                                                                                        "DR", "DN", "DL", "LE", "UL" };
        return sv_array.at(dir.index() + 2);
    }

    inline static std::string_view to_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{
            "undefined", "bad", "up", "up_right", "right", "down_right", "down", "down_left", "left", "up_left"
        };
        return sv_array.at(dir.index() + 2);
    }
};

} // namespace dirn::inline d2
} // namespace arba
