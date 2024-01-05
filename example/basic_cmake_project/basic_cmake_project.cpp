#include <arba/dirn/d2/directions4.hpp>
#include <arba/dirn/version.hpp>
#include <iostream>

int main()
{
    std::cout << dirn::directions4::to_string_view(dirn::directions4::up) << std::endl;
    return EXIT_SUCCESS;
}
