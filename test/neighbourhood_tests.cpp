#include <arba/dirn/d2/neighbourhood.hpp>
#include <cstdlib>
#include <gtest/gtest.h>

class vec2
{
    int x_;
    int y_;

public:
    vec2(int x = 0, int y = 0) : x_(x), y_(y) {}

    const int& x() const { return x_; }
    int& x() { return x_; }

    const int& y() const { return y_; }
    int& y() { return y_; }

    auto operator<=>(const vec2& v) const = default;
};

TEST(neighbourhood_tests, neighbour)
{
    vec2 vec(10, 0);
    ASSERT_EQ(*dirn::d2::neighbour(vec, dirn::directions4::up), vec2(10, -1));
    ASSERT_EQ(*dirn::neighbour(vec, dirn::directions4::right), vec2(11, 0));
    ASSERT_EQ(*dirn::neighbour(vec, dirn::directions4::down), vec2(10, 1));
    ASSERT_EQ(*dirn::neighbour(vec, dirn::directions4::left), vec2(9, 0));

    ASSERT_FALSE(dirn::neighbour(vec, dirn::directions4::bad_direction));
    ASSERT_FALSE(dirn::neighbour(vec, dirn::directions4::undefined_direction));
}

TEST(neighbourhood_tests, neighbour_2)
{
    vec2 vec(10, 0);
    vec2 bad(0xfa11, 0xfa11);
    ASSERT_EQ(dirn::neighbour(vec, dirn::directions4::up, bad), vec2(10, -1));
    ASSERT_EQ(dirn::neighbour(vec, dirn::directions4::right, bad), vec2(11, 0));
    ASSERT_EQ(dirn::neighbour(vec, dirn::directions4::down, bad), vec2(10, 1));
    ASSERT_EQ(dirn::neighbour(vec, dirn::directions4::left, bad), vec2(9, 0));

    ASSERT_EQ(dirn::neighbour(vec, dirn::directions4::bad_direction, bad), bad);
    ASSERT_EQ(dirn::neighbour(vec, dirn::directions4::undefined_direction, bad), bad);
}

TEST(neighbourhood_tests, neighbours)
{
    vec2 vec(10, 0);
    std::array around{ vec2(10, -1), vec2(11, 0), vec2(10, 1), vec2(9, 0) };
    ASSERT_EQ(dirn::neighbours<dirn::directions4>(vec), around);
}
