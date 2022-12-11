// metaprogramming_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


#pragma region Fibonacci

template<int n>
struct Fibonnacci
{
    static const int value = Fibonnacci<n - 1>::value + Fibonnacci<n - 2>::value;
};

template<>
struct Fibonnacci<0>
{
    static const int value = 0;
};

template<>
struct Fibonnacci<1>
{
    static const int value = 1;
};

#pragma endregion

#pragma region ForLoop

//static unroller
template <typename Action, int Begin, int End, int Step = 1>
struct UnrollerS {
    static void step() {
        Action::action(Begin);
        UnrollerS<Action, Begin+Step, End, Step>::step();
    }
};
//end of static unroller
template <typename Action, int End, int Step>
struct UnrollerS<Action, End, End, Step> {
    static void step() { }
};

//dynamic unroller
template <typename Action, int Begin, int End, int Step = 1>
struct UnrollerD {
    static void step(Action& a) {
        a.action(Begin);
        UnrollerD<Action, Begin+Step, End>::step(a);
    }
};
//end of dynamic unroller
template <typename Action, int End, int Step>
struct UnrollerD<Action, End, End, Step> {
    static void step(Action& a) { }
};

#pragma endregion

struct Printer{
    static void action(int i) {
        printf("%d\n", i);
    }
};

int main()
{
    UnrollerS<Printer, 10, 20>::step();
    //std::cout << Fibonnacci<9>::value << std::endl;
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
