#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> readVec();

template <class Arr>
void printVec(const Arr& input) 
{
    std::copy(input.begin(), input.end(),
              std::ostream_iterator<typename Arr::value_type>(std::cout, " "));
    std::cout << std::endl;
}

template <class Arr>
void shakeSort(Arr &input) 
{
    std::cout << "Shake sort: " << std::endl;
    double compCount = 0;
    auto startTimer = std::chrono::high_resolution_clock::now();

    int start = 0;
    int end = input.size() - 1;
    bool swapped = true;
    while (swapped) 
    {
        swapped = false;

        for (int i = start; i < end; ++i) 
        {
            if (input[i] > input[i + 1]) 
            {
                std::swap(input[i], input[i + 1]);
                swapped = true;
            }
            ++compCount;
        }
        if (!swapped) 
            break;
        

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) 
        {
            if (input[i] > input[i + 1]) 
            {
                std::swap(input[i], input[i + 1]);
                swapped = true;
            }
            ++compCount;
        }
        ++start;


    }

    auto endTimer = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = endTimer - startTimer;
    std::cout << "Comparisons: " << compCount << std::endl
              << "Time spend: " << duration.count() << "s" << std::endl
              << std::endl;

    
}

template <class Arr>
void shellSort(Arr &array) 
{
    std::cout << "Shell sort: " << std::endl;
    int size = array.size();
    double compCount = 0;
    int i, j, h, tmp;

    auto startTimer = std::chrono::high_resolution_clock::now();

    for (h = size / 2; h > 0; h /= 2)
        for (i = h; i < size; i++)
            for (j = i - h; j >= 0 && array[j] > array[j + h];
                j -= h, ++compCount)
                std::swap(array[j], array[j + h]);

    auto endTimer = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = endTimer - startTimer;
    std::cout << "Comparisons: " << compCount << std::endl
              << "Time spend: " << duration.count() << "s" << std::endl
              << std::endl;
}
