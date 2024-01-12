#include <arba/dirn/d2/directions4.hpp>
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

    vec2 operator+(const vec2& rhs) const { return vec2(x_ + rhs.x_, y_ + rhs.y_); }

    auto operator<=>(const vec2& v) const = default;
};

TEST(neighborhood_tests, neighbor)
{
    vec2 vec(10, 0);
    ASSERT_EQ(dirn::neighbor(vec, dirn::directions4::up), vec2(10, -1));
    ASSERT_EQ(dirn::neighbor(vec, dirn::directions4::right), vec2(11, 0));
    ASSERT_EQ(dirn::neighbor(vec, dirn::directions4::down), vec2(10, 1));
    ASSERT_EQ(dirn::neighbor(vec, dirn::directions4::left), vec2(9, 0));
}

TEST(neighborhood_tests, neighbors)
{
    vec2 vec(10, 0);
    std::array expected_around{ vec2(10, -1), vec2(11, 0), vec2(10, 1), vec2(9, 0) };
    ASSERT_EQ(dirn::neighbors<dirn::direction4>(vec), expected_around);
}

TEST(neighborhood_tests, neighbors_2)
{
    vec2 vec(10, 0);
    std::array<vec2, 4> around;
    std::array expected_around{ vec2(10, -1), vec2(11, 0), vec2(10, 1), vec2(9, 0) };
    dirn::neighbors<dirn::direction4>(vec, around);
    ASSERT_EQ(around, expected_around);
}
