#include <arba/dirn/d2/dir4/cartographic_directions4.hpp>
#include <arba/dirn/d2/dir4/directions4.hpp>
#include <cstdlib>
#include <gtest/gtest.h>

// directions4

TEST(directions4_tests, directions4_cardinality)
{
    ASSERT_EQ(dirn::directions4::cardinality, 4);
}

TEST(directions4_tests, directions4__dir_value)
{
    ASSERT_EQ(arba::dirn::d2::directions4::up, 0);
    ASSERT_EQ(dirn::d2::directions4::up.index(), 0);
    ASSERT_EQ(dirn::directions4::right, 1);
    ASSERT_EQ(dirn::directions4::right.index(), 1);
    ASSERT_EQ(dirn::directions4::down, 2);
    ASSERT_EQ(dirn::directions4::down.index(), 2);
    ASSERT_EQ(dirn::directions4::left, 3);
    ASSERT_EQ(dirn::directions4::left.index(), 3);

    ASSERT_EQ(dirn::directions4::bad_direction, -1);
    ASSERT_EQ(dirn::directions4::bad_direction.index(), -1);
    ASSERT_EQ(dirn::directions4::undefined_direction, -2);
    ASSERT_EQ(dirn::directions4::undefined_direction.index(), -2);
}

TEST(directions4_tests, direction4_to_string_view)
{
    ASSERT_EQ(dirn::d2::directions4::to_string_view(dirn::directions4::up), "UP");
    ASSERT_EQ(dirn::directions4::to_string_view(dirn::directions4::right), "RIGHT");
    ASSERT_EQ(dirn::directions4::to_string_view(dirn::directions4::down), "DOWN");
    ASSERT_EQ(dirn::directions4::to_string_view(dirn::directions4::left), "LEFT");
    ASSERT_EQ(dirn::directions4::to_string_view(dirn::directions4::bad_direction), "BAD");
    ASSERT_EQ(dirn::directions4::to_string_view(dirn::directions4::undefined_direction), "UNDEFINED");
}

TEST(directions4_tests, direction4_to_char)
{
    ASSERT_EQ(dirn::directions4::to_char(dirn::directions4::up), 'U');
    ASSERT_EQ(dirn::directions4::to_char(dirn::directions4::right), 'R');
    ASSERT_EQ(dirn::directions4::to_char(dirn::directions4::down), 'D');
    ASSERT_EQ(dirn::directions4::to_char(dirn::directions4::left), 'L');
    ASSERT_EQ(dirn::directions4::to_char(dirn::directions4::bad_direction), '%');
    ASSERT_EQ(dirn::directions4::to_char(dirn::directions4::undefined_direction), '?');
}

TEST(directions4_tests, directions4__valid_directions)
{
    dirn::direction4 up = dirn::directions4::up;
    dirn::direction4 right = dirn::directions4::right;
    dirn::direction4 down = dirn::directions4::down;
    dirn::direction4 left = dirn::directions4::left;
    ASSERT_EQ(dirn::directions4::valid_directions, (std::array{ up, right, down, left }));
}

TEST(directions4_tests, directions4_opposed_directions)
{
    dirn::direction4 up = dirn::directions4::up;
    dirn::direction4 right = dirn::directions4::right;
    dirn::direction4 down = dirn::directions4::down;
    dirn::direction4 left = dirn::directions4::left;
    ASSERT_EQ(dirn::directions4::opposed_directions, (std::array{ down, left, up, right }));
}

TEST(directions4_tests, directions4_nth)
{
    ASSERT_EQ(dirn::directions4::nth(0), dirn::directions4::up);
    ASSERT_EQ(dirn::directions4::nth(1), dirn::directions4::right);
    ASSERT_EQ(dirn::directions4::nth(2), dirn::directions4::down);
    ASSERT_EQ(dirn::directions4::nth(3), dirn::directions4::left);
}

// cartographic_directions4

TEST(directions4_tests, cartographic_direction4_value)
{
    ASSERT_EQ(dirn::d2::cartographic_directions4::north, 0);
    ASSERT_EQ(dirn::cartographic_directions4::north.index(), 0);
    ASSERT_EQ(dirn::cartographic_directions4::east, 1);
    ASSERT_EQ(dirn::cartographic_directions4::east.index(), 1);
    ASSERT_EQ(dirn::cartographic_directions4::south, 2);
    ASSERT_EQ(dirn::cartographic_directions4::south.index(), 2);
    ASSERT_EQ(dirn::cartographic_directions4::west, 3);
    ASSERT_EQ(dirn::cartographic_directions4::west.index(), 3);

    ASSERT_EQ(dirn::cartographic_directions4::bad_direction, -1);
    ASSERT_EQ(dirn::cartographic_directions4::bad_direction.index(), -1);
    ASSERT_EQ(dirn::cartographic_directions4::undefined_direction, -2);
    ASSERT_EQ(dirn::cartographic_directions4::undefined_direction.index(), -2);
}

TEST(directions4_tests, cartographic_direction4_to_string_view)
{
    ASSERT_EQ(dirn::cartographic_directions4::to_string_view(dirn::cartographic_directions4::north), "NORTH");
    ASSERT_EQ(dirn::cartographic_directions4::to_string_view(dirn::cartographic_directions4::east), "EAST");
    ASSERT_EQ(dirn::cartographic_directions4::to_string_view(dirn::cartographic_directions4::south), "SOUTH");
    ASSERT_EQ(dirn::cartographic_directions4::to_string_view(dirn::cartographic_directions4::west), "WEST");
    ASSERT_EQ(dirn::cartographic_directions4::to_string_view(dirn::cartographic_directions4::bad_direction), "BAD");
    ASSERT_EQ(dirn::cartographic_directions4::to_string_view(dirn::cartographic_directions4::undefined_direction),
              "UNDEFINED");
}

TEST(directions4_tests, cartographic_direction4_to_char)
{
    ASSERT_EQ(dirn::cartographic_directions4::to_char(dirn::cartographic_directions4::north), 'N');
    ASSERT_EQ(dirn::cartographic_directions4::to_char(dirn::cartographic_directions4::east), 'E');
    ASSERT_EQ(dirn::cartographic_directions4::to_char(dirn::cartographic_directions4::south), 'S');
    ASSERT_EQ(dirn::cartographic_directions4::to_char(dirn::cartographic_directions4::west), 'W');
    ASSERT_EQ(dirn::cartographic_directions4::to_char(dirn::cartographic_directions4::bad_direction), '%');
    ASSERT_EQ(dirn::cartographic_directions4::to_char(dirn::cartographic_directions4::undefined_direction), '?');
}

// directions4 == cartographic_directions4

TEST(directions4_tests, directions4_equals_cartographic_directions4)
{
    ASSERT_EQ(dirn::directions4::up.index(), dirn::cartographic_directions4::north);
    ASSERT_EQ(dirn::directions4::right.index(), dirn::cartographic_directions4::east);
    ASSERT_EQ(dirn::directions4::down.index(), dirn::cartographic_directions4::south);
    ASSERT_EQ(dirn::directions4::left.index(), dirn::cartographic_directions4::west);

    ASSERT_EQ(dirn::directions4::bad_direction.index(), dirn::cartographic_directions4::bad_direction);
    ASSERT_EQ(dirn::directions4::undefined_direction.index(), dirn::cartographic_directions4::undefined_direction);
}

// direction4

TEST(directions4_tests, direction4_cardinality)
{
    ASSERT_EQ(dirn::direction4::cardinality, 4);
}

TEST(directions4_tests, direction4_is_valid)
{
    ASSERT_TRUE(dirn::directions4::up.is_valid());
    ASSERT_TRUE(dirn::directions4::right.is_valid());
    ASSERT_TRUE(dirn::directions4::down.is_valid());
    ASSERT_TRUE(dirn::directions4::left.is_valid());

    ASSERT_FALSE(dirn::directions4::bad_direction.is_valid());
    ASSERT_FALSE(dirn::directions4::undefined_direction.is_valid());
}

TEST(directions4_tests, direction4_is_bad)
{
    ASSERT_FALSE(dirn::directions4::up.is_bad());
    ASSERT_FALSE(dirn::directions4::right.is_bad());
    ASSERT_FALSE(dirn::directions4::down.is_bad());
    ASSERT_FALSE(dirn::directions4::left.is_bad());

    ASSERT_TRUE(dirn::directions4::bad_direction.is_bad());
    ASSERT_FALSE(dirn::directions4::undefined_direction.is_bad());
}

TEST(directions4_tests, direction4_is_defined)
{
    ASSERT_TRUE(dirn::directions4::up.is_defined());
    ASSERT_TRUE(dirn::directions4::right.is_defined());
    ASSERT_TRUE(dirn::directions4::down.is_defined());
    ASSERT_TRUE(dirn::directions4::left.is_defined());

    ASSERT_TRUE(dirn::directions4::bad_direction.is_defined());
    ASSERT_FALSE(dirn::directions4::undefined_direction.is_defined());
}

TEST(directions4_tests, direction4_is_undefined)
{
    ASSERT_FALSE(dirn::directions4::up.is_undefined());
    ASSERT_FALSE(dirn::directions4::right.is_undefined());
    ASSERT_FALSE(dirn::directions4::down.is_undefined());
    ASSERT_FALSE(dirn::directions4::left.is_undefined());

    ASSERT_FALSE(dirn::directions4::bad_direction.is_undefined());
    ASSERT_TRUE(dirn::directions4::undefined_direction.is_undefined());
}

TEST(directions4_tests, direction4_left_direction)
{
    ASSERT_EQ(dirn::directions4::up.left_direction(), dirn::directions4::left);
    ASSERT_EQ(dirn::directions4::right.left_direction(), dirn::directions4::up);
    ASSERT_EQ(dirn::directions4::down.left_direction(), dirn::directions4::right);
    ASSERT_EQ(dirn::directions4::left.left_direction(), dirn::directions4::down);
}

TEST(directions4_tests, direction4_right_direction)
{
    ASSERT_EQ(dirn::directions4::up.right_direction(), dirn::directions4::right);
    ASSERT_EQ(dirn::directions4::right.right_direction(), dirn::directions4::down);
    ASSERT_EQ(dirn::directions4::down.right_direction(), dirn::directions4::left);
    ASSERT_EQ(dirn::directions4::left.right_direction(), dirn::directions4::up);
}

TEST(directions4_tests, direction4_opposed_direction)
{
    ASSERT_EQ(dirn::directions4::up.opposed_direction(), dirn::directions4::down);
    ASSERT_EQ(dirn::directions4::right.opposed_direction(), dirn::directions4::left);
    ASSERT_EQ(dirn::directions4::down.opposed_direction(), dirn::directions4::up);
    ASSERT_EQ(dirn::directions4::left.opposed_direction(), dirn::directions4::right);
}

TEST(directions4_tests, direction4_other_directions)
{
    dirn::direction4 up = dirn::directions4::up;
    dirn::direction4 right = dirn::directions4::right;
    dirn::direction4 down = dirn::directions4::down;
    dirn::direction4 left = dirn::directions4::left;
    ASSERT_EQ(up.other_directions(), (std::array{ right, down, left }));
    ASSERT_EQ(right.other_directions(), (std::array{ up, down, left }));
    ASSERT_EQ(down.other_directions(), (std::array{ up, right, left }));
    ASSERT_EQ(left.other_directions(), (std::array{ up, right, down }));
}

TEST(directions4_tests, direction4_hash)
{
    std::hash<dirn::direction4> dir_hash;
    ASSERT_EQ(dir_hash(dirn::directions4::up), static_cast<std::size_t>(dirn::directions4::up.index()));
    ASSERT_EQ(dir_hash(dirn::directions4::right), static_cast<std::size_t>(dirn::directions4::right.index()));
    ASSERT_EQ(dir_hash(dirn::directions4::down), static_cast<std::size_t>(dirn::directions4::down.index()));
    ASSERT_EQ(dir_hash(dirn::directions4::left), static_cast<std::size_t>(dirn::directions4::left.index()));
}
