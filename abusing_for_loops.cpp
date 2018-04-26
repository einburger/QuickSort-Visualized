#include <iostream>

int main() 
{

    // fibonacci up to N iterations but overflows pretty quickly
    for (size_t a{}, b{1}, i{}, N{10}; i < N; std::cout << a << ' ', a = b - a, b = a + b, ++i);

    // number of bits different between two numbers (5 and 8 here)
    int count{};
    for (int x{5}, y{8}, xy_xor{x^y}; xy_xor; count += 1 & xy_xor, xy_xor >>= 1);

    // fizz buzz problem for 1 - 100
    for (int i{1}, N{100}; i < N; 
        [&]{ 
            std::cout << i << ": "; 
            if (i % 3 == 0) { std::cout << "fizz "; } 
            if (i % 5 == 0) { std::cout << "buzz "; } 
            i++;
        }() );

    return 0;
}
