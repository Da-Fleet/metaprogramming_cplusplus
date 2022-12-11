#include <iostream>

template<int n>
struct Fibonacci
{
    static const int value = Fibonacci<n - 1>::value + Fibonacci<n - 2>::value;
};

template<>
struct Fibonacci<0>
{
    static const int value = 0;
};

template<>
struct Fibonacci<1>
{
    static const int value = 1;
};

int main()
{
    std::cout << Fibonacci<20>::value << std::endl;
}
