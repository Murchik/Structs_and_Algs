#include "stdio.h"
#include "stdlib.h"
#define N 18

typedef struct myArray
{
    int _data;
    int _key;
} _array;

int printArr(_array **arr);
int bubble_sort(_array **array, int array_size);
int searchS(_array **arr, int key);
int searchQ(_array **arr, int key);
int searchT(_array **arr, int key);
int searchB(_array **arr, int key);

const int keys[N] = {17, 14, 11, 3, 4, 6, 12, 16, 10, 2, 7, 1, 13, 8, 15, 9, 5, 0};

int main()
{
    int key;
    _array **Array;
    Array = (_array **)malloc((N + 1) * sizeof(_array *));
    for (int i = 0; i < N + 1; ++i)
    {
        Array[i] = (_array *)malloc(sizeof(_array));
        Array[i]->_data = rand() % 100;
        Array[i]->_key = keys[i];
    }
    system("color F0");
    printf("Array:\n");
    printArr(Array);

    printf("\nEnter the search key: ");
    scanf("%d", &key);
    searchS(Array, key);
    searchQ(Array, key);

    bubble_sort(Array, N);
    printf("Sorted array:\n");
    printArr(Array);
    searchT(Array, key);
    searchB(Array, key);

    for (int i = 0; i < N + 1; ++i)
    {
        free(Array[i]);
    }
    free(Array);
    system("pause");
    return 0;
}

int printArr(_array **Array)
{
    for (int i = 0; i < N; ++i)
        printf("Array[%d]:\tData = %3d, Key = %2d\n", i, Array[i]->_data, Array[i]->_key);
    return 0;
}

int bubble_sort(_array **array, int array_size)
{
    int i = 0;
    _array *buf;
    char swap_cnt = 0;
    if (array_size == 0)
        return (0);
    while (i < array_size)
    {
        if (i + 1 != array_size && array[i]->_key > array[i + 1]->_key)
        {
            buf = array[i];
            array[i] = array[i + 1];
            array[i + 1] = buf;
            swap_cnt = 1;
        }
        i++;
        if (i == array_size && swap_cnt == 1)
        {
            swap_cnt = 0;
            i = 0;
        }
    }
    return 0;
}

int searchS(_array **Array, int key)
{
    int i;
    int count = 0;
    int comp = 0;
    printf("Search S:\n");
    for (i = 0; i < N; ++i)
    {
        comp += 1;
        if (Array[i]->_key == key)
        {
            count += 1;
            printf("\tElement found: Array[%d] = %d\n", i, Array[i]->_data);
            break;
        }
        comp += 1;
    }
    if (count != 0)
        printf("\tSearch was a success.");
    else
        printf("\tThe search was unsuccessful: No items with such keys.\n");
    printf("\tComparisons: %d\tIterations: %d\n", comp, i);
    return 0;
}

int searchQ(_array **Array, int key)
{
    int i;
    int count = 0;
    int comp = 0;
    printf("Search Q:\n");

    Array[N]->_data = 99;
    Array[N]->_key = key;

    for (i = 0; Array[i]->_key != key; ++i)
        comp += 1;
    if (i < N)
    {
        printf("\tSearch was a success");
        printf(" Element found: Array[%d] = %d\n", i, Array[i]->_data);
    }
    else
        printf("\tThe search was unsuccessful: No items with such keys.\n");
    printf("\tComparisons: %d\tIterations: %d\n", comp, i);
    return 0;
}

int searchT(_array **Array, int key)
{
    int i;
    int comp = 0;
    printf("Search T:\n");
    Array[N]->_data = 99;
    Array[N]->_key = 1000;
    for (i = 0; key > Array[i]->_key; ++i)
        comp += 1;
    if (key == Array[i]->_key)
    {
        printf("\tSearch was a success.");
        printf(" Element found: Array[%d] = %d\n", i, Array[i]->_data);
    }
    else
        printf("\tThe search was unsuccessful: No items with such keys.\n");
    printf("\tComparisons: %d\tIterations: %d\n", comp, i);
    return 0;
}

int searchB(_array **Array, int key)
{
    int i, j;
    int comp = 0;
    int count = 0;
    printf("Search B:\n");
    int i_left = 0;
    int i_right = N;
    for (i = 0, j = 0; i_left <= i_right; ++i, ++j)
    {
        i = (i_left + i_right) / 2;
        comp += 1;
        if (key < Array[i]->_key)
            i_right = i - 1;
        else
        {
            comp += 1;
            if (key == Array[i]->_key)
            {
                count += 1;
                break;
            }
            else
                i_left = i + 1;
        }
        comp += 1;
    }
    if (count != 0)
    {
        printf("\tSearch was a success");
        printf("\tElement found: Array[%d] = %d\n", i, Array[i]->_data);
    }
    else
        printf("\tThe search was unsuccessful: No items with such keys.\n");
    printf("\tComparisons: %d\tIterations: %d\n", comp, j);
    return 0;
}