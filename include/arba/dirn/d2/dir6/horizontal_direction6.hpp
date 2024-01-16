#pragma once

#include <arba/dirn/directions_decl.hpp>
#include <arba/dirn/dual_direction.hpp>
#include <arba/dirn/dual_directions_decl.hpp>
#include <arba/dirn/neighborhood.hpp>

inline namespace arba
{
namespace dirn
{
inline namespace d2
{

class horizontal_direction6 : public dual_direction<6, horizontal_direction6>
{
private:
    using base_ = dual_direction<6, horizontal_direction6>;

public:
    using typename base_::int_type;

    inline constexpr horizontal_direction6() : base_() {}

    inline constexpr auto operator<=>(const horizontal_direction6& rhs) const { return this->index() <=> rhs.index(); }

protected:
    inline constexpr explicit horizontal_direction6(int_type value) : base_(value) {}

private:
    friend direction<6, horizontal_direction6>;
    friend dual_direction<6, horizontal_direction6>;

    friend class directions<horizontal_direction6>;
    friend class dual_directions<horizontal_direction6>;
    friend class horizontal_directions6;
};

}

template <class Vec2>
class neighborhood<d2::horizontal_direction6, Vec2>
{
public:
    using direction = d2::horizontal_direction6;
    using vec2 = Vec2;
    using neighbors_array = std::array<vec2, direction::cardinality>;

    static const neighbors_array even_offsets;
    static const neighbors_array odd_offsets;

    static vec2 neighbor(const vec2& vec, direction dir)
    {
        assert(dir.is_valid());
        if ((vec.y() & 1) == 0)
            return vec + even_offsets[dir];
        return vec + odd_offsets[dir];
    }

    static auto neighbors(const vec2& vec)
    {
        if ((vec.y() & 1) == 0)
            return std::array{ vec + even_offsets[0], vec + even_offsets[1], vec + even_offsets[2],
                               vec + even_offsets[3], vec + even_offsets[4], vec + even_offsets[5] };
        else
            return std::array{ vec + odd_offsets[0], vec + odd_offsets[1], vec + odd_offsets[2],
                               vec + odd_offsets[3], vec + odd_offsets[4], vec + odd_offsets[5] };
    }

    static void neighbors(const vec2& vec, std::array<vec2, direction::cardinality>& neighbors)
    {
        auto iter = ((vec.y() & 1) == 0) ? even_offsets.cbegin() : odd_offsets.cbegin();
        for (auto& neighbor : neighbors)
        {
            neighbor = vec + (*iter);
            ++iter;
        }
    }
};

template <class Vec2>
const typename neighborhood<d2::horizontal_direction6, Vec2>::neighbors_array
    neighborhood<d2::horizontal_direction6, Vec2>::even_offsets = { Vec2(-1, 0), Vec2(-1, -1), Vec2(0, -1),
                                                                    Vec2(1, 0),  Vec2(0, 1),   Vec2(-1, 1) };

template <class Vec2>
const typename neighborhood<d2::horizontal_direction6, Vec2>::neighbors_array
    neighborhood<d2::horizontal_direction6, Vec2>::odd_offsets = { Vec2(-1, 0), Vec2(0, -1), Vec2(1, -1),
                                                                   Vec2(1, 0),  Vec2(1, 1),  Vec2(0, 1) };

}
}

template <>
struct std::hash<::arba::dirn::d2::horizontal_direction6>
    : public std::hash<::arba::dirn::dual_direction<6, ::arba::dirn::d2::horizontal_direction6>>
{
};
