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

class direction8 : public dual_direction<8, direction8>
{
private:
    using base_ = dual_direction<8, direction8>;

public:
    using typename base_::int_type;

    inline constexpr direction8() : base_() {}

    inline constexpr auto operator<=>(const direction8& rhs) const { return this->index() <=> rhs.index(); }

protected:
    inline constexpr explicit direction8(int_type value) : base_(value) {}

private:
    friend direction<8, direction8>;
    friend dual_direction<8, direction8>;

    friend class directions<direction8>;
    friend class dual_directions<direction8>;
    friend class directions8;
};

}

template <class Vec2>
class neighborhood<d2::direction8, Vec2>
{
public:
    using direction = d2::direction8;
    using vec2 = Vec2;
    using neighbors_array = std::array<vec2, direction::cardinality>;

    static const neighbors_array offsets;

    static vec2 neighbor(const vec2& vec, direction dir)
    {
        assert(dir.is_valid());
        return vec + offsets[dir];
    }

    static auto neighbors(const vec2& vec)
    {
        return std::array{ vec + offsets[0], vec + offsets[1], vec + offsets[2], vec + offsets[3],
                           vec + offsets[4], vec + offsets[5], vec + offsets[6], vec + offsets[7] };
    }

    static void neighbors(const vec2& vec, std::array<vec2, direction::cardinality>& neighbors)
    {
        auto iter = offsets.cbegin();
        for (auto& neighbor : neighbors)
        {
            neighbor = vec + (*iter);
            ++iter;
        }
    }
};

template <class Vec2>
const typename neighborhood<d2::direction8, Vec2>::neighbors_array neighborhood<d2::direction8, Vec2>::offsets = {
    Vec2(0, -1), Vec2(1, -1), Vec2(1, 0), Vec2(1, 1), Vec2(0, 1), Vec2(-1, 1), Vec2(-1, 0), Vec2(-1, -1)
};

}
}

template <>
struct std::hash<::arba::dirn::d2::direction8>
    : public std::hash<::arba::dirn::dual_direction<8, ::arba::dirn::d2::direction8>>
{
};
