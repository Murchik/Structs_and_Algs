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
    int created;
    setlocale(LC_ALL, "RUS");

    printf("\n------------ Вас приветстует Программа список! ------------\n\n\
Выберите желаемое действие:\n\
\t1 - Создание списка\n\
\t2 - Добавление нового элемента в конец списка\n\
\t3 - Удаление элемента из конце списка\n\
\t4 - Вывод списка на экран\n\
\t5 - Поиск заданного значения\n\
\t6 - Очистка списка\n\n\
\t0 - Выход\n");

    action = 1;
    created = 0;
    while (action != 0)
    {
        scanf("%d", &action);

        switch (action)
        {
        /* Выход */
        case 0:
            if (created)
                listClear(myList);
            printf("Программа успешно завершена. "); 
            break;

        /* Создание списка */
        case 1:
            if (!created)
            {
                myList = listInit();
                printf("Список успешно создан.\n");
                created = 1;
            }
            else
                printf("Список уже создан!\n");
            break;

        /* Добавление нового элемента в конец списка */
        case 2:
            if (!created)
            {
                printf("Список не создан!\n");
                break;
            }
            printf("Введите значение для добавления: ");
            scanf("%d", &value);
            if (listAppend(myList, value) != 0)
            {
                printf("Ошибка добавления элемента\n");
            }
            else
                printf("Элемент добавлен.\n");
            break;

        /* Удаление элемента из конце списка */
        case 3:
            if (created == 0)
            {
                printf("Список не создан!\n");
                break;
            }
            listDelLast(myList);
            printf("Последний элемент удалён.\n");
            break;

        /* Вывод на экран */
        case 4:
            if (created == 0)
            {
                printf("Список не создан!\n");
                break;
            }
            if (listPrint(myList) != 0)
                printf("Список пуст!\n");
            break;

        /* Поиск заданного значения */
        case 5:
            if (created == 0)
            {
                printf("Список не создан!\n");
                break;
            }
            printf("Введите значение для поиска: ");
            scanf("%d", &value);
            if (listSearch(myList, value) != 0)
                printf("Элементов с таким значением не найдено\n");
            break;

        /* Очистка списка */
        case 6:
            if (created == 0)
            {
                printf("Список не создан!\n");
                break;
            }
            listClear(myList);
            printf("Список успешно очищен\n");
            break;

        /* Неизвестная команда */
        default:
            printf("Введена неизвестная команда!\n");
            break;
        }
    }
    system("pause");
    return 0;
}