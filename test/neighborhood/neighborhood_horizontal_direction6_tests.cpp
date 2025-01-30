#include "vec2.hpp"
#include <arba/dirn/d2/dir6/horizontal_directions6.hpp>

#include <gtest/gtest.h>

#include <cstdlib>

const vec2 odd_pos(2, 1);
const std::array odd_neighborhood{ vec2(1, 1), vec2(2, 0), vec2(3, 0), vec2(3, 1), vec2(3, 2), vec2(2, 2) };
const vec2 even_pos(1, 2);
const std::array even_neighborhood{ vec2(0, 2), vec2(0, 1), vec2(1, 1), vec2(2, 2), vec2(1, 3), vec2(0, 3) };

TEST(neighborhood_horizontal_direction6_tests, neighbor)
{
    vec2 pos = odd_pos;
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::left), odd_neighborhood[0]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::left_up), odd_neighborhood[1]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::right_up), odd_neighborhood[2]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::right), odd_neighborhood[3]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::right_down), odd_neighborhood[4]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::left_down), odd_neighborhood[5]);

    pos = even_pos;
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::left), even_neighborhood[0]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::left_up), even_neighborhood[1]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::right_up), even_neighborhood[2]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::right), even_neighborhood[3]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::right_down), even_neighborhood[4]);
    ASSERT_EQ(dirn::neighbor(pos, dirn::horizontal_directions6::left_down), even_neighborhood[5]);
}

TEST(neighborhood_horizontal_direction6_tests, neighbors)
{
    ASSERT_EQ(dirn::neighbors<dirn::horizontal_direction6>(odd_pos), odd_neighborhood);
    ASSERT_EQ(dirn::neighbors<dirn::horizontal_direction6>(even_pos), even_neighborhood);
}

TEST(neighborhood_horizontal_direction6_tests, neighbors_array)
{
    std::array<vec2, 6> around;
    dirn::neighbors<dirn::horizontal_direction6>(odd_pos, around);
    ASSERT_EQ(around, odd_neighborhood);
    dirn::neighbors<dirn::horizontal_direction6>(even_pos, around);
    ASSERT_EQ(around, even_neighborhood);
}
