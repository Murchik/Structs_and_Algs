#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Record
{
    int key;
};

void swap(std::vector<Record> &array, int i, int j)
{
    Record tmp;

    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

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
    int size = array.size();
    double compCount = 0;
    clock_t t_start = clock();

    // code

    clock_t t_stop = clock();
    std::cout << "After shell sort:" << std::endl;
    //print(array);
    std::cout << "Comparisons: " << compCount << std::endl
              << "Time spend: " << (double)(t_stop - t_start) / (double)CLOCKS_PER_SEC << "s" << std::endl
              << std::endl;
}

void shellSort(std::vector<Record> &array)
{
    int step, i, j;
    int size = array.size();
    double compCount = 0;
    clock_t t_start = clock();

    for (step = size / 2; step > 0; step /= 2, ++compCount)
    {
        for (i = step; i < size; ++i, ++compCount)
        {
            for (j = i - step; j >= 0 && array[j].key > array[j + step].key; j -= step, compCount += 2)
            {
                swap(array, j, j + step);
            }
        }
    }

    clock_t t_stop = clock();
    std::cout << "After shell sort:" << std::endl;
    //print(array);
    std::cout << "Comparisons: " << compCount << std::endl
              << "Time spend: " << (double)(t_stop - t_start) / (double)CLOCKS_PER_SEC << "s" << std::endl
              << std::endl;
}

int main()
{
    using namespace std;
    vector<Record> array(20);

    shake(array);
    cout << "Original array:" << endl;
    print(array);
    cout << endl;

    shakeSort(array);

    shake(array);
    shellSort(array);

    return 0;
}
