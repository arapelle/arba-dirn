# Concept

The purpose is to provide simple C++ tools to manage directions, like { Up, Right, Down, Left } or { North, East, South, West }.

# Install

## Requirements

Binaries:

- A C++20 compiler (ex: g++-13)
- CMake 3.26 or later

Testing Libraries (optional):
- [Google Test](https://github.com/google/googletest) 1.13 or later (optional)

## Clone

```
git clone https://github.com/arapelle/arba-dirn --recurse-submodules
```

## Quick Install

There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).

```
cd /path/to/dirn
cmake -P cmake/scripts/quick_install.cmake
```

Use the following to quickly install a different mode.

```
cmake -P cmake/scripts/quick_install.cmake -- TESTS BUILD Debug DIR /tmp/local
```

## Uninstall

There is a uninstall cmake script created during installation. You can use it to uninstall properly this library.

```
cd /path/to/installed-arba-dirn/
cmake -P uninstall.cmake
```

# How to use

## Example - Display the basic and cartographic names for each direction

```c++
#include <iostream>
#include <arba/dirn/directions4.hpp>
#include <arba/dirn/cartographic_directions4.hpp>

int main()
{
    for (dirn::direction4 dir : dirn::directions4::directions)
    {
        std::cout << dirn::directions4::to_string_view(dir) << "    "
                  << dirn::cartographic_directions4::to_string_view(dir) << std::endl;
    }
    return EXIT_SUCCESS;
}
```

## Example - Compute neighbour position

```c++
#include <iostream>
#include <arba/dirn/directions4.hpp>
#include <arba/dirn/neighbourhood.hpp>

class vec2
{
    int x_;
    int y_;

public:
    vec2(int x = 0, int y = 0)
        : x_(x), y_(y)
    {}

    const int& x() const { return x_; }
    int& x() { return x_; }

    const int& y() const { return y_; }
    int& y() { return y_; }

    auto operator<=>(const vec2& v) const = default;
};

int main()
{
    vec2 position(0,0);
    vec2 new_position = *dirn::neighbour(position, dirn::directions4::right);
    std::cout << new_position.x() << " " << new_position.y() << std::endl;
    return EXIT_SUCCESS;
}
```

## Example - Using *dirn* in a CMake project

See the *basic_cmake_project* example, and more specifically the *CMakeLists.txt* to see how to use *dirn* in your CMake projects.

# License

[MIT License](./LICENSE.md) © arba-dirn
