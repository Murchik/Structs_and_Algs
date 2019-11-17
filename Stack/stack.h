#ifndef list_h
#define list_h

struct stackEl
{
    struct stackEl *_pNext;
    int _data;
};

typedef struct stack
{
    struct stackEl *_pTop;
} stack_t;

stack_t *stackInit();
int stackCreate(stack_t *, int);
int stackClear(stack_t *);
int push(stack_t *, int);
int pop(stack_t *);
int stackPrint(stack_t *);

#endif