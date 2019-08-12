#include "utils_vector.hpp"

template<typename T>
void utils::drop_value(std::vector<T> &vec, T value)
{
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) vec.erase(it);
}

template<typename T>
void utils::drop_values_all(std::vector<T> &vec, T value)
{
    auto it = std::find_if(vec.begin(), vec.end(), [value](int it)
    { it == value; });
    if (it != vec.end()) vec.erase(it);
}

template<typename T>
T &utils::drop_random(std::vector<T> &vec)
{
    if (vec.empty()) throw std::invalid_argument("vector has no objects to choose from");

    int idx = rnd_int_range(0, vec.size())();
    T result = vec[idx];
    vec.erase(vec.begin() + idx);
    return result;
}

template<typename T>
T &utils::get_random(std::vector<T> &vec)
{
    if (vec.empty()) throw std::invalid_argument("vector has no objects to choose from");
    return vec[rnd_int_range(0, vec.size())()];
}
