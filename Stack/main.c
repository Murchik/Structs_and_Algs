#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "stack.h"

#define MAX_LENGTH 19

int main()
{
    stack_t *myStack;
    int action;
    int value;
    setlocale(LC_ALL, "RUS");

    myStack = stackInit();
    if (myStack == NULL)
    {
        printf("Ошибка создания дескриптора списка!\n");
        return 0;
    }
    
    printf("\n------------ Вас приветстует программа Стек! ------------\n\n\
Выберите желаемое действие:\n\
\t1 - Создание стека\n\
\t2 - Вывод элементов стека на экран\n\
\t3 - Включение нового элемента (push)\n\
\t4 - Выборка элемента (pop)\n\
\t5 - Очистка стека\n\n\
\t0 - Выход\n");

    action = 1;
    while (action != 0)
    {
        scanf("%d", &action);
        if (action == 0)
        {
            printf("Программа успешно завершена. ");
            break;
        }
        else if (action == 1)
        {
            stackCreate(myStack, MAX_LENGTH);
            printf("Стек создан\n");
            stackPrint(myStack);
        }
        else if (action == 2)
        {
            stackPrint(myStack);
        }
        else if (action == 3)
        {
            scanf("%d", &value);
            push(myStack, value);
            stackPrint(myStack);
        }
        else if (action == 4)
        {
            printf("Выбран элемент: %d\n", pop(myStack));
            stackPrint(myStack);
        }
        else if (action == 5)
        {
           stackClear(myStack);
           printf("Стек очищен\n");
        }
        else
            printf("Введена неизвестная команда!\n");
    }
    stackClear(myStack);
    system("pause");
    return 0;
}