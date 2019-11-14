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

    printf("\n------------ ��� ����������� ��������� ������! ------------\n\n\
�������� �������� ��������:\n\
\t1 - �������� ������\n\
\t2 - ���������� ������ �������� � ����� ������\n\
\t3 - �������� �������� �� ����� ������\n\
\t4 - ����� ������ �� �����\n\
\t5 - ����� ��������� ��������\n\
\t6 - ������� ������\n\n\
\t0 - �����\n");

    action = 1;
    created = 0;
    while (action != 0)
    {
        scanf("%d", &action);

        switch (action)
        {
        /* ����� */
        case 0:
            if (created)
                listClear(myList);
            printf("��������� ������� ���������. "); 
            break;

        /* �������� ������ */
        case 1:
            if (!created)
            {
                myList = listInit();
                printf("������ ������� ������.\n");
                created = 1;
            }
            else
                printf("������ ��� ������!\n");
            break;

        /* ���������� ������ �������� � ����� ������ */
        case 2:
            if (!created)
            {
                printf("������ �� ������!\n");
                break;
            }
            printf("������� �������� ��� ����������: ");
            scanf("%d", &value);
            if (listAppend(myList, value) != 0)
            {
                printf("������ ���������� ��������\n");
            }
            else
                printf("������� ��������.\n");
            break;

        /* �������� �������� �� ����� ������ */
        case 3:
            if (created == 0)
            {
                printf("������ �� ������!\n");
                break;
            }
            listDelLast(myList);
            printf("��������� ������� �����.\n");
            break;

        /* ����� �� ����� */
        case 4:
            if (created == 0)
            {
                printf("������ �� ������!\n");
                break;
            }
            if (listPrint(myList) != 0)
                printf("������ ����!\n");
            break;

        /* ����� ��������� �������� */
        case 5:
            if (created == 0)
            {
                printf("������ �� ������!\n");
                break;
            }
            printf("������� �������� ��� ������: ");
            scanf("%d", &value);
            if (listSearch(myList, value) != 0)
                printf("��������� � ����� ��������� �� �������\n");
            break;

        /* ������� ������ */
        case 6:
            if (created == 0)
            {
                printf("������ �� ������!\n");
                break;
            }
            listClear(myList);
            printf("������ ������� ������\n");
            break;

        /* ����������� ������� */
        default:
            printf("������� ����������� �������!\n");
            break;
        }
    }
    system("pause");
    return 0;
}