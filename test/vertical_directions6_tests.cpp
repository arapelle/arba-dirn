#include <arba/dirn/d2/dir6/vertical_directions6.hpp>
#include <cstdlib>
#include <gtest/gtest.h>

// vertical_directions6

TEST(vertical_directions6_tests, vertical_directions6_cardinality)
{
    ASSERT_EQ(dirn::vertical_directions6::cardinality, 6);
}

TEST(vertical_directions6_tests, vertical_direction6_value)
{
    ASSERT_EQ(arba::dirn::d2::vertical_directions6::up, 0);
    ASSERT_EQ(dirn::d2::vertical_directions6::up.index(), 0);
    ASSERT_EQ(dirn::vertical_directions6::up_right, 1);
    ASSERT_EQ(dirn::vertical_directions6::up_right.index(), 1);
    ASSERT_EQ(dirn::vertical_directions6::down_right, 2);
    ASSERT_EQ(dirn::vertical_directions6::down_right.index(), 2);
    ASSERT_EQ(dirn::vertical_directions6::down, 3);
    ASSERT_EQ(dirn::vertical_directions6::down.index(), 3);
    ASSERT_EQ(dirn::vertical_directions6::down_left, 4);
    ASSERT_EQ(dirn::vertical_directions6::down_left.index(), 4);
    ASSERT_EQ(dirn::vertical_directions6::up_left, 5);
    ASSERT_EQ(dirn::vertical_directions6::up_left.index(), 5);

    ASSERT_EQ(dirn::vertical_directions6::bad_direction, -1);
    ASSERT_EQ(dirn::vertical_directions6::bad_direction.index(), -1);
    ASSERT_EQ(dirn::vertical_directions6::undefined_direction, -2);
    ASSERT_EQ(dirn::vertical_directions6::undefined_direction.index(), -2);
}

TEST(vertical_directions6_tests, vertical_direction6_to_string_view)
{
    ASSERT_EQ(dirn::d2::vertical_directions6::to_string_view(dirn::vertical_directions6::up), "up");
    ASSERT_EQ(dirn::vertical_directions6::to_string_view(dirn::vertical_directions6::up_right), "up_right");
    ASSERT_EQ(dirn::vertical_directions6::to_string_view(dirn::vertical_directions6::down_right), "down_right");
    ASSERT_EQ(dirn::vertical_directions6::to_string_view(dirn::vertical_directions6::down), "down");
    ASSERT_EQ(dirn::vertical_directions6::to_string_view(dirn::vertical_directions6::down_left), "down_left");
    ASSERT_EQ(dirn::vertical_directions6::to_string_view(dirn::vertical_directions6::up_left), "up_left");
    ASSERT_EQ(dirn::vertical_directions6::to_string_view(dirn::vertical_directions6::bad_direction), "bad");
    ASSERT_EQ(dirn::vertical_directions6::to_string_view(dirn::vertical_directions6::undefined_direction), "undefined");
}

TEST(vertical_directions6_tests, vertical_direction6_to_char)
{
    ASSERT_EQ(dirn::vertical_directions6::to_char(dirn::vertical_directions6::up), 'U');
    ASSERT_EQ(dirn::vertical_directions6::to_char(dirn::vertical_directions6::up_right), 'R');
    ASSERT_EQ(dirn::vertical_directions6::to_char(dirn::vertical_directions6::down_right), 'K');
    ASSERT_EQ(dirn::vertical_directions6::to_char(dirn::vertical_directions6::down), 'D');
    ASSERT_EQ(dirn::vertical_directions6::to_char(dirn::vertical_directions6::down_left), 'J');
    ASSERT_EQ(dirn::vertical_directions6::to_char(dirn::vertical_directions6::up_left), 'L');
    ASSERT_EQ(dirn::vertical_directions6::to_char(dirn::vertical_directions6::bad_direction), '%');
    ASSERT_EQ(dirn::vertical_directions6::to_char(dirn::vertical_directions6::undefined_direction), '?');
}

TEST(vertical_directions6_tests, vertical_directions6__valid_directions)
{
    dirn::vertical_direction6 up = dirn::vertical_directions6::up;
    dirn::vertical_direction6 up_right = dirn::vertical_directions6::up_right;
    dirn::vertical_direction6 down_right = dirn::vertical_directions6::down_right;
    dirn::vertical_direction6 down = dirn::vertical_directions6::down;
    dirn::vertical_direction6 down_left = dirn::vertical_directions6::down_left;
    dirn::vertical_direction6 up_left = dirn::vertical_directions6::up_left;
    ASSERT_EQ(dirn::vertical_directions6::valid_directions, (std::array{ up, up_right, down_right, down, down_left, up_left }));
}

TEST(vertical_directions6_tests, vertical_directions6__opposed_directions)
{
    dirn::vertical_direction6 up = dirn::vertical_directions6::up;
    dirn::vertical_direction6 up_right = dirn::vertical_directions6::up_right;
    dirn::vertical_direction6 down_right = dirn::vertical_directions6::down_right;
    dirn::vertical_direction6 down = dirn::vertical_directions6::down;
    dirn::vertical_direction6 down_left = dirn::vertical_directions6::down_left;
    dirn::vertical_direction6 up_left = dirn::vertical_directions6::up_left;
    ASSERT_EQ(dirn::vertical_directions6::opposed_directions, (std::array{ down, down_left, up_left, up, up_right, down_right }));
}

TEST(vertical_directions6_tests, vertical_directions6__nth)
{
    ASSERT_EQ(dirn::vertical_directions6::nth(0), dirn::vertical_directions6::up);
    ASSERT_EQ(dirn::vertical_directions6::nth(1), dirn::vertical_directions6::up_right);
    ASSERT_EQ(dirn::vertical_directions6::nth(2), dirn::vertical_directions6::down_right);
    ASSERT_EQ(dirn::vertical_directions6::nth(3), dirn::vertical_directions6::down);
    ASSERT_EQ(dirn::vertical_directions6::nth(4), dirn::vertical_directions6::down_left);
    ASSERT_EQ(dirn::vertical_directions6::nth(5), dirn::vertical_directions6::up_left);
}

// vertical_direction6

TEST(vertical_directions6_tests, vertical_direction6_cardinality)
{
    ASSERT_EQ(dirn::vertical_direction6::cardinality, 6);
}

TEST(vertical_directions6_tests, vertical_direction6_is_valid)
{
    ASSERT_TRUE(dirn::vertical_directions6::up.is_valid());
    ASSERT_TRUE(dirn::vertical_directions6::up_right.is_valid());
    ASSERT_TRUE(dirn::vertical_directions6::down_right.is_valid());
    ASSERT_TRUE(dirn::vertical_directions6::down.is_valid());
    ASSERT_TRUE(dirn::vertical_directions6::down_left.is_valid());
    ASSERT_TRUE(dirn::vertical_directions6::up_left.is_valid());

    ASSERT_FALSE(dirn::vertical_directions6::bad_direction.is_valid());
    ASSERT_FALSE(dirn::vertical_directions6::undefined_direction.is_valid());
}

TEST(vertical_directions6_tests, vertical_direction6_is_bad)
{
    ASSERT_FALSE(dirn::vertical_directions6::up.is_bad());
    ASSERT_FALSE(dirn::vertical_directions6::up_right.is_bad());
    ASSERT_FALSE(dirn::vertical_directions6::down_right.is_bad());
    ASSERT_FALSE(dirn::vertical_directions6::down.is_bad());
    ASSERT_FALSE(dirn::vertical_directions6::down_left.is_bad());
    ASSERT_FALSE(dirn::vertical_directions6::up_left.is_bad());

    ASSERT_TRUE(dirn::vertical_directions6::bad_direction.is_bad());
    ASSERT_FALSE(dirn::vertical_directions6::undefined_direction.is_bad());
}

TEST(vertical_directions6_tests, vertical_direction6_is_defined)
{
    ASSERT_TRUE(dirn::vertical_directions6::up.is_defined());
    ASSERT_TRUE(dirn::vertical_directions6::up_right.is_defined());
    ASSERT_TRUE(dirn::vertical_directions6::down_right.is_defined());
    ASSERT_TRUE(dirn::vertical_directions6::down.is_defined());
    ASSERT_TRUE(dirn::vertical_directions6::down_left.is_defined());
    ASSERT_TRUE(dirn::vertical_directions6::up_left.is_defined());

    ASSERT_TRUE(dirn::vertical_directions6::bad_direction.is_defined());
    ASSERT_FALSE(dirn::vertical_directions6::undefined_direction.is_defined());
}

TEST(vertical_directions6_tests, vertical_direction6_is_undefined)
{
    ASSERT_FALSE(dirn::vertical_directions6::up.is_undefined());
    ASSERT_FALSE(dirn::vertical_directions6::up_right.is_undefined());
    ASSERT_FALSE(dirn::vertical_directions6::down_right.is_undefined());
    ASSERT_FALSE(dirn::vertical_directions6::down.is_undefined());
    ASSERT_FALSE(dirn::vertical_directions6::down_left.is_undefined());
    ASSERT_FALSE(dirn::vertical_directions6::up_left.is_undefined());

    ASSERT_FALSE(dirn::vertical_directions6::bad_direction.is_undefined());
    ASSERT_TRUE(dirn::vertical_directions6::undefined_direction.is_undefined());
}

TEST(vertical_directions6_tests, vertical_direction6__left_direction)
{
    ASSERT_EQ(dirn::vertical_directions6::up.left_direction(), dirn::vertical_directions6::up_left);
    ASSERT_EQ(dirn::vertical_directions6::up_right.left_direction(), dirn::vertical_directions6::up);
    ASSERT_EQ(dirn::vertical_directions6::down_right.left_direction(), dirn::vertical_directions6::up_right);
    ASSERT_EQ(dirn::vertical_directions6::down.left_direction(), dirn::vertical_directions6::down_right);
    ASSERT_EQ(dirn::vertical_directions6::down_left.left_direction(), dirn::vertical_directions6::down);
    ASSERT_EQ(dirn::vertical_directions6::up_left.left_direction(), dirn::vertical_directions6::down_left);
}

TEST(vertical_directions6_tests, vertical_direction6__right_direction)
{
    ASSERT_EQ(dirn::vertical_directions6::up.right_direction(), dirn::vertical_directions6::up_right);
    ASSERT_EQ(dirn::vertical_directions6::up_right.right_direction(), dirn::vertical_directions6::down_right);
    ASSERT_EQ(dirn::vertical_directions6::down_right.right_direction(), dirn::vertical_directions6::down);
    ASSERT_EQ(dirn::vertical_directions6::down.right_direction(), dirn::vertical_directions6::down_left);
    ASSERT_EQ(dirn::vertical_directions6::down_left.right_direction(), dirn::vertical_directions6::up_left);
    ASSERT_EQ(dirn::vertical_directions6::up_left.right_direction(), dirn::vertical_directions6::up);
}

TEST(vertical_directions6_tests, vertical_direction6__opposed_direction)
{
    ASSERT_EQ(dirn::vertical_directions6::up.opposed_direction(), dirn::vertical_directions6::down);
    ASSERT_EQ(dirn::vertical_directions6::up_right.opposed_direction(), dirn::vertical_directions6::down_left);
    ASSERT_EQ(dirn::vertical_directions6::down_right.opposed_direction(), dirn::vertical_directions6::up_left);
    ASSERT_EQ(dirn::vertical_directions6::down.opposed_direction(), dirn::vertical_directions6::up);
    ASSERT_EQ(dirn::vertical_directions6::down_left.opposed_direction(), dirn::vertical_directions6::up_right);
    ASSERT_EQ(dirn::vertical_directions6::up_left.opposed_direction(), dirn::vertical_directions6::down_right);
}

TEST(vertical_directions6_tests, vertical_direction6__other_directions)
{
    dirn::vertical_direction6 up = dirn::vertical_directions6::up;
    dirn::vertical_direction6 up_right = dirn::vertical_directions6::up_right;
    dirn::vertical_direction6 down_right = dirn::vertical_directions6::down_right;
    dirn::vertical_direction6 down = dirn::vertical_directions6::down;
    dirn::vertical_direction6 down_left = dirn::vertical_directions6::down_left;
    dirn::vertical_direction6 up_left = dirn::vertical_directions6::up_left;

    ASSERT_EQ(up.other_directions(), (std::array{ up_right, down_right, down, down_left, up_left }));
    ASSERT_EQ(up_right.other_directions(), (std::array{ up, down_right, down, down_left, up_left }));
    ASSERT_EQ(down_right.other_directions(), (std::array{ up, up_right, down, down_left, up_left }));
    ASSERT_EQ(down.other_directions(), (std::array{ up, up_right, down_right, down_left, up_left }));
    ASSERT_EQ(down_left.other_directions(), (std::array{ up, up_right, down_right, down, up_left }));
    ASSERT_EQ(up_left.other_directions(), (std::array{ up, up_right, down_right, down, down_left }));
}

TEST(vertical_directions6_tests, vertical_direction6__hash)
{
    std::hash<dirn::vertical_direction6> dir_hash;
    ASSERT_EQ(dir_hash(dirn::vertical_directions6::up), static_cast<std::size_t>(dirn::vertical_directions6::up.index()));
    ASSERT_EQ(dir_hash(dirn::vertical_directions6::up_right), static_cast<std::size_t>(dirn::vertical_directions6::up_right.index()));
    ASSERT_EQ(dir_hash(dirn::vertical_directions6::down_right), static_cast<std::size_t>(dirn::vertical_directions6::down_right.index()));
    ASSERT_EQ(dir_hash(dirn::vertical_directions6::down), static_cast<std::size_t>(dirn::vertical_directions6::down.index()));
    ASSERT_EQ(dir_hash(dirn::vertical_directions6::down_left), static_cast<std::size_t>(dirn::vertical_directions6::down_left.index()));
    ASSERT_EQ(dir_hash(dirn::vertical_directions6::up_left), static_cast<std::size_t>(dirn::vertical_directions6::up_left.index()));
}
