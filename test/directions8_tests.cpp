#include <arba/dirn/d2/dir8/cartographic_directions8.hpp>
#include <arba/dirn/d2/dir8/directions8.hpp>

#include <gtest/gtest.h>

#include <cstdlib>

// directions8

TEST(directions8_tests, directions8_cardinality)
{
    ASSERT_EQ(dirn::directions8::cardinality, 8);
}

TEST(directions8_tests, directions8__dir_value)
{
    ASSERT_EQ(arba::dirn::d2::directions8::up, 0);
    ASSERT_EQ(dirn::d2::directions8::up.index(), 0);
    ASSERT_EQ(arba::dirn::d2::directions8::up_right, 1);
    ASSERT_EQ(dirn::d2::directions8::up_right.index(), 1);
    ASSERT_EQ(dirn::directions8::right, 2);
    ASSERT_EQ(dirn::directions8::right.index(), 2);
    ASSERT_EQ(arba::dirn::d2::directions8::down_right, 3);
    ASSERT_EQ(dirn::d2::directions8::down_right.index(), 3);
    ASSERT_EQ(dirn::directions8::down, 4);
    ASSERT_EQ(dirn::directions8::down.index(), 4);
    ASSERT_EQ(arba::dirn::d2::directions8::down_left, 5);
    ASSERT_EQ(dirn::d2::directions8::down_left.index(), 5);
    ASSERT_EQ(dirn::directions8::left, 6);
    ASSERT_EQ(dirn::directions8::left.index(), 6);
    ASSERT_EQ(arba::dirn::d2::directions8::up_left, 7);
    ASSERT_EQ(dirn::d2::directions8::up_left.index(), 7);

    ASSERT_EQ(dirn::directions8::bad_direction, -1);
    ASSERT_EQ(dirn::directions8::bad_direction.index(), -1);
    ASSERT_EQ(dirn::directions8::undefined_direction, -2);
    ASSERT_EQ(dirn::directions8::undefined_direction.index(), -2);
}

TEST(directions8_tests, direction8_to_string_view)
{
    ASSERT_EQ(dirn::d2::directions8::to_string_view(dirn::directions8::up), "up");
    ASSERT_EQ(dirn::d2::directions8::to_string_view(dirn::directions8::up_right), "up_right");
    ASSERT_EQ(dirn::directions8::to_string_view(dirn::directions8::right), "right");
    ASSERT_EQ(dirn::d2::directions8::to_string_view(dirn::directions8::down_right), "down_right");
    ASSERT_EQ(dirn::directions8::to_string_view(dirn::directions8::down), "down");
    ASSERT_EQ(dirn::d2::directions8::to_string_view(dirn::directions8::down_left), "down_left");
    ASSERT_EQ(dirn::directions8::to_string_view(dirn::directions8::left), "left");
    ASSERT_EQ(dirn::d2::directions8::to_string_view(dirn::directions8::up_left), "up_left");
    ASSERT_EQ(dirn::directions8::to_string_view(dirn::directions8::bad_direction), "bad");
    ASSERT_EQ(dirn::directions8::to_string_view(dirn::directions8::undefined_direction), "undefined");
}

TEST(directions8_tests, directions8__valid_directions)
{
    dirn::direction8 up = dirn::directions8::up;
    dirn::direction8 up_right = dirn::directions8::up_right;
    dirn::direction8 right = dirn::directions8::right;
    dirn::direction8 down_right = dirn::directions8::down_right;
    dirn::direction8 down = dirn::directions8::down;
    dirn::direction8 down_left = dirn::directions8::down_left;
    dirn::direction8 left = dirn::directions8::left;
    dirn::direction8 up_left = dirn::directions8::up_left;
    ASSERT_EQ(dirn::directions8::valid_directions,
              (std::array{ up, up_right, right, down_right, down, down_left, left, up_left }));
}

TEST(directions8_tests, directions8_opposed_directions)
{
    dirn::direction8 up = dirn::directions8::up;
    dirn::direction8 up_right = dirn::directions8::up_right;
    dirn::direction8 right = dirn::directions8::right;
    dirn::direction8 down_right = dirn::directions8::down_right;
    dirn::direction8 down = dirn::directions8::down;
    dirn::direction8 down_left = dirn::directions8::down_left;
    dirn::direction8 left = dirn::directions8::left;
    dirn::direction8 up_left = dirn::directions8::up_left;
    ASSERT_EQ(dirn::directions8::opposed_directions,
              (std::array{ down, down_left, left, up_left, up, up_right, right, down_right }));
}

TEST(directions8_tests, directions8_nth)
{
    ASSERT_EQ(dirn::directions8::nth(0), dirn::directions8::up);
    ASSERT_EQ(dirn::directions8::nth(1), dirn::directions8::up_right);
    ASSERT_EQ(dirn::directions8::nth(2), dirn::directions8::right);
    ASSERT_EQ(dirn::directions8::nth(3), dirn::directions8::down_right);
    ASSERT_EQ(dirn::directions8::nth(4), dirn::directions8::down);
    ASSERT_EQ(dirn::directions8::nth(5), dirn::directions8::down_left);
    ASSERT_EQ(dirn::directions8::nth(6), dirn::directions8::left);
    ASSERT_EQ(dirn::directions8::nth(7), dirn::directions8::up_left);
}

// cartographic_directions8

TEST(directions8_tests, cartographic_direction8_value)
{
    ASSERT_EQ(dirn::d2::cartographic_directions8::north, 0);
    ASSERT_EQ(dirn::cartographic_directions8::north.index(), 0);
    ASSERT_EQ(dirn::d2::cartographic_directions8::north_east, 1);
    ASSERT_EQ(dirn::cartographic_directions8::north_east.index(), 1);
    ASSERT_EQ(dirn::cartographic_directions8::east, 2);
    ASSERT_EQ(dirn::cartographic_directions8::east.index(), 2);
    ASSERT_EQ(dirn::d2::cartographic_directions8::south_east, 3);
    ASSERT_EQ(dirn::cartographic_directions8::south_east.index(), 3);
    ASSERT_EQ(dirn::cartographic_directions8::south, 4);
    ASSERT_EQ(dirn::cartographic_directions8::south.index(), 4);
    ASSERT_EQ(dirn::d2::cartographic_directions8::south_west, 5);
    ASSERT_EQ(dirn::cartographic_directions8::south_west.index(), 5);
    ASSERT_EQ(dirn::cartographic_directions8::west, 6);
    ASSERT_EQ(dirn::cartographic_directions8::west.index(), 6);
    ASSERT_EQ(dirn::d2::cartographic_directions8::north_west, 7);
    ASSERT_EQ(dirn::cartographic_directions8::north_west.index(), 7);

    ASSERT_EQ(dirn::cartographic_directions8::bad_direction, -1);
    ASSERT_EQ(dirn::cartographic_directions8::bad_direction.index(), -1);
    ASSERT_EQ(dirn::cartographic_directions8::undefined_direction, -2);
    ASSERT_EQ(dirn::cartographic_directions8::undefined_direction.index(), -2);
}

TEST(directions8_tests, cartographic_direction8_to_string_view)
{
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::north), "north");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::north_east), "north_east");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::east), "east");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::south_east), "south_east");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::south), "south");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::south_west), "south_west");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::west), "west");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::north_west), "north_west");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::bad_direction), "bad");
    ASSERT_EQ(dirn::cartographic_directions8::to_string_view(dirn::cartographic_directions8::undefined_direction),
              "undefined");
}

// directions8 == cartographic_directions8

TEST(directions8_tests, directions8_equals_cartographic_directions8)
{
    ASSERT_EQ(dirn::directions8::up.index(), dirn::cartographic_directions8::north);
    ASSERT_EQ(dirn::directions8::up_right.index(), dirn::cartographic_directions8::north_east);
    ASSERT_EQ(dirn::directions8::right.index(), dirn::cartographic_directions8::east);
    ASSERT_EQ(dirn::directions8::down_right.index(), dirn::cartographic_directions8::south_east);
    ASSERT_EQ(dirn::directions8::down.index(), dirn::cartographic_directions8::south);
    ASSERT_EQ(dirn::directions8::down_left.index(), dirn::cartographic_directions8::south_west);
    ASSERT_EQ(dirn::directions8::left.index(), dirn::cartographic_directions8::west);
    ASSERT_EQ(dirn::directions8::up_left.index(), dirn::cartographic_directions8::north_west);

    ASSERT_EQ(dirn::directions8::bad_direction.index(), dirn::cartographic_directions8::bad_direction);
    ASSERT_EQ(dirn::directions8::undefined_direction.index(), dirn::cartographic_directions8::undefined_direction);
}

// direction8

TEST(directions8_tests, direction8_cardinality)
{
    ASSERT_EQ(dirn::direction8::cardinality, 8);
}

TEST(directions8_tests, direction8_is_valid)
{
    ASSERT_TRUE(dirn::directions8::up.is_valid());
    ASSERT_TRUE(dirn::directions8::right.is_valid());
    ASSERT_TRUE(dirn::directions8::down.is_valid());
    ASSERT_TRUE(dirn::directions8::left.is_valid());

    ASSERT_TRUE(dirn::directions8::up_right.is_valid());
    ASSERT_TRUE(dirn::directions8::up_left.is_valid());
    ASSERT_TRUE(dirn::directions8::down_right.is_valid());
    ASSERT_TRUE(dirn::directions8::down_left.is_valid());

    ASSERT_FALSE(dirn::directions8::bad_direction.is_valid());
    ASSERT_FALSE(dirn::directions8::undefined_direction.is_valid());
}

TEST(directions8_tests, direction8_is_bad)
{
    ASSERT_FALSE(dirn::directions8::up.is_bad());
    ASSERT_FALSE(dirn::directions8::right.is_bad());
    ASSERT_FALSE(dirn::directions8::down.is_bad());
    ASSERT_FALSE(dirn::directions8::left.is_bad());

    ASSERT_FALSE(dirn::directions8::up_right.is_bad());
    ASSERT_FALSE(dirn::directions8::up_left.is_bad());
    ASSERT_FALSE(dirn::directions8::down_right.is_bad());
    ASSERT_FALSE(dirn::directions8::down_left.is_bad());

    ASSERT_TRUE(dirn::directions8::bad_direction.is_bad());
    ASSERT_FALSE(dirn::directions8::undefined_direction.is_bad());
}

TEST(directions8_tests, direction8_is_defined)
{
    ASSERT_TRUE(dirn::directions8::up.is_defined());
    ASSERT_TRUE(dirn::directions8::right.is_defined());
    ASSERT_TRUE(dirn::directions8::down.is_defined());
    ASSERT_TRUE(dirn::directions8::left.is_defined());

    ASSERT_TRUE(dirn::directions8::up_right.is_defined());
    ASSERT_TRUE(dirn::directions8::up_left.is_defined());
    ASSERT_TRUE(dirn::directions8::down_right.is_defined());
    ASSERT_TRUE(dirn::directions8::down_left.is_defined());

    ASSERT_TRUE(dirn::directions8::bad_direction.is_defined());
    ASSERT_FALSE(dirn::directions8::undefined_direction.is_defined());
}

TEST(directions8_tests, direction8_is_undefined)
{
    ASSERT_FALSE(dirn::directions8::up.is_undefined());
    ASSERT_FALSE(dirn::directions8::right.is_undefined());
    ASSERT_FALSE(dirn::directions8::down.is_undefined());
    ASSERT_FALSE(dirn::directions8::left.is_undefined());

    ASSERT_FALSE(dirn::directions8::up_right.is_undefined());
    ASSERT_FALSE(dirn::directions8::up_left.is_undefined());
    ASSERT_FALSE(dirn::directions8::down_right.is_undefined());
    ASSERT_FALSE(dirn::directions8::down_left.is_undefined());

    ASSERT_FALSE(dirn::directions8::bad_direction.is_undefined());
    ASSERT_TRUE(dirn::directions8::undefined_direction.is_undefined());
}

TEST(directions8_tests, direction8_left_direction)
{
    ASSERT_EQ(dirn::directions8::up.left_direction(), dirn::directions8::up_left);
    ASSERT_EQ(dirn::directions8::up_right.left_direction(), dirn::directions8::up);
    ASSERT_EQ(dirn::directions8::right.left_direction(), dirn::directions8::up_right);
    ASSERT_EQ(dirn::directions8::down_right.left_direction(), dirn::directions8::right);
    ASSERT_EQ(dirn::directions8::down.left_direction(), dirn::directions8::down_right);
    ASSERT_EQ(dirn::directions8::down_left.left_direction(), dirn::directions8::down);
    ASSERT_EQ(dirn::directions8::left.left_direction(), dirn::directions8::down_left);
    ASSERT_EQ(dirn::directions8::up_left.left_direction(), dirn::directions8::left);
}

TEST(directions8_tests, direction8_right_direction)
{
    ASSERT_EQ(dirn::directions8::up.right_direction(), dirn::directions8::up_right);
    ASSERT_EQ(dirn::directions8::up_right.right_direction(), dirn::directions8::right);
    ASSERT_EQ(dirn::directions8::right.right_direction(), dirn::directions8::down_right);
    ASSERT_EQ(dirn::directions8::down_right.right_direction(), dirn::directions8::down);
    ASSERT_EQ(dirn::directions8::down.right_direction(), dirn::directions8::down_left);
    ASSERT_EQ(dirn::directions8::down_left.right_direction(), dirn::directions8::left);
    ASSERT_EQ(dirn::directions8::left.right_direction(), dirn::directions8::up_left);
    ASSERT_EQ(dirn::directions8::up_left.right_direction(), dirn::directions8::up);
}

TEST(directions8_tests, direction8_opposed_direction)
{
    ASSERT_EQ(dirn::directions8::up.opposed_direction(), dirn::directions8::down);
    ASSERT_EQ(dirn::directions8::up_right.opposed_direction(), dirn::directions8::down_left);
    ASSERT_EQ(dirn::directions8::right.opposed_direction(), dirn::directions8::left);
    ASSERT_EQ(dirn::directions8::down_right.opposed_direction(), dirn::directions8::up_left);
    ASSERT_EQ(dirn::directions8::down.opposed_direction(), dirn::directions8::up);
    ASSERT_EQ(dirn::directions8::down_left.opposed_direction(), dirn::directions8::up_right);
    ASSERT_EQ(dirn::directions8::left.opposed_direction(), dirn::directions8::right);
    ASSERT_EQ(dirn::directions8::up_left.opposed_direction(), dirn::directions8::down_right);
}

TEST(directions8_tests, direction8_other_directions)
{
    dirn::direction8 up = dirn::directions8::up;
    dirn::direction8 up_right = dirn::directions8::up_right;
    dirn::direction8 right = dirn::directions8::right;
    dirn::direction8 down_right = dirn::directions8::down_right;
    dirn::direction8 down = dirn::directions8::down;
    dirn::direction8 down_left = dirn::directions8::down_left;
    dirn::direction8 left = dirn::directions8::left;
    dirn::direction8 up_left = dirn::directions8::up_left;
    ASSERT_EQ(up.other_directions(), (std::array{ up_right, right, down_right, down, down_left, left, up_left }));
    ASSERT_EQ(up_right.other_directions(), (std::array{ up, right, down_right, down, down_left, left, up_left }));
    ASSERT_EQ(right.other_directions(), (std::array{ up, up_right, down_right, down, down_left, left, up_left }));
    ASSERT_EQ(down_right.other_directions(), (std::array{ up, up_right, right, down, down_left, left, up_left }));
    ASSERT_EQ(down.other_directions(), (std::array{ up, up_right, right, down_right, down_left, left, up_left }));
    ASSERT_EQ(down_left.other_directions(), (std::array{ up, up_right, right, down_right, down, left, up_left }));
    ASSERT_EQ(left.other_directions(), (std::array{ up, up_right, right, down_right, down, down_left, up_left }));
    ASSERT_EQ(up_left.other_directions(), (std::array{ up, up_right, right, down_right, down, down_left, left }));
}

TEST(directions8_tests, direction8_hash)
{
    std::hash<dirn::direction8> dir_hash;
    ASSERT_EQ(dir_hash(dirn::directions8::up), static_cast<std::size_t>(dirn::directions8::up.index()));
    ASSERT_EQ(dir_hash(dirn::directions8::right), static_cast<std::size_t>(dirn::directions8::right.index()));
    ASSERT_EQ(dir_hash(dirn::directions8::down), static_cast<std::size_t>(dirn::directions8::down.index()));
    ASSERT_EQ(dir_hash(dirn::directions8::left), static_cast<std::size_t>(dirn::directions8::left.index()));
    ASSERT_EQ(dir_hash(dirn::directions8::up_right), static_cast<std::size_t>(dirn::directions8::up_right.index()));
    ASSERT_EQ(dir_hash(dirn::directions8::up_left), static_cast<std::size_t>(dirn::directions8::up_left.index()));
    ASSERT_EQ(dir_hash(dirn::directions8::down_right), static_cast<std::size_t>(dirn::directions8::down_right.index()));
    ASSERT_EQ(dir_hash(dirn::directions8::down_left), static_cast<std::size_t>(dirn::directions8::down_left.index()));
}
