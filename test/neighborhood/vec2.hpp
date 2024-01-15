#include <compare>

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
