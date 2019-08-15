#include "utils.hpp"

#include <random>
#include <functional>

int utils::rnd_int_range(int min, int max)
{
    static std::default_random_engine engine;
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(engine);
}

int utils::io::int_value(std::ostream &os, std::istream &is, const std::string& prompt, const std::string& error)
{
    os << prompt;
    int result = 0;

    while (!(is >> result))
    {
        os << error;
        if (is.bad()) throw std::runtime_error("stream is corrupt");
        if (is.eof()) throw std::runtime_error("stream reached end of file");
        is.clear();
        for (char c; is >> c;)
            if (!isdigit(c) && c != '-') continue;
            else is.unget();
    }

    return result;
}

int utils::io::int_range(std::ostream &os, std::istream &is, int min, int max, const std::string& prompt, const std::string& error)
{
    os << prompt;
    int result = 0;

    while (!(is >> result) || result < min || result > max)
    {
        os << error;
        if (is.bad()) throw std::runtime_error("stream is corrupt");
        if (is.eof()) throw std::runtime_error("stream reached end of file");
        is.clear();
        for (char c; is >> c;)
            if (!isdigit(c) && c != '-') continue;
            else is.unget();
    }

    return result;
}