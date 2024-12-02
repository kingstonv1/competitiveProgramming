#include <iostream>
#include <cmath>

bool solve(unsigned long long num) {
    for (unsigned long long i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            std::cout << num << " " << i << std::endl;
            return true;
        }
    }
    return false;
}

int main() {
    unsigned long long t;
    std::cin >> t;

    for (unsigned long long i = 0; i < t; ++i) {
        std::string input;
        std::cin >> input;

        if (solve(std::stoull(input))) continue;

        for (unsigned long long idx = 0; idx < input.length(); ++idx) {
            unsigned long long num = std::stoull(input.substr(0, idx) + input.substr(idx + 1, input.length()));
            if (solve(num)) break;
        }
    }

    return 0;
}

