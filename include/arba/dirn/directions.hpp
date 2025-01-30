#pragma once

#include "direction.hpp"
#include "directions_decl.hpp"

#include <cassert>
#include <cstdint>

inline namespace arba
{
namespace dirn
{

template <class DirectionType>
class directions
{
public:
    using direction = DirectionType;

    inline static constexpr std::size_t cardinality = direction::cardinality;

private:
    inline static constexpr std::array<direction, cardinality> directions_()
    {
        std::array<direction, cardinality> dirs;
        for (std::size_t i = 0; i < cardinality; ++i)
            dirs[i] = direction(i);
        return dirs;
    }

public:
    inline static constexpr direction bad_direction = direction(priv::bad_direction_);
    inline static constexpr direction undefined_direction = direction(priv::undefined_direction_);

    inline static constexpr std::array<direction, cardinality> valid_directions = directions_();

    inline static constexpr direction nth(std::size_t index)
    {
        assert(index < cardinality);
        return valid_directions[index];
    }
};

} // namespace dirn
} // namespace arba
