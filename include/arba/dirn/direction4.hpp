#pragma once

#include "direction.hpp"
#include <string_view>
#include <functional>
#include <cstdint>
#include <cassert>

inline namespace arba
{
namespace dirn
{

class direction4
{
public:
    using IT = int8_t;

private:
    inline static constexpr std::size_t count_ = 4;
    inline static constexpr std::size_t opposed_offset_ = count_ / 2;
    inline static constexpr std::size_t left_offset_ = opposed_offset_ + 1;
    inline static constexpr std::size_t right_offset_ = opposed_offset_ - 1;
    inline static constexpr IT first_valid_value_ = 0;
    inline static constexpr IT bad_value_ = first_valid_value_ - 1;
    inline static constexpr IT undefined_value_ = bad_value_ - 1;

public:
    inline constexpr bool is_valid() const { return value_ >= first_valid_value_; }
    inline constexpr bool is_bad() const { return value_ == bad_value_; }
    inline constexpr bool is_undefined() const { return value_ == undefined_value_; }
    inline constexpr bool is_defined() const { return value_ > undefined_value_; }

    inline constexpr auto operator<=>(const direction4& rhs) const = default;

    inline constexpr direction4 opposed() const { assert(is_valid()); return direction4((value_ + opposed_offset_) % count_); }
    inline constexpr direction4 left() const { assert(is_valid()); return direction4((value_ + left_offset_) % count_); }
    inline constexpr direction4 right() const { assert(is_valid()); return direction4((value_ + right_offset_) % count_); }

    inline constexpr IT index() const { return value_; }
    inline constexpr operator IT() const { return value_; }

private:
    inline constexpr explicit direction4(IT value) : value_(value) {}
    inline constexpr explicit direction4(priv::bad_direction) : value_(bad_value_) {}
    inline constexpr explicit direction4(priv::undefined_direction) : value_(undefined_value_) {}

private:
    friend class directions4_base;

    IT value_;
};

}
}

namespace std
{
template<>
struct hash< ::arba::dirn::direction4>
{
    inline std::size_t operator()(const ::arba::dirn::direction4& dir) const noexcept
    {
        return static_cast<std::size_t>(dir.index());
    }
};
}
