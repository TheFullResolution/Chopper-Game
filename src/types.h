//
// Created by Jedrzej Lewandowski on 05/02/2020.
//

#ifndef types_H
#define types_H

#include "../lib/config.h"
namespace types {

template <typename T> struct vector{
  T x;
  T y;
};

using Decoration = config::Player;
using Player = config::Player;
using Map = config::Map;

} // namespace types
#endif