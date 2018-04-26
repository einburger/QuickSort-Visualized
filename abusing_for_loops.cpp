#include <iostream>

// 1. Counts number of bits that are different between two numbers.
// 2. The classic fizzbuzz problem [1 - N).
// 3. Calculates the fibonacci series up to N iterations, but overflows pretty quickly.

int main() 
{
    /* 1. */ for (int x{5}, y{8}, count{}, xy_xor{x^y}; xy_xor; count += 1 & xy_xor, xy_xor >>= 1, printf("%s", xy_xor ? "" : std::to_string(count).c_str()));
    /* 2. */ for (int i{1}, N{100}; i < N;  printf("%d: %s%s\n", i, i % 3 ? "" : "fizz", i % 5 ? "" : "buzz"), i++);
    /* 3. */ for (size_t a{}, b{1}, i{}, N{10}; i < N; std::cout << a << ' ', a = b - a, b = a + b, ++i);
    return 0;
}
