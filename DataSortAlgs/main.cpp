#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Record
{
    int key;
};

void shake(std::vector<Record> &array)
{
    int N = array.size();
    srand(0);
    for (int i = 0; i < N; ++i)
    {
        array[i].key = rand() % 100 + 1;
    }
}

void print(std::vector<Record> &array)
{
    int N = array.size();
    for (int i = 0; i < N; ++i)
    {
        printf(" A[%2d] = %3d\n", i, array[i].key);
    }
}

void shakeSort(std::vector<Record> &array)
{
    int compCount = 0;
    clock_t t_start = clock();

    // code

    clock_t t_stop = clock();
    std::cout << "After shell sort:" << std::endl;
    print(array);
    std::cout << "Comparisons: " << compCount << std::endl
              << "Time spend: " << (double)(t_start - t_stop) / (double)CLOCKS_PER_SEC << std::endl
              << std::endl;
}

void shellSort(std::vector<Record> &array)
{
    int compCount = 0;
    clock_t t_start = clock();

    // code

    clock_t t_stop = clock();
    std::cout << "After shell sort:" << std::endl;
    print(array);
    std::cout << "Comparisons: " << compCount << std::endl
              << "Time spend: " << (double)(t_start - t_stop) / (double)CLOCKS_PER_SEC << std::endl
              << std::endl;
}

int main()
{
    using namespace std;
    int N = 20;
    vector<Record> array(N);

    shake(array);

    cout << "Original array:" << endl;
    print(array);
    cout << endl;

    shakeSort(array);

    shake(array);

    shellSort(array);

    return 0;
}
