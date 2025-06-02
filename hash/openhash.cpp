#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

//Основная — линейное хеширование, вспомогательная — метод умножения по году
ifstream in("input.txt");
ofstream out("output.txt");

struct date {
    int dd, mm, yy;
};

struct people {
    string surname;
    string position;
    date dob;
    int exp;
    int salary;
    bool is_empty; // Флаг пустой ячейки
};

date strdate(string str) {
    date x;
    x.dd = stoi(str.substr(0, 2));
    x.mm = stoi(str.substr(3, 2));
    x.yy = stoi(str.substr(6, 4));
    return x;
}

vector<people> inFile() {
    vector<people> x;
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        people temp;
        string date_str;
        if (iss >> temp.surname >> temp.position >> date_str >> temp.exp >> temp.salary) {
            temp.dob = strdate(date_str);
            temp.is_empty = false;
            x.push_back(temp);
        }
    }
    return x;
}
void print(people x) {
    if (x.is_empty) {
        cout << setw(12) << left << "NULL";
        cout << setw(15) << left << "NULL";
        cout << setw(12) << left << "NULL";
        cout << setw(6) << left << "NULL";
        cout << setw(10) << left << "NULL" << endl;
        return;
    }

    cout << setw(12) << left << x.surname;
    cout << setw(15) << left << x.position;
    cout << setw(2) << right << setfill('0') << x.dob.dd << ".";
    cout << setw(2) << right << setfill('0') << x.dob.mm << ".";
    cout << setw(6) << left << setfill(' ') << x.dob.yy;
    cout << setw(10) << left << x.exp;
    cout << setw(10) << left << x.salary << endl;
}

// Метод умножения (вспомогательная хэш-функция)
int hash_multiply(int year, int table_size) {
    const double A = (sqrt(5) - 1) / 2; // Золотое сечение
    double val = year * A;
    val -= (int)val; // Дробная часть
    return (int)(table_size * val);
}

// Линейное хеширование (основная функция)
int linear_hash(int year, int i, int table_size) {
    return (hash_multiply(year, table_size) + i) % table_size;
}

vector<people> create_hash_table(vector<people>& employees, int table_size) {
    vector<people> hash_table(table_size);

    // Инициализация пустой таблицы
    for (int i = 0; i < table_size; i++) {
        hash_table[i].is_empty = true;
    }

    // Заполнение таблицы
    for (const auto& emp : employees) {
        int i = 0;
        while (i < table_size) {
            int hash = linear_hash(emp.dob.yy, i, table_size);
            if (hash_table[hash].is_empty) {
                hash_table[hash] = emp;
                hash_table[hash].is_empty = false;
                break;
            }
            i++;
        }
        if (i >= table_size) {
            cerr << "Ошибка: Не удалось вставить сотрудника " << emp.surname << endl;
        }
    }

    return hash_table;
}

void search_in_hash_table(vector<people>& hash_table, int search_year) {
    int table_size = hash_table.size();
    bool found = false;

    for (int i = 0; i < table_size; i++) {
        int hash = linear_hash(search_year, i, table_size);
        if (hash_table[hash].is_empty) break;
        if (hash_table[hash].dob.yy == search_year) {
            cout << "\nНайден сотрудник:\n";
            print(hash_table[hash]);
            found = true;
        }
    }

    if (!found) {
        cout << "\nСотрудники с годом рождения " << search_year << " не найдены." << endl;
    }
}

void print_hash_table(vector<people>& hash_table) {
    cout << "\nХэш-таблица (линейное хеширование + метод умножения по году):\n";
    cout << "Индекс | Фамилия     | Должность      | Дата рожд. | Стаж  | Зарплата\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < hash_table.size(); i++) {
        cout << setw(6) << left << i << " | ";
        print(hash_table[i]);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    vector<people> employees = inFile();
    int table_size = 23; // Лучше использовать простое число

    vector<people> hash_table = create_hash_table(employees, table_size);
    print_hash_table(hash_table);

    int search_year;
    cout << "\nВведите год рождения для поиска: ";
    cin >> search_year;
    search_in_hash_table(hash_table, search_year);

    return 0;
}
