#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Specialnist { COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS, PHYSICS_INFORMATICS, LABOR_STUDIES };
string specStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student {
    string prizv;
    unsigned kurs;
    Specialnist spec;
    int physics;
    int math;
    int informatics;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Sort(Student* s, const int N);
int BinSearch(Student* s, const int N, const string prizv, const Specialnist spec, const int informatics);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів N: "; cin >> N;

    Student* s = new Student[N];
    int menuItem;
    string prizv;
    int ispec, found, informatics;
    Specialnist spec;

    do {
        cout << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних" << endl;
        cout << " [2] - вивід даних" << endl;
        cout << " [3] - фізичне впорядкування даних" << endl;
        cout << " [4] - бінарний пошук студента" << endl;
        cout << " [0] - вихід" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl;

        switch (menuItem) {
        case 1:
            Create(s, N);
            break;
        case 2:
            Print(s, N);
            break;
        case 3:
            Sort(s, N);
            break;
        case 4:
            cout << "Введіть ключі пошуку:" << endl;
            cout << " спеціальність (0 - КН, 1 - ІНФ, 2 - МЕ, 3 - ФІ, 4 - ТН): ";
            cin >> ispec;
            spec = (Specialnist)ispec;
            cout << " оцінка з інформатики: "; cin >> informatics;
            cin.get();
            cin.sync();
            cout << " прізвище: "; getline(cin, prizv);
            cout << endl;

            if ((found = BinSearch(s, N, prizv, spec, informatics)) != -1)
                cout << "Знайдено студента в позиції " << found + 1 << endl;
            else
                cout << "Шуканого студента не знайдено" << endl;
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення!" << endl;
        }
    } while (menuItem != 0);

    delete[] s;
    return 0;
}

void Create(Student* s, const int N) {
    int spec;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " прізвище: "; getline(cin, s[i].prizv);
        cout << " курс: "; cin >> s[i].kurs;
        cout << " спеціальність (0 - КН, 1 - ІНФ, 2 - МЕ, 3 - ФІ, 4 - ТН): ";
        cin >> spec;
        s[i].spec = (Specialnist)spec;
        cout << " оцінка з фізики: "; cin >> s[i].physics;
        cout << " оцінка з математики: "; cin >> s[i].math;
        cout << " оцінка з інформатики: "; cin >> s[i].informatics;
        cout << endl;
    }
}

void Print(Student* s, const int N) {
    cout << "=============================================================================================="
        << endl;
    cout << "|  № |   Прізвище   | Курс |        Спеціальність       |  Фізика | Математика | Інформатика |"
        << endl;
    cout << "----------------------------------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << s[i].prizv
            << "| " << setw(4) << right << s[i].kurs << " "
            << "| " << setw(27) << left << specStr[s[i].spec]
            << "| " << setw(7) << right << s[i].physics << " "
            << "| " << setw(10) << right << s[i].math << " "
            << "| " << setw(11) << right << s[i].informatics << " |" << endl;
    }
    cout << "=============================================================================================="
        << endl;
    cout << endl;
}

void Sort(Student* s, const int N) {
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((s[i1].spec > s[i1 + 1].spec)
                || (s[i1].spec == s[i1 + 1].spec && s[i1].informatics > s[i1 + 1].informatics)
                || (s[i1].spec == s[i1 + 1].spec && s[i1].informatics == s[i1 + 1].informatics && s[i1].prizv > s[i1 + 1].prizv)) {
                tmp = s[i1];
                s[i1] = s[i1 + 1];
                s[i1 + 1] = tmp;
            }
}

int BinSearch(Student* s, const int N, const string prizv, const Specialnist spec, const int informatics) {
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (s[m].prizv == prizv && s[m].spec == spec && s[m].informatics == informatics)
            return m;
        if ((s[m].spec < spec)
            || (s[m].spec == spec && s[m].informatics < informatics)
            || (s[m].spec == spec && s[m].informatics == informatics && s[m].prizv < prizv)) {
            L = m + 1;
        }
        else {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}