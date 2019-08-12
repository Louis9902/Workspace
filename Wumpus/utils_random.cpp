#include "utils_random.hpp"

auto utils::rnd_int_range(int min, int max)
{
    static std::default_random_engine engine;
    std::uniform_int_distribution<int> distribution(min, max);
    return std::bind(distribution, engine);
}
