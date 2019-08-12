#ifndef UTILS_VECTOR_HPP
#define UTILS_VECTOR_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

#include "utils_random.hpp"

namespace utils
{
    template<typename T>
    void drop_value(std::vector<T> &vec, T value);

    template<typename T>
    void drop_values_all(std::vector<T> &vec, T value);

    template<typename T>
    T &drop_random(std::vector<T> &vec);

    template<typename T>
    T &get_random(std::vector<T> &vec);
}

#endif //UTILS_VECTOR_HPP
