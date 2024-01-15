#pragma once

#include "direction8.hpp"

#include <arba/dirn/dual_directions.hpp>
#include <string_view>

inline namespace arba
{
namespace dirn::inline d2
{

class cartographic_directions8 : public dual_directions<direction8>
{
private:
    using base_ = dual_directions<direction8>;

public:
    using typename base_::direction;

public:
    inline static constexpr direction north = base_::valid_directions[0];
    inline static constexpr direction north_east = base_::valid_directions[1];
    inline static constexpr direction east = base_::valid_directions[2];
    inline static constexpr direction south_east = base_::valid_directions[3];
    inline static constexpr direction south = base_::valid_directions[4];
    inline static constexpr direction south_west = base_::valid_directions[5];
    inline static constexpr direction west = base_::valid_directions[6];
    inline static constexpr direction north_west = base_::valid_directions[7];

    inline static std::string_view to_short_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{ "~?", "~%", "NO", "NE", "EA",
                                                                                        "SE", "SO", "SW", "WE", "NW" };
        return sv_array.at(dir.index() + 2);
    }

    inline static std::string_view to_string_view(direction dir)
    {
        static constexpr std::array<std::string_view, base_::cardinality + 2> sv_array{
            "undefined", "bad", "north", "north_east", "east", "south_east", "south", "south_west", "west", "north_west"
        };
        return sv_array.at(dir.index() + 2);
    }
};

}
}
