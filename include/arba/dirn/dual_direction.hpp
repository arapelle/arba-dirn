#pragma once

#include "direction.hpp"

#include <cassert>
#include <compare>
#include <cstdint>

inline namespace arba
{
namespace dirn
{

template <std::size_t DirCount, class SelfType>
    requires((DirCount & 1) == 0)
class dual_direction : public direction<DirCount, SelfType>
{
private:
    using base_ = direction<DirCount, SelfType>;

public:
    using typename base_::int_type;
    using typename base_::self_type;

private:
    inline static constexpr std::size_t opposed_offset_ = base_::cardinality / 2;

public:
    inline constexpr self_type opposed_direction() const
    {
        assert(this->is_valid());
        return self_type((this->value_ + this->opposed_offset_) % this->cardinality);
    }

    inline constexpr dual_direction() : base_() {}

protected:
    inline constexpr explicit dual_direction(int_type value) : base_(value) {}
};

} // namespace dirn
} // namespace arba

template <std::size_t DirCount, class SelfType>
struct std::hash<::arba::dirn::dual_direction<DirCount, SelfType>>
    : public std::hash<::arba::dirn::direction<DirCount, SelfType>>
{
};
