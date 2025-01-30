# Concept

The purpose is to provide simple C++ tools to manage directions, like { up, right, down, left } or { north, east, south, west } 
in different tiled spaces."

# Install

## Requirements

Binaries:
- A C++20 compiler (ex: g++-14)
- CMake 3.26 or later

Testing Libraries (optional):
- [Google Test](https://github.com/google/googletest) 1.14 or later (optional)

## Clone

```
git clone https://github.com/arapelle/arba-dirn
```

## Use with `conan`

Create the conan package.
```
conan create . --build=missing -c
```
Add a requirement in your conanfile project file.
```python
    def requirements(self):
        self.requires("arba-dirn/0.5.0")
```

## Quick Install

There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).

```
cd /path/to/arba-dirn
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

## Example - Compute neighbor position

```c++
#include <arba/dirn/d2/directions4.hpp>
#include <iostream>

class vec2
{
    int x_;
    int y_;

public:
    vec2(int x = 0, int y = 0) : x_(x), y_(y) {}

    const int& x() const { return x_; }
    int& x() { return x_; }

    const int& y() const { return y_; }
    int& y() { return y_; }

    vec2 operator+(const vec2& rhs) const { return vec2(x_ + rhs.x_, y_ + rhs.y_); }

    auto operator<=>(const vec2& v) const = default;
};

int main()
{
    vec2 position(0, 0);
    vec2 new_position = dirn::neighbor(position, dirn::directions4::right);
    std::cout << new_position.x() << " " << new_position.y() << std::endl;
    return EXIT_SUCCESS;
}
```

# License

[MIT License](./LICENSE.md) © arba-dirn
