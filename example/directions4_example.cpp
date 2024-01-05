#include <arba/dirn/d2/cartographic_directions4.hpp>
#include <arba/dirn/d2/directions4.hpp>
#include <arba/dirn/version.hpp>
#include <iostream>

int main()
{
    for (dirn::direction4 dir : dirn::directions4::directions)
    {
        std::cout << dirn::directions4::to_string_view(dir) << "    "
                  << dirn::cartographic_directions4::to_string_view(dir) << std::endl;
    }
    return EXIT_SUCCESS;
}
