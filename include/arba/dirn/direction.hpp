#pragma once

#include <cassert>
#include <cstdint>
#include <functional>

inline namespace arba
{
namespace dirn
{
namespace priv
{

class bad_direction
{
};

class undefined_direction
{
};

enum invalid_direction_ : int8_t
{
    bad_direction_ = -1,
    undefined_direction_ = bad_direction_ - 1,
};

}

template <std::size_t DirCount, class SelfType>
    requires(DirCount > 0)
class direction
{
public:
    using int_type = int8_t;
    using self_type = SelfType;

    inline static constexpr std::size_t cardinality = DirCount;

private:
    inline static constexpr std::size_t left_offset_ = cardinality - 1;

public:
    inline constexpr bool is_valid() const { return value_ >= 0; }
    inline constexpr bool is_bad() const { return value_ == priv::invalid_direction_::bad_direction_; }
    inline constexpr bool is_undefined() const { return value_ == priv::invalid_direction_::undefined_direction_; }
    inline constexpr bool is_defined() const { return value_ > priv::invalid_direction_::undefined_direction_; }

    inline constexpr int_type index() const { return value_; }
    inline constexpr operator int_type() const { return value_; }

    inline constexpr self_type left_direction() const
    {
        assert(this->is_valid());
        return self_type((this->value_ + left_offset_) % this->cardinality);
    }

    inline constexpr void turn_left()
    {
        assert(this->is_valid());
        this->value_ += left_offset_;
        this->value_ %= this->cardinality;
    }

    inline constexpr self_type right_direction() const
    {
        assert(this->is_valid());
        return self_type((this->value_ + 1) % this->cardinality);
    }

    inline constexpr void turn_right()
    {
        assert(this->is_valid());
        ++this->value_ %= this->cardinality;
    }

    inline constexpr std::array<self_type, cardinality - 1> other_directions() const
    {
        assert(this->is_valid());
        std::array<self_type, cardinality - 1> dirs;
        int_type i = 0;
        auto iter = dirs.begin();
        for (auto end_iter = iter + value_; iter != end_iter; ++iter)
            *iter = self_type(i++);
        ++i;
        for (auto end_iter = dirs.end(); iter != end_iter; ++iter)
            *iter = self_type(i++);
        return dirs;
    }

    inline constexpr direction() : value_(priv::invalid_direction_::undefined_direction_) {}

protected:
    inline constexpr explicit direction(int_type value) : value_(value) {}

protected:
    int_type value_;
};

}
}

namespace std
{
template <std::size_t DirCount, class SelfType>
struct hash<::arba::dirn::direction<DirCount, SelfType>>
{
    inline std::size_t operator()(const ::arba::dirn::direction<DirCount, SelfType>& dir) const noexcept
    {
        return static_cast<std::size_t>(dir.index());
    }
};
}
