#include <iostream>
#include <stdexcept>

// Calculate factorial (marked as noexcept)
unsigned long long factorial(int n) noexcept {
    if (n < 0)
        throw std::invalid_argument("Factorial is not defined for negative numbers");
    
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;

    return result;
}

int main() {
    try {
        int num;
        std::cout << "Enter a non-negative integer: ";
        std::cin >> num;

        std::cout << "Factorial of " << num << " is " << factorial(num) << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}