#include <iostream>
#include <locale>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct kard {
    string name;
    string type;
    string date1;
    string date2;
    int amount;
    void printInfo() {
        cout << "\nИмя: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Дата выдачи: " << date1 << endl;
        cout << "Дата окончания: " << date2 << endl;
        cout << "Количество поездок: " << amount << endl;
    }
};
void counter()
{
    const string str = " One Eight Zero ";
    int counter = count(str.cbegin(), str.cend(), 'e');
    cout << "Количество букв 'e' в \"One Eight Zero\" равно:" << counter << '\n';
    cout << endl;
}
void matrica()
{

    int p = 6;
    int j = 5;
    for (int i = 0; i < 6; i++)
    {
        cout << i << " ";
        for (int star = j; star > 0; star--)
        {
            cout << setfill('*') << setw(1) << "" << " ";
        }
        j--;
        cout << endl;
        for (int space = -1; space < i; space++)
        {
            cout << ' ' << ' ';
        }
        p--;
    }
    cout << endl;

}

int main()
{
    setlocale(LC_ALL, "Rus");
    kard card[3];
    card[0] = { "Карта 1", "Универсальная", "19.03.2023", "18.04.2023", 0 };
    card[1] = { "Карта 2", "Только метро", "01.01.2023", "31.01.2023", 70 };
    card[2] = { "Карта 3", "Только наземный ", "08.03.2023", "07.04.2023", 12 };
    int choice;
    while (true)
    {
        cout << "\nМеню:" << endl;
        cout << "1. Нарисовать матрицу" << endl;
        cout << "2. Подсчёт количества букв 'e' в строке" << endl;
        cout << "3. Создать характеристики проездных карт и посмотреть их" << endl;
        cout << "4. Вывести количество карт без поездок" << endl;
        cout << "5. Выход" << endl;
        cout << "\nВведите свой выбор: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Ошибка! Введите число согласно номеру в меню: ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1: {
            matrica();
        }
              break;

        case 2: {
            counter();
            break;
        }
        case 3: {
            ofstream out_file("card.txt");
            if (!out_file.is_open()) {
                cout << "Ошибка открытия файла" << endl;
                return 1;
            }
            for (int i = 0; i < 1; i++) {
                out_file << card[i].name << "\t\t" << card[i + 1].name << "\t\t\t" << card[i + 2].name << endl;
                out_file << card[i].type << "\t" << card[i + 1].type << "\t\t" << card[i + 2].type << endl;
                out_file << card[i].date1 << "\t\t" << card[i + 1].date1 << "\t\t\t" << card[i + 2].date1 << endl;
                out_file << card[i].date2 << "\t\t" << card[i + 1].date2 << "\t\t\t" << card[i + 2].date2 << endl;
                out_file << card[i].amount << "\t\t\t" << card[i + 1].amount << "\t\t\t\t" << card[i + 2].amount << endl;
            }
            out_file.close();
            int numcard = sizeof(card) / sizeof(card[0]);
            while (true) {
                cout << "\nИнформация о картах:" << endl;
                for (int i = 0; i < numcard; i++) {
                    cout << i + 1 << ". " << card[i].name << endl;
                }
                cout << numcard + 1 << ". Выход" << endl;
                cout << "\nВведите свой выбор: ";
                cin >> choice;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Ошибка! Введите число согласно номеру в меню: ";
                    cin >> choice;
                }
                if (choice == numcard + 1) {
                    break;
                }
                else if (choice >= 1 && choice <= numcard) {
                    card[choice - 1].printInfo();
                }
                else if (choice > 4) {
                    cout << "\nНеверный выбор. Попробуйте ещё раз." << endl;
                }
            }
            break;
            break;
        }
        case 4: {
            int c = 0;
            for (int i = 0; i < 3; i++)
            {
                if (card[i].amount == 0)
                {
                    c++;
                }
            }
            cout << "\n Количество карт без поездок: " << c << endl;

            break;
        }
        case 5: {
            return 0;
        }
        default: {
            cout << "\nНеверный выбор. Попробуйте ещё раз." << endl;
            break;
        }
        }
    }
    return 0;
}
