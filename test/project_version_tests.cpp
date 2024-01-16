#include <arba/dirn/version.hpp>
#include <gtest/gtest.h>

TEST(project_version_tests, test_version_core)
{
    constexpr unsigned major = 0;
    constexpr unsigned minor = 5;
    constexpr unsigned patch = 0;
    static_assert(arba::dirn::version.core() == arba::vrsn::tri_version(major, minor, patch));
}
