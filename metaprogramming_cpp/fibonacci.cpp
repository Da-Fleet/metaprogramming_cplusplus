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