#include "func.hpp"

#define MAXELEM 10000

int main() 
{
    std::vector<int> test(10);

    for (size_t i = 0; i < 10; ++i)
    {
        test[i] = rand() % 1000;
    }

    std::cout << "A test on both sorts" << std::endl << std::endl;
    std::cout << "Initial array: ";
    printVec(test);
    shakeSort(test);
    std::cout << "Array after sort: ";
    printVec(test);
    std::cout << std::endl;
    for (size_t i = 0; i < 10; ++i)
    {
        test[i] = rand() % 1000;
    }
    std::cout << "Initial array: ";
    printVec(test);

    shellSort(test);

    std::cout << "Array after sort: ";
    std::cout << std::endl;
    printVec(test);
    std::cout << std::endl;

    std::cout << "A test on a 10000 element array" << std::endl;

    std::vector<int> vec(MAXELEM);

    for (size_t i = 0; i < MAXELEM; ++i) 
    {
        vec[i] = rand() % 1000;
    }

    

    shakeSort(vec);
    

    for (size_t i = 0; i < MAXELEM; ++i)
    {
        vec[i] = rand() % 1000;
    }
    
    

    shellSort(vec);



    return 0;
}
