#include "func.hpp"

#define MAXELEM 10000

int main() {
    std::vector<int> vec(MAXELEM);

    for (size_t i = 0; i < MAXELEM; ++i) {
        vec[i] = rand() % 1000;
    }

    //printVec(vec);

    shakeSort(vec);

    for (size_t i = 0; i < MAXELEM; ++i) {
        vec[i] = rand() % 1000;
    }

    shellSort(vec);

    return 0;
}
