#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// =============== Инициализация списка =============== //

list *listInit()
{
    list *rez;

    rez = (list *)malloc(sizeof(list));
    if (rez == NULL)
        return NULL;

    rez->pHead = NULL;
    rez->size = 0;
    return rez;
}

// ================ Добавление в конец ================ //

int listAppend(list *pList, int vaule)
{
    struct listNode *newNode;
    struct listNode *current;

    // Если в списке нет ни одного элемента
    if (pList->pHead == NULL)
    {
        newNode = (struct listNode *)malloc(sizeof(struct listNode));
        if (newNode == NULL)
            return -1;

        // Создание нового элемента списка
        pList->pHead = newNode;
        newNode->pPrev = pList->pHead;
        newNode->pNext = pList->pHead;
        newNode->Data = vaule;
        pList->size += 1;
    }
    else
    {
        newNode = (struct listNode *)malloc(sizeof(struct listNode));
        if (newNode == NULL)
            return -1;

        /*  
            Указатель на след. элемент у последнего элемента списка
            заменяем на указатель на новый элемент
        */
        current = pList->pHead;
        current = current->pPrev;
        current->pNext = newNode;

        // Создание нового элемента списка
        newNode->pNext = pList->pHead;
        newNode->pPrev = current;
        newNode->Data = vaule;
        pList->size += 1;

        /*
            Указатель на пред. элемент у первого элемента списка
            заменяем на указатель на новый элемент
        */
        current = pList->pHead;
        current->pPrev = newNode;
    }
    return 0;
}

// ======= Поиск элемента с заданным значением ======== //

int listSearch(list *pList, int value)
{
    struct listNode *current;
    if (pList->pHead == NULL)
        return -1;

    current = pList->pHead;
    for (int i = 0; i < pList->size; ++i)
    {
        if (current->Data == value)
            printf("Found the element list[%d]:\t%d\n", i, current->Data);
        current = current->pNext;
    }

    return 0;
}

// ================ Распечатка списка ================= //

int listPrint(list *pList)
{
    struct listNode *current;

    if (pList->pHead == NULL)
        return -1;

    current = pList->pHead;
    printf("List:\n");
    for (int i = 0; i < pList->size; ++i)
    {
        printf("%3d:%4d\n", i + 1, current->Data);
        current = current->pNext;
    }
    return 0;
}

// ============= Распечатка списка в файл ============= //

int listFilePrint(list *pList)
{
    struct listNode *current;
    FILE *ptrFile;

    if (pList->pHead == NULL)
        return -1;

    ptrFile = fopen("list.txt", "wt");
    if (ptrFile == NULL)
        return -2;

    current = pList->pHead;
    fprintf(ptrFile, "List:\n");
    for (int i = 0; i < pList->size; ++i)
    {
        fprintf(ptrFile, "%3d:%4d\n", i + 1, current->Data);
        current = current->pNext;
    }
    fclose(ptrFile);

    return 0;
}

// ================ Удаление последнего =============== //

int listDelLast(list *pList)
{
    struct listNode *pHead;
    struct listNode *current;

    if (pList->pHead == NULL)
        return -1;

    // Переходим к предпоследнему элементу списка
    current = pList->pHead;
    current = current->pPrev;
    current = current->pPrev;

    /*
        Указатель на предыдущий элемент у первого элемента списка
        заменяем на указатель предпоследнего элемента
    */
    pHead = pList->pHead;
    pHead->pPrev = current;

    // Удаляем последний элемент списка
    free(current->pNext);
    pList->size -= 1;

    /*
        Указатель на следующий элемент у предпоследнего элемента списка
        заменяем на указатель первого элемента (его голову)
    */
    current->pNext = pList->pHead;

    return 0;
}

// ================== Удаление списка ================= //

int listDelete(list *pList)
{
    struct listNode *current;

    if (pList->pHead == NULL)
        return -1;

    /*
        Указатель на текущий элемент
        переместить на последний эл. списка
    */
    current = pList->pHead;
    current = current->pPrev;

    /*
        Пока в списке не останется один элемент
        (Первый элемент списка, его голова)
        переходим к предыдущему элементу и удаляем следующий
    */
    while (current != pList->pHead)
    {
        current = current->pPrev;
        free(current->pNext);
        pList->size -= 1;
    }

    /* 
        Удаляем последний оставшийся элемент
        (Первый элемент списка, его голова)
    */
    free(pList->pHead);
    pList->size -= 1;

    free(pList);
    return 0;
}