# Concept

The purpose is to provide simple C++ tools to manage directions, like { Up, Right, Down, Left } or { North, East, South, West }.

See [task board](https://app.gitkraken.com/glo/board/X1n3iyQxbQAR7dFE) for future updates and features.

# Install

## Requirements

Binaries:

- A C++20 compiler (ex: g++-10)
- CMake 3.16 or later

Libraries:

- [Google Test](https://github.com/google/googletest) 1.10 or later (only for testing)

## Clone

```
git clone https://github.com/arapelle/dirn --recurse-submodules
```

## Quick Install

There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).

```
cd /path/to/dirn
cmake -P cmake_quick_install.cmake
```

Use the following to quickly install a different mode.

```
cmake -DCMAKE_BUILD_TYPE=Debug -P cmake_quick_install.cmake
```

## Uninstall

There is a uninstall cmake script created during installation. You can use it to uninstall properly this library.

```
cd /path/to/installed-dirn/
cmake -P cmake_uninstall.cmake
```

# How to use

## Example - Display the basic and cartographic names for each direction

```c++
#include <iostream>
#include <dirn/directions4.hpp>
#include <dirn/cartographic_directions4.hpp>

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
#include <dirn/directions4.hpp>
#include <dirn/neighbourhood.hpp>

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

See the [basic cmake project](https://github.com/arapelle/dirn/tree/master/example/basic_cmake_project) example, and more specifically the [CMakeLists.txt](https://github.com/arapelle/dirn/tree/master/example/basic_cmake_project/CMakeLists.txt) to see how to use *dirn* in your CMake projects.

# License

[MIT License](https://github.com/arapelle/dirn/blob/master/LICENSE.md) © dirn