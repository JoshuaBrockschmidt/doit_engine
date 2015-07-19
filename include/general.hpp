#ifndef GENERAL_H
#define GENERAL_H

#include <type_traits>

template<typename E>
constexpr auto to_integral(E e) -> typename std::underlying_type<E>::type 
{
   return static_cast<typename std::underlying_type<E>::type>(e);
}

#endif
