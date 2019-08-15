#ifndef UTILS_RANDOM_HPP
#define UTILS_RANDOM_HPP

#include <iostream>
#include <string>

namespace utils
{
    int rnd_int_range(int min, int max);

    namespace io
    {
        int int_value(std::ostream &os, std::istream &is, const std::string& prompt, const std::string& error);

        int int_range(std::ostream &os, std::istream &is, int min, int max, const std::string& prompt, const std::string& error);
    }

}

#endif //UTILS_RANDOM_HPP
