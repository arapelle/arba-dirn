#include <arba/dirn/version.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(project_version_tests, test_version_macros)
{
    ASSERT_EQ(ARBA_DIRN_VERSION_MAJOR, 0);
    ASSERT_EQ(ARBA_DIRN_VERSION_MINOR, 2);
    ASSERT_EQ(ARBA_DIRN_VERSION_PATCH, 0);
    ASSERT_STREQ(ARBA_DIRN_VERSION, "0.2.0");
}
