#include <stdio.h>
#include <stdlib.h>

struct stackEl
{
    struct stackEl *pNext;
    int Data;
};

typedef struct stack
{
    struct stackEl *pTop;
} stack_t;

#define MAX_LENGTH 19

stack_t *stackInit();
int stackDelete(stack_t *);
int push(stack_t *, int);
int pop(stack_t *);
int stackPrint(stack_t *);

// ==================================================== //

int main()
{
    stack_t *MyStack = stackInit();
    
    for(int i = 0; i < MAX_LENGTH; ++i)
        push(MyStack, rand() % 100);

    stackPrint(MyStack);

    stackDelete(MyStack);
    //system("pause");
    return 0;
}

// ================= Создание стека =================== //

stack_t *stackInit()
{
    stack_t *rez;

    rez = (stack_t *)malloc(sizeof(stack_t));
    if (rez != NULL)
        rez->pTop = NULL;
    return rez;
}

// ============ Включение нового элемента ============= //

int push(stack_t *pStack, int value)
{
    struct stackEl *newEl;

    if (pStack->pTop == NULL)
    {
        newEl = (struct stackEl *)malloc(sizeof(struct stackEl));
        if (newEl == NULL)
            return -1;
        newEl->Data = value;
        newEl->pNext = NULL;
        pStack->pTop = newEl;
    }
    else
    {
        newEl = (struct stackEl *)malloc(sizeof(struct stackEl));
        if (newEl == NULL)
            return -1;
        newEl->Data = value;
        newEl->pNext = pStack->pTop;
        pStack->pTop = newEl;
    }
    return 0;
}

// ================ Выборка элемента ================== //

int pop(stack_t *pStack)
{
    struct stackEl *currEl;
    int rez;

    if (pStack->pTop == NULL)
        return 0;
    currEl = pStack->pTop;
    rez = currEl->Data;
    pStack->pTop = currEl->pNext;
    free(currEl);
    return rez;
}

// === Вывод на экран значений стека с их индексами === //

int stackPrint(stack_t *pStack)
{
    struct stackEl *currEl;
    struct stackEl *ptrTop;

    ptrTop = pStack->pTop;
    currEl = pStack->pTop;
    for (int i = 0; currEl != NULL; ++i)
    {
        pStack->pTop = currEl->pNext;
        printf("stack[%d]:\t%d\n", i, currEl->Data);
        currEl = pStack->pTop;
    }
    pStack->pTop = ptrTop;
    return 0;
}

// ================ Очистка списка ==================== //

int stackDelete(stack_t *pStack)
{
    struct stackEl *currEl;

    currEl = pStack->pTop;
    while (currEl != NULL)
    {
        pStack->pTop = currEl->pNext;
        free(currEl);
        currEl = pStack->pTop;
    }
    free(pStack);
    return 0;
}