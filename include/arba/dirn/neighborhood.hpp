#pragma once

#include <array>

inline namespace arba
{
namespace dirn
{

template <class DirectionType, class VecType>
class neighborhood;

template <class DirectionType, class VecType>
auto neighbor(const VecType& vec, DirectionType dir)
{
    return neighborhood<DirectionType, VecType>::neighbor(vec, dir);
}

template <class DirectionType, class VecType>
auto neighbors(const VecType& vec)
{
    return neighborhood<DirectionType, VecType>::neighbors(vec);
}

template <class DirectionType, class VecType>
void neighbors(const VecType& vec, std::array<VecType, DirectionType::cardinality>& neighbors)
{
    neighborhood<DirectionType, VecType>::neighbors(vec, neighbors);
}

} // namespace dirn
} // namespace arba
