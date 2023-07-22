#pragma once

#include "direction4.hpp"

namespace dirn
{
class directions4_base
{
public:
    inline static constexpr std::size_t count = direction4::count_;
    inline static constexpr direction4 bad_direction = direction4(priv::bad_direction{});
    inline static constexpr direction4 undefined_direction = direction4(priv::undefined_direction{});

    inline static constexpr std::array<direction4, count> directions{ direction4(0), direction4(1), direction4(2), direction4(3) };
    inline static constexpr std::array<direction4, count> opposed_directions{ direction4(2), direction4(3), direction4(0), direction4(1) };

    inline static constexpr std::array<direction4, count - 1> other_directions(const direction4& dir)
    {
        return std::array<direction4, count - 1>{ dir.opposed(), dir.left(), dir.right() };
    }

    inline static constexpr direction4 nth(std::size_t index) { assert(index < count); return directions[index]; }
};
}
