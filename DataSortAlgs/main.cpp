#include <iostream>
#include <vector>

#include "func.hpp"

#define MAXELEM 20

int main() {
    std::vector<int> test(MAXELEM);

    for (size_t i = 0; i < MAXELEM; ++i) {
        test[i] = rand() % 100;
    }

    std::cout << "A test on both sorts" << std::endl << std::endl;

    std::cout << "Initial array: " << std::endl;
    printVec(test);
    std::cout << std::endl << std::endl;

    shakeSort(test);

    std::cout << "Array after sort: " << std::endl;
    printVec(test);
    std::cout << std::endl << std::endl << std::endl;

    for (size_t i = 0; i < MAXELEM; ++i) {
        test[i] = rand() % 100;
    }

    std::cout << "Initial array: " << std::endl;
    printVec(test);
    std::cout << std::endl << std::endl;

    shellSort(test);

    std::cout << "Array after sort: " << std::endl;
    printVec(test);
    std::cout << std::endl;

    return 0;
}
