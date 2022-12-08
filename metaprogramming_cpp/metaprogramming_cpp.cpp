// metaprogramming_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

template<int n>
struct Fibonnacci
{
    static const int value = Fibonnacci<n - 1>::value + Fibonnacci<n - 2>::value;
};

template<>
struct Fibonnacci<0>
{

    std::cout << "Hello World" << std::endl;
    static const int value = 0;
};

template<>
struct Fibonnacci<1>
{
    static const int value = 1;
};

#include <iostream>

int main()
{
    std::cout << Fibonnacci<10>::value << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
