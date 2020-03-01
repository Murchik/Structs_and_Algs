#include <iostream>
#include <fstream>
#include <locale>
#include "tree.hpp"

int main()
{
    using namespace std;
    setlocale(LC_ALL, "RUS");
    cout << "\t\t\"Реализация двоичного дерева поиска\"" << endl
         << "Выберете действие: " << endl
         << "\t1. Создать бинарное дерево." << endl
         << "\t2. Найти узел с заданным значением ключа." << endl
         << "\t3. Вставить отдельный узел." << endl
         << "\t4. Вывести обратный обход дерева." << endl
         << "\t5. Найти узел с максимальным значением ключа." << endl
         << "\t6. Удаление узла с заданным ключём." << endl
         << "\t0. Завершить работу." << endl;

    int value;
    int action;
    ifstream fin;
    BinTree tree;
    Node *rez;

    action = -1;
    while (action != 0)
    {
        cin >> action;
        switch (action)
        {
        case 1:
            fin.open("tree.txt", ifstream::in);
            if (!fin.is_open())
            {
                cout << "Ошибка открытия файла tree.txt" << endl;
                break;
            }
            while (fin.good())
            {
                fin >> value;
                tree.insert(value);
            }
            cout << "Дерево успешно считано из файла." << endl;
            break;
        case 2:
            cout << "Введите значение для поиска: ";
            cin >> value;
            rez = tree.search(value);
            if (rez != nullptr)
                cout << "Узел " << rez->data << " найден" << endl;
            else
                cout << "Узла со значением " << value << " не найдено!" << endl;
            break;
        case 3:
            cout << "Введите значение для вставки: ";
            cin >> value;
            tree.insert(value);
            break;
        case 4:
            if (tree.isCreated())
            {
                cout << "Обратный обход дерева: " << endl;
                tree.postTraversal();
                cout << endl;
            }
            else
                cout << "Дерево пустое!" << endl;
            break;
        case 5:
            rez = tree.max();
            if (rez != nullptr)
                cout << "Узел с максимальным значением ключа: " << rez->data << endl;
            else
                cout << "Максимального элемента не найдено!" << endl;
            break;
        case 6:
            cout << "Введите значение для удаления: ";
            cin >> value;
            if (tree.erase(value) == 0)
                cout << "Узел с задданым значением успешно удалён." << endl;
            else
                cout << "Ключ заданный для удаления не найден!" << endl;
            break;
        case 0:
            cout << "Завершение работы программы..." << endl;
            break;
        default:
            cout << "Выбрано неверное действие!" << endl;
            break;
        }
    }
    return 0;
}
