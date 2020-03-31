#include <iostream>
#include <vector>
#include <chrono>

struct Record {
    int key;
};

void shake(std::vector<Record> &array) {
    int N = array.size();
    srand(0);
    for (int i = 0; i < N; ++i) {
        array[i].key = rand() % 100 + 1;
    }
}

void print(std::vector<Record> &array) {
    int N = array.size();
    for (int i = 0; i < N; ++i) {
        printf(" A[%2d] = %3d\n", i, array[i].key);
    }
}

void shakeSort(std::vector<Record> &array) {
    double compCount = 0;
    auto start = std::chrono::high_resolution_clock::now();

    // code

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    // std::cout << "After shell sort:" << std::endl;
    // print(array);
    std::cout << "Comparisons: " << compCount << std::endl
              << "Time spend: " << duration.count() << "s" << std::endl
              << std::endl;
}

void shellSort(std::vector<Record> &array) {
    int step, i, j;
    int size = array.size();
    double compCount = 0;
    auto start = std::chrono::high_resolution_clock::now();

    // code

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    // std::cout << "After shell sort:" << std::endl;
    // print(array);
    std::cout << "Comparisons: " << compCount << std::endl
              << "Time spend: " << duration.count() << "s" << std::endl
              << std::endl;
}

int main() {
    using namespace std;
    vector<Record> array(20000);

    shake(array);
    shakeSort(array);

    shake(array);
    shellSort(array);

    return 0;
}
