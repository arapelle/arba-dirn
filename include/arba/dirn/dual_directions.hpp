#pragma once

#include "directions.hpp"
#include "dual_directions_decl.hpp"

inline namespace arba
{
namespace dirn
{

template <class DirectionType>
class dual_directions : public directions<DirectionType>
{
private:
    using base_ = directions<DirectionType>;

public:
    using typename base_::direction;

private:
    inline static constexpr std::array<direction, base_::cardinality> opposed_directions_()
    {
        std::array dirs = base_::valid_directions;
        for (auto& dir : dirs)
            dir = dir.opposed_direction();
        return dirs;
    }

public:
    inline static constexpr std::array<direction, base_::cardinality> opposed_directions = opposed_directions_();
};

}
}
