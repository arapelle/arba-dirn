#include <dirn/directions4.hpp>
#include <dirn/cartographic_directions4.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

// directions4_base

TEST(dirn_tests, directions4_base_count)
{
    ASSERT_EQ(dirn::directions4_base::count, 4);
}

// directions4

TEST(dirn_tests, direction4_value)
{
    ASSERT_EQ(dirn::directions4::up, 0);
    ASSERT_EQ(dirn::directions4::up.index(), 0);
    ASSERT_EQ(dirn::directions4::right, 1);
    ASSERT_EQ(dirn::directions4::right.index(), 1);
    ASSERT_EQ(dirn::directions4::right, 1);
    ASSERT_EQ(dirn::directions4::right.index(), 1);
    ASSERT_EQ(dirn::directions4::left, 3);
    ASSERT_EQ(dirn::directions4::left.index(), 3);

    ASSERT_EQ(dirn::directions4::bad_direction, -1);
    ASSERT_EQ(dirn::directions4::bad_direction.index(), -1);
    ASSERT_EQ(dirn::directions4::undefined_direction, -2);
    ASSERT_EQ(dirn::directions4::undefined_direction.index(), -2);
}

// cartographic_directions4

TEST(dirn_tests, cartographic_direction4_value)
{
    ASSERT_EQ(dirn::cartographic_directions4::north, 0);
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

// directions4 == cartographic_directions4

TEST(dirn_tests, directions4_equals_cartographic_directions4)
{
    ASSERT_EQ(dirn::directions4::up.index(), dirn::cartographic_directions4::north);
    ASSERT_EQ(dirn::directions4::right.index(), dirn::cartographic_directions4::east);
    ASSERT_EQ(dirn::directions4::down.index(), dirn::cartographic_directions4::south);
    ASSERT_EQ(dirn::directions4::left.index(), dirn::cartographic_directions4::west);

    ASSERT_EQ(dirn::directions4::bad_direction.index(), dirn::cartographic_directions4::bad_direction);
    ASSERT_EQ(dirn::directions4::undefined_direction.index(), dirn::cartographic_directions4::undefined_direction);
}

//-----

TEST(dirn_tests, direction4_is_valid)
{
    ASSERT_TRUE(dirn::directions4::up.is_valid());
    ASSERT_TRUE(dirn::directions4::right.is_valid());
    ASSERT_TRUE(dirn::directions4::down.is_valid());
    ASSERT_TRUE(dirn::directions4::left.is_valid());

    ASSERT_FALSE(dirn::directions4::bad_direction.is_valid());
    ASSERT_FALSE(dirn::directions4::undefined_direction.is_valid());
}

TEST(dirn_tests, direction4_is_bad)
{
    ASSERT_FALSE(dirn::directions4::up.is_bad());
    ASSERT_FALSE(dirn::directions4::right.is_bad());
    ASSERT_FALSE(dirn::directions4::down.is_bad());
    ASSERT_FALSE(dirn::directions4::left.is_bad());

    ASSERT_TRUE(dirn::directions4::bad_direction.is_bad());
    ASSERT_FALSE(dirn::directions4::undefined_direction.is_bad());
}

TEST(dirn_tests, direction4_is_defined)
{
    ASSERT_TRUE(dirn::directions4::up.is_defined());
    ASSERT_TRUE(dirn::directions4::right.is_defined());
    ASSERT_TRUE(dirn::directions4::down.is_defined());
    ASSERT_TRUE(dirn::directions4::left.is_defined());

    ASSERT_TRUE(dirn::directions4::bad_direction.is_defined());
    ASSERT_FALSE(dirn::directions4::undefined_direction.is_defined());
}

TEST(dirn_tests, direction4_is_undefined)
{
    ASSERT_FALSE(dirn::directions4::up.is_undefined());
    ASSERT_FALSE(dirn::directions4::right.is_undefined());
    ASSERT_FALSE(dirn::directions4::down.is_undefined());
    ASSERT_FALSE(dirn::directions4::left.is_undefined());

    ASSERT_FALSE(dirn::directions4::bad_direction.is_undefined());
    ASSERT_TRUE(dirn::directions4::undefined_direction.is_undefined());
}


TEST(dirn_tests, direction4_left)
{
    ASSERT_EQ(dirn::directions4::up.left(), dirn::directions4::left);
    ASSERT_EQ(dirn::directions4::right.left(), dirn::directions4::up);
    ASSERT_EQ(dirn::directions4::down.left(), dirn::directions4::right);
    ASSERT_EQ(dirn::directions4::left.left(), dirn::directions4::down);
}

TEST(dirn_tests, direction4_right)
{
    ASSERT_EQ(dirn::directions4::up.right(), dirn::directions4::right);
    ASSERT_EQ(dirn::directions4::right.right(), dirn::directions4::down);
    ASSERT_EQ(dirn::directions4::down.right(), dirn::directions4::left);
    ASSERT_EQ(dirn::directions4::left.right(), dirn::directions4::up);
}

TEST(dirn_tests, direction4_opposed)
{
    ASSERT_EQ(dirn::directions4::up.opposed(), dirn::directions4::down);
    ASSERT_EQ(dirn::directions4::right.opposed(), dirn::directions4::left);
    ASSERT_EQ(dirn::directions4::down.opposed(), dirn::directions4::up);
    ASSERT_EQ(dirn::directions4::left.opposed(), dirn::directions4::right);
}

//-----

TEST(dirn_tests, directions4_directions)
{
    dirn::direction4 up = dirn::directions4::up;
    dirn::direction4 right = dirn::directions4::right;
    dirn::direction4 down = dirn::directions4::down;
    dirn::direction4 left = dirn::directions4::left;
    ASSERT_EQ(dirn::directions4::directions, (std::array{ up, right, down, left }));
}

TEST(dirn_tests, directions4_opposed_directions)
{
    dirn::direction4 up = dirn::directions4::up;
    dirn::direction4 right = dirn::directions4::right;
    dirn::direction4 down = dirn::directions4::down;
    dirn::direction4 left = dirn::directions4::left;
    ASSERT_EQ(dirn::directions4::opposed_directions, (std::array{ down, left, up, right }));
}

TEST(dirn_tests, directions4_other_directions)
{
    dirn::direction4 up = dirn::directions4::up;
    dirn::direction4 right = dirn::directions4::right;
    dirn::direction4 down = dirn::directions4::down;
    dirn::direction4 left = dirn::directions4::left;
    ASSERT_EQ(dirn::directions4::other_directions(up), (std::array{ down, left, right }));
    ASSERT_EQ(dirn::directions4::other_directions(right), (std::array{ left, up, down }));
    ASSERT_EQ(dirn::directions4::other_directions(down), (std::array{ up, right, left }));
    ASSERT_EQ(dirn::directions4::other_directions(left), (std::array{ right, down, up }));
}

TEST(dirn_tests, directions4_nth)
{
    ASSERT_EQ(dirn::directions4::nth(0), dirn::directions4::up);
    ASSERT_EQ(dirn::directions4::nth(1), dirn::directions4::right);
    ASSERT_EQ(dirn::directions4::nth(2), dirn::directions4::down);
    ASSERT_EQ(dirn::directions4::nth(3), dirn::directions4::left);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
