#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// ============== Инициализация стека ================= //

stack_t *stackInit()
{
    stack_t *newStack = NULL;

    newStack = (stack_t *)malloc(sizeof(stack_t));
    if (newStack != NULL)
        newStack->_pTop = NULL;
    return newStack;
}

// ================= Создание стека =================== //

int stackCreate(stack_t * pStack, int amount)
{
    int value;
    int i;

    stackClear(pStack);
    for(i = 0; i < amount; ++i)
    {
        value = rand() % 100;
        if(push(pStack, value) == -1)
            return i;
    }
    return i;
}

// ============ Включение нового элемента ============= //

int push(stack_t *pStack, int value)
{
    struct stackEl *newEl = NULL;

    if (pStack->_pTop == NULL)
    {
        newEl = (struct stackEl *)malloc(sizeof(struct stackEl));
        if (newEl == NULL)
            return -1;
        newEl->_data = value;
        newEl->_pNext = NULL;
        pStack->_pTop = newEl;
    }
    else
    {
        newEl = (struct stackEl *)malloc(sizeof(struct stackEl));
        if (newEl == NULL)
            return -1;
        newEl->_data = value;
        newEl->_pNext = pStack->_pTop;
        pStack->_pTop = newEl;
    }
    return 0;
}

// ================ Выборка элемента ================== //

int pop(stack_t *pStack)
{
    struct stackEl *currEl = NULL;
    int result;

    if (pStack->_pTop == NULL)
        return 0;
    currEl = pStack->_pTop;
    result = currEl->_data;
    pStack->_pTop = currEl->_pNext;
    free(currEl);
    return result;
}

// === Вывод на экран значений стека с их индексами === //

int stackPrint(stack_t *pStack)
{
    struct stackEl *currEl = NULL;
    struct stackEl *ptrTop = NULL;

    if(pStack->_pTop == NULL)
        return -1;
    ptrTop = pStack->_pTop;
    currEl = pStack->_pTop;
    printf("Stack:\n");
    for (int i = 0; currEl != NULL; ++i)
    {
        pStack->_pTop = currEl->_pNext;
        printf("stack[%d]:\t%d\n", i, currEl->_data);
        currEl = pStack->_pTop;
    }
    pStack->_pTop = ptrTop;
    return 0;
}

// ================ Очистка стека ==================== //

int stackClear(stack_t *pStack)
{
    struct stackEl *currEl = NULL;

    if(pStack->_pTop == NULL)
        return -1;
    currEl = pStack->_pTop;
    while (currEl != NULL)
    {
        pStack->_pTop = currEl->_pNext;
        free(currEl);
        currEl = pStack->_pTop;
    }
    return 0;
}