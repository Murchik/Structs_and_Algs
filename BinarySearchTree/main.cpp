#include <iostream>
#include <fstream>
#include <locale>
#include "tree.hpp"

int main()
{
    using namespace std;
    setlocale(LC_ALL, "RUS");
    cout << "\t\t\"���������� ��������� ������ ������\"" << endl
         << "�������� ��������: " << endl
         << "\t1. ������� �������� ������." << endl
         << "\t2. ����� ���� � �������� ��������� �����." << endl
         << "\t3. �������� ��������� ����." << endl
         << "\t4. ������� �������� ����� ������." << endl
         << "\t5. ����� ���� � ������������ ��������� �����." << endl
         << "\t6. �������� ���� � �������� ������." << endl
         << "\t0. ��������� ������." << endl;

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
                cout << "������ �������� ����� tree.txt" << endl;
                break;
            }
            while (fin.good())
            {
                fin >> value;
                tree.insert(value);
            }
            cout << "������ ������� ������� �� �����." << endl;
            break;
        case 2:
            cout << "������� �������� ��� ������: ";
            cin >> value;
            rez = tree.search(value);
            if (rez != nullptr)
                cout << "���� " << rez->data << " ������" << endl;
            else
                cout << "���� �� ��������� " << value << " �� �������!" << endl;
            break;
        case 3:
            cout << "������� �������� ��� �������: ";
            cin >> value;
            tree.insert(value);
            break;
        case 4:
            if (tree.isCreated())
            {
                cout << "�������� ����� ������: " << endl;
                tree.postTraversal();
                cout << endl;
            }
            else
                cout << "������ ������!" << endl;
            break;
        case 5:
            rez = tree.max();
            if (rez != nullptr)
                cout << "���� � ������������ ��������� �����: " << rez->data << endl;
            else
                cout << "������������� �������� �� �������!" << endl;
            break;
        case 6:
            cout << "������� �������� ��� ��������: ";
            cin >> value;
            if (tree.erase(value) == 0)
                cout << "���� � �������� ��������� ������� �����." << endl;
            else
                cout << "���� �������� ��� �������� �� ������!" << endl;
            break;
        case 0:
            cout << "���������� ������ ���������..." << endl;
            break;
        default:
            cout << "������� �������� ��������!" << endl;
            break;
        }
    }
    return 0;
}
