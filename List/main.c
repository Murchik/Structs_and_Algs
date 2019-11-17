#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "list.h"

#define MAX_LENGTH 20

int main()
{
    list *myList;
    int action;
    int value;
    setlocale(LC_ALL, "RUS");

    myList = listInit();
    if (myList == NULL)
    {
        printf("Ошибка создания дескриптора списка!\n");
        return 0;
    }

    printf("\n------------ Вас приветстует программа Список! ------------\n\n\
Выберите желаемое действие:\n\
\t1 - Создание списка\n\
\t2 - Добавление нового элемента в конец списка\n\
\t3 - Удаление элемента из конце списка\n\
\t4 - Вывод списка на экран\n\
\t5 - Поиск заданного значения\n\
\t6 - Очистка списка\n\n\
\t0 - Выход\n");

    action = 1;
    while (action != 0)
    {
        scanf("%d", &action);
        if (action == 0)
        {
            listClear(myList);
            printf("Программа успешно завершена. ");
            break;
        }
        else if (action == 1)
        {
            if(listCreate(myList, MAX_LENGTH) == MAX_LENGTH)
            {
                printf("Список успешно создан\n");
                listPrint(myList);
            }
            else
                printf("Ошибка при создании списка\n");
        }
        else if (action == 2)
        {
            printf("Введите значение для добавления: ");
            scanf("%d", &value);
            value = listAppend(myList, value);
            if (value == -1)
                printf("Ошибка добавления элемента\n");
            else
            {
                printf("Элемент успешно добавлен\n");
                printf("Просмотренно элементов: %d\n", value);
                listPrint(myList);
            }
        }
        else if (action == 3)
        {
            value = listDelLast(myList);
            if(value < 0)
            {
                printf("Удаление не удалось: попытка удалить элемент из пустого списка!\n");
            }
            else
            {
                printf("Удаление последнего элемента прошло успешно\n");
                printf("Просмотренно элементов: %d\n", value);
                listPrint(myList);
            }
        }
        else if (action == 4)
        {
            if(listPrint(myList) == -1)
                printf("Попытка распечатать пустой список!\n");
        }
        else if (action == 5)
        {
            printf("Введите значение для поиска: ");
            scanf("%d", &value);
            value = listSearch(myList, value);
            if (value < 0)
                printf("Элемент с данным значением найти не удалось.\n");
            else
                printf("Просмотренно элементов: %d\n", value);
        }
        else if (action == 6)
        {
            listClear(myList);
            printf("Список успешно очищен\n");
        }
        else
            printf("Введена неизвестная команда!\n");
    }
    listClear(myList);
    system("pause");
    return 0;
}