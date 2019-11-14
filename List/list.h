#ifndef list_h
#define list_h

struct listNode
{
    struct listNode *pNext;
    struct listNode *pPrev;
    int Data;
} listNode;

typedef struct
{
    struct listNode *pHead;
    int size;
} list;

list *listInit(); // Создание списка

int listAppend(list *, int); // Доп. операция 4

int listSearch(list *, int); // Доп. операция 1

int listPrint(list *);     // Вывод на экран значений элементов списка с их индексами
int listFilePrint(list *); // Вывод в файл значений элементов списка с их индексами

int listDelLast(list *); // Доп. операция 7
int listClear(list *);  // Очистка списка

#endif