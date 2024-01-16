#include "vec2.hpp"

#include <arba/dirn/d2/dir4/directions4.hpp>
#include <cstdlib>
#include <gtest/gtest.h>

TEST(neighborhood_direction4_tests, neighbor)
{
    vec2 pos(10, 0);
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions4::up), vec2(10, -1));
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions4::right), vec2(11, 0));
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions4::down), vec2(10, 1));
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions4::left), vec2(9, 0));
}

TEST(neighborhood_direction4_tests, neighbors)
{
    vec2 pos(10, 0);
    std::array expected_around{ vec2(10, -1), vec2(11, 0), vec2(10, 1), vec2(9, 0) };
    ASSERT_EQ(dirn::neighbors<dirn::direction4>(pos), expected_around);
}

TEST(neighborhood_direction4_tests, neighbors_array)
{
    vec2 pos(10, 0);
    std::array<vec2, 4> around;
    std::array expected_around{ vec2(10, -1), vec2(11, 0), vec2(10, 1), vec2(9, 0) };
    dirn::neighbors<dirn::direction4>(pos, around);
    ASSERT_EQ(around, expected_around);
}
