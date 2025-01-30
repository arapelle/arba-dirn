#include <arba/dirn/d2/dir6/horizontal_directions6.hpp>

#include <gtest/gtest.h>

#include <cstdlib>

// horizontal_directions6

TEST(horizontal_directions6_tests, horizontal_directions6_cardinality)
{
    ASSERT_EQ(dirn::horizontal_directions6::cardinality, 6);
}

TEST(horizontal_directions6_tests, horizontal_direction6_value)
{
    ASSERT_EQ(arba::dirn::d2::horizontal_directions6::left, 0);
    ASSERT_EQ(dirn::d2::horizontal_directions6::left.index(), 0);
    ASSERT_EQ(dirn::horizontal_directions6::left_up, 1);
    ASSERT_EQ(dirn::horizontal_directions6::left_up.index(), 1);
    ASSERT_EQ(dirn::horizontal_directions6::right_up, 2);
    ASSERT_EQ(dirn::horizontal_directions6::right_up.index(), 2);
    ASSERT_EQ(dirn::horizontal_directions6::right, 3);
    ASSERT_EQ(dirn::horizontal_directions6::right.index(), 3);
    ASSERT_EQ(dirn::horizontal_directions6::right_down, 4);
    ASSERT_EQ(dirn::horizontal_directions6::right_down.index(), 4);
    ASSERT_EQ(dirn::horizontal_directions6::left_down, 5);
    ASSERT_EQ(dirn::horizontal_directions6::left_down.index(), 5);

    ASSERT_EQ(dirn::horizontal_directions6::bad_direction, -1);
    ASSERT_EQ(dirn::horizontal_directions6::bad_direction.index(), -1);
    ASSERT_EQ(dirn::horizontal_directions6::undefined_direction, -2);
    ASSERT_EQ(dirn::horizontal_directions6::undefined_direction.index(), -2);
}

TEST(horizontal_directions6_tests, horizontal_direction6_to_string_view)
{
    ASSERT_EQ(dirn::d2::horizontal_directions6::to_string_view(dirn::horizontal_directions6::left), "left");
    ASSERT_EQ(dirn::horizontal_directions6::to_string_view(dirn::horizontal_directions6::left_up), "left_up");
    ASSERT_EQ(dirn::horizontal_directions6::to_string_view(dirn::horizontal_directions6::right_up), "right_up");
    ASSERT_EQ(dirn::horizontal_directions6::to_string_view(dirn::horizontal_directions6::right), "right");
    ASSERT_EQ(dirn::horizontal_directions6::to_string_view(dirn::horizontal_directions6::right_down), "right_down");
    ASSERT_EQ(dirn::horizontal_directions6::to_string_view(dirn::horizontal_directions6::left_down), "left_down");
    ASSERT_EQ(dirn::horizontal_directions6::to_string_view(dirn::horizontal_directions6::bad_direction), "bad");
    ASSERT_EQ(dirn::horizontal_directions6::to_string_view(dirn::horizontal_directions6::undefined_direction),
              "undefined");
}

TEST(horizontal_directions6_tests, horizontal_direction6_to_char)
{
    ASSERT_EQ(dirn::horizontal_directions6::to_char(dirn::horizontal_directions6::left), 'L');
    ASSERT_EQ(dirn::horizontal_directions6::to_char(dirn::horizontal_directions6::left_up), 'U');
    ASSERT_EQ(dirn::horizontal_directions6::to_char(dirn::horizontal_directions6::right_up), 'V');
    ASSERT_EQ(dirn::horizontal_directions6::to_char(dirn::horizontal_directions6::right), 'R');
    ASSERT_EQ(dirn::horizontal_directions6::to_char(dirn::horizontal_directions6::right_down), 'B');
    ASSERT_EQ(dirn::horizontal_directions6::to_char(dirn::horizontal_directions6::left_down), 'D');
    ASSERT_EQ(dirn::horizontal_directions6::to_char(dirn::horizontal_directions6::bad_direction), '%');
    ASSERT_EQ(dirn::horizontal_directions6::to_char(dirn::horizontal_directions6::undefined_direction), '?');
}

TEST(horizontal_directions6_tests, horizontal_directions6__valid_directions)
{
    dirn::horizontal_direction6 left = dirn::horizontal_directions6::left;
    dirn::horizontal_direction6 left_up = dirn::horizontal_directions6::left_up;
    dirn::horizontal_direction6 right_up = dirn::horizontal_directions6::right_up;
    dirn::horizontal_direction6 right = dirn::horizontal_directions6::right;
    dirn::horizontal_direction6 right_down = dirn::horizontal_directions6::right_down;
    dirn::horizontal_direction6 left_down = dirn::horizontal_directions6::left_down;
    ASSERT_EQ(dirn::horizontal_directions6::valid_directions,
              (std::array{ left, left_up, right_up, right, right_down, left_down }));
}

TEST(horizontal_directions6_tests, horizontal_directions6__opposed_directions)
{
    dirn::horizontal_direction6 left = dirn::horizontal_directions6::left;
    dirn::horizontal_direction6 left_up = dirn::horizontal_directions6::left_up;
    dirn::horizontal_direction6 right_up = dirn::horizontal_directions6::right_up;
    dirn::horizontal_direction6 right = dirn::horizontal_directions6::right;
    dirn::horizontal_direction6 right_down = dirn::horizontal_directions6::right_down;
    dirn::horizontal_direction6 left_down = dirn::horizontal_directions6::left_down;
    ASSERT_EQ(dirn::horizontal_directions6::opposed_directions,
              (std::array{ right, right_down, left_down, left, left_up, right_up }));
}

TEST(horizontal_directions6_tests, horizontal_directions6__nth)
{
    ASSERT_EQ(dirn::horizontal_directions6::nth(0), dirn::horizontal_directions6::left);
    ASSERT_EQ(dirn::horizontal_directions6::nth(1), dirn::horizontal_directions6::left_up);
    ASSERT_EQ(dirn::horizontal_directions6::nth(2), dirn::horizontal_directions6::right_up);
    ASSERT_EQ(dirn::horizontal_directions6::nth(3), dirn::horizontal_directions6::right);
    ASSERT_EQ(dirn::horizontal_directions6::nth(4), dirn::horizontal_directions6::right_down);
    ASSERT_EQ(dirn::horizontal_directions6::nth(5), dirn::horizontal_directions6::left_down);
}

// horizontal_direction6

TEST(horizontal_directions6_tests, horizontal_direction6_cardinality)
{
    ASSERT_EQ(dirn::horizontal_direction6::cardinality, 6);
}

TEST(horizontal_directions6_tests, horizontal_direction6_is_valid)
{
    ASSERT_TRUE(dirn::horizontal_directions6::left.is_valid());
    ASSERT_TRUE(dirn::horizontal_directions6::left_up.is_valid());
    ASSERT_TRUE(dirn::horizontal_directions6::right_up.is_valid());
    ASSERT_TRUE(dirn::horizontal_directions6::right.is_valid());
    ASSERT_TRUE(dirn::horizontal_directions6::right_down.is_valid());
    ASSERT_TRUE(dirn::horizontal_directions6::left_down.is_valid());

    ASSERT_FALSE(dirn::horizontal_directions6::bad_direction.is_valid());
    ASSERT_FALSE(dirn::horizontal_directions6::undefined_direction.is_valid());
}

TEST(horizontal_directions6_tests, horizontal_direction6_is_bad)
{
    ASSERT_FALSE(dirn::horizontal_directions6::left.is_bad());
    ASSERT_FALSE(dirn::horizontal_directions6::left_up.is_bad());
    ASSERT_FALSE(dirn::horizontal_directions6::right_up.is_bad());
    ASSERT_FALSE(dirn::horizontal_directions6::right.is_bad());
    ASSERT_FALSE(dirn::horizontal_directions6::right_down.is_bad());
    ASSERT_FALSE(dirn::horizontal_directions6::left_down.is_bad());

    ASSERT_TRUE(dirn::horizontal_directions6::bad_direction.is_bad());
    ASSERT_FALSE(dirn::horizontal_directions6::undefined_direction.is_bad());
}

TEST(horizontal_directions6_tests, horizontal_direction6_is_defined)
{
    ASSERT_TRUE(dirn::horizontal_directions6::left.is_defined());
    ASSERT_TRUE(dirn::horizontal_directions6::left_up.is_defined());
    ASSERT_TRUE(dirn::horizontal_directions6::right_up.is_defined());
    ASSERT_TRUE(dirn::horizontal_directions6::right.is_defined());
    ASSERT_TRUE(dirn::horizontal_directions6::right_down.is_defined());
    ASSERT_TRUE(dirn::horizontal_directions6::left_down.is_defined());

    ASSERT_TRUE(dirn::horizontal_directions6::bad_direction.is_defined());
    ASSERT_FALSE(dirn::horizontal_directions6::undefined_direction.is_defined());
}

TEST(horizontal_directions6_tests, horizontal_direction6_is_undefined)
{
    ASSERT_FALSE(dirn::horizontal_directions6::left.is_undefined());
    ASSERT_FALSE(dirn::horizontal_directions6::left_up.is_undefined());
    ASSERT_FALSE(dirn::horizontal_directions6::right_up.is_undefined());
    ASSERT_FALSE(dirn::horizontal_directions6::right.is_undefined());
    ASSERT_FALSE(dirn::horizontal_directions6::right_down.is_undefined());
    ASSERT_FALSE(dirn::horizontal_directions6::left_down.is_undefined());

    ASSERT_FALSE(dirn::horizontal_directions6::bad_direction.is_undefined());
    ASSERT_TRUE(dirn::horizontal_directions6::undefined_direction.is_undefined());
}

TEST(horizontal_directions6_tests, horizontal_direction6__left_direction)
{
    ASSERT_EQ(dirn::horizontal_directions6::left.left_direction(), dirn::horizontal_directions6::left_down);
    ASSERT_EQ(dirn::horizontal_directions6::left_up.left_direction(), dirn::horizontal_directions6::left);
    ASSERT_EQ(dirn::horizontal_directions6::right_up.left_direction(), dirn::horizontal_directions6::left_up);
    ASSERT_EQ(dirn::horizontal_directions6::right.left_direction(), dirn::horizontal_directions6::right_up);
    ASSERT_EQ(dirn::horizontal_directions6::right_down.left_direction(), dirn::horizontal_directions6::right);
    ASSERT_EQ(dirn::horizontal_directions6::left_down.left_direction(), dirn::horizontal_directions6::right_down);
}

TEST(horizontal_directions6_tests, horizontal_direction6__right_direction)
{
    ASSERT_EQ(dirn::horizontal_directions6::left.right_direction(), dirn::horizontal_directions6::left_up);
    ASSERT_EQ(dirn::horizontal_directions6::left_up.right_direction(), dirn::horizontal_directions6::right_up);
    ASSERT_EQ(dirn::horizontal_directions6::right_up.right_direction(), dirn::horizontal_directions6::right);
    ASSERT_EQ(dirn::horizontal_directions6::right.right_direction(), dirn::horizontal_directions6::right_down);
    ASSERT_EQ(dirn::horizontal_directions6::right_down.right_direction(), dirn::horizontal_directions6::left_down);
    ASSERT_EQ(dirn::horizontal_directions6::left_down.right_direction(), dirn::horizontal_directions6::left);
}

TEST(horizontal_directions6_tests, horizontal_direction6__opposed_direction)
{
    ASSERT_EQ(dirn::horizontal_directions6::left.opposed_direction(), dirn::horizontal_directions6::right);
    ASSERT_EQ(dirn::horizontal_directions6::left_up.opposed_direction(), dirn::horizontal_directions6::right_down);
    ASSERT_EQ(dirn::horizontal_directions6::right_up.opposed_direction(), dirn::horizontal_directions6::left_down);
    ASSERT_EQ(dirn::horizontal_directions6::right.opposed_direction(), dirn::horizontal_directions6::left);
    ASSERT_EQ(dirn::horizontal_directions6::right_down.opposed_direction(), dirn::horizontal_directions6::left_up);
    ASSERT_EQ(dirn::horizontal_directions6::left_down.opposed_direction(), dirn::horizontal_directions6::right_up);
}

TEST(horizontal_directions6_tests, horizontal_direction6__other_directions)
{
    dirn::horizontal_direction6 left = dirn::horizontal_directions6::left;
    dirn::horizontal_direction6 left_up = dirn::horizontal_directions6::left_up;
    dirn::horizontal_direction6 right_up = dirn::horizontal_directions6::right_up;
    dirn::horizontal_direction6 right = dirn::horizontal_directions6::right;
    dirn::horizontal_direction6 right_down = dirn::horizontal_directions6::right_down;
    dirn::horizontal_direction6 left_down = dirn::horizontal_directions6::left_down;

    ASSERT_EQ(left.other_directions(), (std::array{ left_up, right_up, right, right_down, left_down }));
    ASSERT_EQ(left_up.other_directions(), (std::array{ left, right_up, right, right_down, left_down }));
    ASSERT_EQ(right_up.other_directions(), (std::array{ left, left_up, right, right_down, left_down }));
    ASSERT_EQ(right.other_directions(), (std::array{ left, left_up, right_up, right_down, left_down }));
    ASSERT_EQ(right_down.other_directions(), (std::array{ left, left_up, right_up, right, left_down }));
    ASSERT_EQ(left_down.other_directions(), (std::array{ left, left_up, right_up, right, right_down }));
}

TEST(horizontal_directions6_tests, horizontal_direction6__hash)
{
    std::hash<dirn::horizontal_direction6> dir_hash;
    ASSERT_EQ(dir_hash(dirn::horizontal_directions6::left),
              static_cast<std::size_t>(dirn::horizontal_directions6::left.index()));
    ASSERT_EQ(dir_hash(dirn::horizontal_directions6::left_up),
              static_cast<std::size_t>(dirn::horizontal_directions6::left_up.index()));
    ASSERT_EQ(dir_hash(dirn::horizontal_directions6::right_up),
              static_cast<std::size_t>(dirn::horizontal_directions6::right_up.index()));
    ASSERT_EQ(dir_hash(dirn::horizontal_directions6::right),
              static_cast<std::size_t>(dirn::horizontal_directions6::right.index()));
    ASSERT_EQ(dir_hash(dirn::horizontal_directions6::right_down),
              static_cast<std::size_t>(dirn::horizontal_directions6::right_down.index()));
    ASSERT_EQ(dir_hash(dirn::horizontal_directions6::left_down),
              static_cast<std::size_t>(dirn::horizontal_directions6::left_down.index()));
}
