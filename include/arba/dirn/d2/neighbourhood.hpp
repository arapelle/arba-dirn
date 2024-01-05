#pragma once

#include "directions4.hpp"

#include <array>
#include <optional>

inline namespace arba
{
namespace dirn::inline d2
{

template <typename Vec2>
std::optional<Vec2> neighbour(const Vec2& vec, direction4 dir)
{
    switch (dir)
    {
    case directions4::up:
    {
        return Vec2(vec.x(), vec.y() - 1);
    }
    case directions4::right:
    {
        return Vec2(vec.x() + 1, vec.y());
    }
    case directions4::down:
    {
        return Vec2(vec.x(), vec.y() + 1);
    }
    case directions4::left:
    {
        return Vec2(vec.x() - 1, vec.y());
    }
    case directions4::bad_direction:
    case directions4::undefined_direction:
    default:
        return std::nullopt;
    }
}

template <typename Vec2>
Vec2 neighbour(const Vec2& vec, direction4 dir, const Vec2& bad_vec)
{
    std::optional vec_opt = neighbour(vec, dir);
    return vec_opt ? *vec_opt : bad_vec;
}

template <typename dirs, typename Vec2>
std::array<Vec2, dirs::count> neighbours(Vec2 vec)
{
    std::array<Vec2, dirs::count> neighbours;
    for (const auto& dir : dirs::directions)
        neighbours[dir] = *neighbour(vec, dir);
    return neighbours;
}

}
}
