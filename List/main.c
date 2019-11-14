#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define MAX_LENGTH 20

int main()
{
    list *myList = listInit();
    
    listPrint(myList);

    listAppend(myList, 1);
    listAppend(myList, 16);
    listAppend(myList, 3);
    listAppend(myList, 4);
    listAppend(myList, 16);
    for (int i = 5; i < MAX_LENGTH; i++)
        listAppend(myList, i+1);

    listPrint(myList);

    listSearch(myList, 16);

    listClear(myList);
    //system("pause");
    return 0;
}