//
// Created by danie on 1/1/2019.
//

#ifndef EFFECTIVE_MODERN_C_COMMON_H
#define EFFECTIVE_MODERN_C_COMMON_H

#include <boost/type_index.hpp>

#define TYPE_ID(T)                         \
  std::cout << BOOST_DO_STRINGIZE(T) " = " \
            << boost::typeindex::type_id_with_cvr<T>().pretty_name() << std::endl;

#define TEMPLATE_TYPE_ID(T, ParamType, f)           \
  template <typename T>                             \
  void f(ParamType param) {                         \
    std::cout << std::endl;                         \
                                                    \
    TYPE_ID(T)                                      \
                                                    \
    TYPE_ID(decltype(param))                        \
                                                    \
    std::cout << std::endl;                         \
  };

#endif  // EFFECTIVE_MODERN_C_COMMON_H
