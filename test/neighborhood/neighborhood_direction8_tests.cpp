#include "vec2.hpp"
#include <arba/dirn/d2/dir8/directions8.hpp>

#include <gtest/gtest.h>

#include <cstdlib>

const vec2 pos(10, 0);
const std::array neighborhood{ vec2(10, -1), vec2(11, -1), vec2(11, 0), vec2(11, 1),
                               vec2(10, 1),  vec2(9, 1),   vec2(9, 0),  vec2(9, -1) };

TEST(neighborhood_direction8_tests, neighbor)
{
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions8::up), neighborhood[0]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions8::up_right), neighborhood[1]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions8::right), neighborhood[2]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions8::down_right), neighborhood[3]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions8::down), neighborhood[4]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions8::down_left), neighborhood[5]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions8::left), neighborhood[6]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::directions8::up_left), neighborhood[7]);
}

TEST(neighborhood_direction8_tests, neighbors)
{
    ASSERT_EQ(dirn::neighbors<dirn::direction8>(pos), neighborhood);
}

TEST(neighborhood_direction8_tests, neighbors_array)
{
    std::array<vec2, 8> around;
    dirn::neighbors<dirn::direction8>(pos, around);
    ASSERT_EQ(around, neighborhood);
}
