#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>

template<typename T>
T sum_all(T arg)
{
    return arg;
}

template<typename T, typename... Args>
T sum_all(T arg, Args... args)
{
    return arg + sum_all(args...);
}

template<typename T>
T sum_all(const std::vector<T>& vec)
{
    T sum = 0;
    for (const auto& value : vec)
    {
        sum += value;
    }
    return sum;
}

template<>
std::string sum_all<std::string>(const std::vector<std::string>& vec)
{
    std::string result;
    for (const auto& str : vec)
    {
        result += str;
    }
    return result;
}

template<>
std::string sum_all<char>(const std::vector<char>& vec)
{
    std::string result;
    for (const auto& ch : vec)
    {
        result += ch;
    }
    return result;
}

int main()
{
    std::cout << sum_all(5) << std::endl; // 5
    std::cout << sum_all(3.0) << std::endl; // 3.0

    std::vector<int> v1 = { 1, 2, 3 };
    std::cout << sum_all(v1) << std::endl; // 6

    std::vector<double> v2 = { 1, 2, 3 };
    std::cout << sum_all(v2) << std::endl; // 6.0

    std::vector<std::string> v3 = { "a", "bc", "def" };
    std::cout << sum_all(v3) << std::endl; // "abcdef"

    std::vector<char> v4 = { 'a', 'b', 'c' };
    std::cout << sum_all(v4) << std::endl; // "abc"

    return 0;
}