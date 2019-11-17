#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// =============== Инициализация списка =============== //
/*  
    В случае успешного создания дескриптора
    возвращает указатель на него,
    в противном случае возвращает NULL
*/
list *listInit()
{
    list *newList = NULL;
    int value;

    newList = (list *)malloc(sizeof(list));
    if (newList == NULL)
        return NULL;

    newList->_pHead = NULL;
    newList->_size = 0;

    return newList;
}

// === Создание списка с заданным кол-вом элементов === //
/*
    Возвращает кол-во успешно добавленных элементов
*/
int listCreate(list *pList, int maxLength)
{
    int value;
    int i;

    listClear(pList);
    for (i = 0; i < maxLength; ++i)
    {
        value = rand() % 100;
        if(listAppend(pList, value) == -1)
            return i;
    }

    return i;
}

// ================ Добавление в конец ================ //
/*
    Возвращает кол-во элементов списка
    просмотренных данной операцией,
    если добавить новый элемент не удалось
    возвращает -1
*/
int listAppend(list *pList, int vaule)
{
    struct listNode *newNode = NULL;
    struct listNode *current = NULL;
    int transCount;

    transCount = 0;
    // Если в списке нет ни одного элемента
    if (pList->_pHead == NULL)
    {
        newNode = (struct listNode *)malloc(sizeof(struct listNode));
        if (newNode == NULL)
            return -1;

        pList->_pHead = newNode;
        newNode->_pPrev = pList->_pHead;
        newNode->_pNext = pList->_pHead;
        newNode->_Data = vaule;
        pList->_size += 1;
    }
    else
    {
        current = pList->_pHead;
        
        newNode = (struct listNode *)malloc(sizeof(struct listNode));
        if (newNode == NULL)
            return -1;

        /*  
            Указатель на след. элемент у последнего элемента списка
            заменяем на указатель на новый элемент
        */
        current = current->_pPrev;
        transCount += 1;
        current->_pNext = newNode;

        // Инициализирование полей нового элемента списка
        newNode->_pNext = pList->_pHead;
        newNode->_pPrev = current;
        newNode->_Data = vaule;
        pList->_size += 1;

        /*
            Указатель на пред. элемент у первого элемента списка
            заменяем на указатель на новый элемент
        */
        current = pList->_pHead;
        transCount += 1;
        current->_pPrev = newNode;
    }
    return transCount;
}

// ======= Поиск элемента с заданным значением ======== //
/*
    Возвращает кол-во элементов списка
    просмотренных данной операцией,
    если список пуст возвращает -1,
    если заданного элемента обнаружить не удалось
    возвращает -2
*/
int listSearch(list *pList, int value)
{
    struct listNode *current = NULL;
    int transCount;
    int found;

    found = 0;
    transCount = 0;
    if (pList->_pHead == NULL)
        return -1;

    current = pList->_pHead;
    for (int i = 0; i < pList->_size; ++i)
    {
        if (current->_Data == value)
        {
            printf("Found the element list[%d]:\t%d\n", i, current->_Data);
            found = 1;
        }
        current = current->_pNext;
        transCount += 1;
    }
    if(found)
        return transCount;
    else
        return -2;
}

// ================ Распечатка списка ================= //
/*
    Возвращает 0 при успешной распечатке списка,
    если список пуст возвращает -1
*/
int listPrint(list *pList)
{
    struct listNode *current = NULL;

    if (pList->_pHead == NULL)
        return -1;

    current = pList->_pHead;
    printf("List:\n");
    for (int i = 0; i < pList->_size; ++i)
    {
        printf("\tlist[%d]:\t%d\n", i, current->_Data);
        current = current->_pNext;
    }
    return 0;
}

// ============= Распечатка списка в файл ============= //
/*
    Возвращает 0 при успешной распечатке списка,
    если список пуст возвращает -1,
    если создать выходной файл не удалось
    возвращает -2
*/
int listFilePrint(list *pList)
{
    struct listNode *current = NULL;
    FILE *ptrFile = NULL;

    if (pList->_pHead == NULL)
        return -1;

    ptrFile = fopen("list.txt", "wt");
    if (ptrFile == NULL)
        return -2;

    current = pList->_pHead;
    fprintf(ptrFile, "List:\n");
    for (int i = 0; i < pList->_size; ++i)
    {
        fprintf(ptrFile, "\tlist[%d]:\t%d\n", i, current->_Data);
        current = current->_pNext;
    }
    fclose(ptrFile);

    return 0;
}

// ================ Удаление последнего =============== //
/*
    Возвращает кол-во элементов списка
    просмотренных данной операцией,
    если список пуст возвращает -1
*/
int listDelLast(list *pList)
{
    struct listNode *pHead = NULL;
    struct listNode *current = NULL;
    int transCount;

    transCount = 0;
    // Если список пустой
    if (pList->_pHead == NULL)
        return -1;
    
    current = pList->_pHead;

    // Переходим к последнему элементу списка
    current = current->_pPrev;
    transCount += 1;

    // Если в списке один элемент
    if (current == pList->_pHead)
    {
        free(current->_pNext);
        pList->_size -= 1;
        pList->_pHead = NULL;
        return transCount;
    }

    // Переходим к предпоследнему элементу списка
    current = current->_pPrev;
    transCount += 1;

    /*
        Указатель на предыдущий элемент у первого элемента списка
        заменяем на указатель предпоследнего элемента
    */
    pHead = pList->_pHead;
    pHead->_pPrev = current;

    // Удаляем последний элемент списка
    free(current->_pNext);
    pList->_size -= 1;

    /*
        Указатель на следующий элемент у предпоследнего элемента списка
        заменяем на указатель первого элемента (его голову)
    */
    current->_pNext = pList->_pHead;

    return transCount;
}

// ================== Удаление списка ================= //
/*
    Возвращает кол-во элементов списка
    просмотренных данной операцией,
    если список пуст возвращает -1
*/
int listClear(list *pList)
{
    struct listNode *current = NULL;
    int transCount;

    transCount = 0;
    if (pList->_pHead == NULL)
        return -1;

    current = pList->_pHead;

    /*
        Указатель на текущий элемент
        переместить на последний эл. списка
    */
    current = current->_pPrev;
    transCount += 1;

    /*
        Пока в списке не останется один элемент
        (Первый элемент списка, его голова)
        переходим к предыдущему элементу и удаляем следующий
    */
    while (current != pList->_pHead)
    {
        current = current->_pPrev;
        transCount += 1;
        free(current->_pNext);
        pList->_size -= 1;
    }

    /* 
        Удаляем последний оставшийся элемент
        (Первый элемент списка, его голова)
    */
    free(pList->_pHead);
    pList->_size -= 1;
    pList->_pHead = NULL;
    
    return transCount;
}