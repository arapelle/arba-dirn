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
