#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;
по зарплате
struct date
{
	int d, m, y;
};

struct people
{
	string surname;
	string dolsh;
	date dateofbrith;
	int salary;
	int stash;
};
date str_to_date(string s) {
	date x;
	string temp = s.substr(0, 2);
	x.d = atoi(temp.c_str());
	temp = s.substr(3, 2);
	x.m = atoi(temp.c_str());
	temp = s.substr(6, 4);
	x.y = atoi(temp.c_str());
	return x;
 }

vector<people> inFile() {
	vector<people> x;
	people temp;
	ifstream in("input.txt");
	if (!in.is_open()) {
		cout << "EOF,input" << endl;
		return x;
	}
	while (in >> temp.surname >> temp.dolsh) {
		string tmp;
		in >> tmp;
		temp.dateofbrith = str_to_date(tmp);
		in >> temp.salary;
		in >> temp.stash;
		x.push_back(temp); // Добавляем элемент в вектор
	}
	in.close();
	return x;
}

void print(people x,ofstream & out) {
	    out << setw(10) << left << x.surname<<' ';

    out << setw(10) << left << x.dolsh<<' ';

    if (x.dateofbrith.d < 10)
    	out << left << '0' <<setw(2)<<x.dateofbrith.d << '.';
    else
    	out << left <<setw(2)<< x.dateofbrith.d << '.';

    if (x.dateofbrith.m < 10)
    	out << left << '0' <<setw(2)<< x.dateofbrith.m << '.';
    else
    	out << setw(2)<<x.dateofbrith.m << '.';

    out << setw(4) << x.dateofbrith.y;

    out << setw(7) <<right<< x.salary;

    out << setw(4) <<right<< x.stash<<endl;
    	
       
}

bool operator < (people a, people b) {
	if (a.salary < b.salary)
		return true;
	return false;
}
void fastsort(vector<people>& arr, int low, int high) {
	if (low < high) {
		int i = low - 1;
		people pivot = arr[high]; // Опорный элемент

		
		for (int j = low; j < high; j++) {
			if (arr[j] < pivot) { // Сравнение по зарплате
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]); // Помещаем опорный элемент на правильное место
		int p = i + 1;

		
		fastsort(arr, low, p - 1);
		fastsort(arr, p + 1, high);
	}
}
int main() {
	vector<people> x = inFile();
	fastsort(x,0,x.size()-1);
	ofstream out("output.txt");
	if (!out.is_open()) {
		cout << "EOF,output" << endl;
		return 1;
	}
	
	for (int i = 0;i < x.size();i++)
		print(x[i],out);

	out.close();
	return 0;
}
 Сначала по году рождения, потом по стажу работы с помощью сортировки расческой
struct date
{
	int d, m, y;
};

struct people
{
	string surname;
	string dolsh;
	date dateofbrith;
	int salary;
	int stash;
};
date str_to_date(string s) {
	date x;
	string temp = s.substr(0, 2);
	x.d = atoi(temp.c_str());
	temp = s.substr(3, 2);
	x.m = atoi(temp.c_str());
	temp = s.substr(6, 4);
	x.y = atoi(temp.c_str());
	return x;
 }

vector<people> inFile() {
	vector<people> x;
	people temp;
	ifstream in("input.txt");
	if (!in.is_open()) {
		cout << "EOF,input" << endl;
		return x;
	}
	while (in >> temp.surname >> temp.dolsh) {
		string tmp;
		in >> tmp;
		temp.dateofbrith = str_to_date(tmp);
		in >> temp.salary;
		in >> temp.stash;
		x.push_back(temp); // Добавляем элемент в вектор
	}
	in.close();
	return x;
}

void print(people x,ofstream & out) {
	    out << setw(10) << left << x.surname<<' ';

    out << setw(10) << left << x.dolsh<<' ';

    if (x.dateofbrith.d < 10)
    	out << left << '0' <<setw(2)<<x.dateofbrith.d << '.';
    else
    	out << left <<setw(2)<< x.dateofbrith.d << '.';

    if (x.dateofbrith.m < 10)
    	out << left << '0' <<setw(2)<< x.dateofbrith.m << '.';
    else
    	out << setw(2)<<x.dateofbrith.m << '.';

    out << setw(4) << x.dateofbrith.y;

    out << setw(7) <<right<< x.salary;

    out << setw(4) <<right<< x.stash<<endl;
    	
}
bool operator<(date a, date b) {
	if (a.y != b.y)
		return a.y < b.y;
	if (a.m != b.m)
		return a.m < b.m;
	return a.d < b.d;
}
bool operator==(date a, date b) {
	return a.y == b.y && a.m == b.m && a.d == b.d;
}

bool operator < (people a, people b) {
	if (a.dateofbrith < b.dateofbrith)
		return true;
	if (a.dateofbrith == b.dateofbrith && a.stash > b.stash)
		return true;

	return false;
}
void combSort(vector<people>& arr) {
	int n = arr.size();
	int gap = n;
	bool swapped = true;

	while (gap != 1 || swapped) {
		gap = (gap * 10) / 13;
		if (gap < 1)
			gap = 1;

		swapped = false;

		for (int i = 0; i < n - gap; i++) {
			if (arr[i + gap] < arr[i]) {
				swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}
	}
}
int main() {
	vector<people> x = inFile();
	combSort(x);
	ofstream out("output.txt");
	if (!out.is_open()) {
		cout << "EOF,output" << endl;
		return 1;
	}
	
	for (int i = 0;i < x.size();i++)
		print(x[i],out);

	out.close();
	return 0;
}
 Сначала по зарплате, потом по году рождения, потом по стажу работы с помощью сортировки выбором
struct date
{
	int d, m, y;
};

struct people
{
	string surname;
	string dolsh;
	date dateofbrith;
	int salary;
	int stash;
};
date str_to_date(string s) {
	date x;
	string temp = s.substr(0, 2);
	x.d = atoi(temp.c_str());
	temp = s.substr(3, 2);
	x.m = atoi(temp.c_str());
	temp = s.substr(6, 4);
	x.y = atoi(temp.c_str());
	return x;
}

vector<people> inFile() {
	vector<people> x;
	people temp;
	ifstream in("input.txt");
	if (!in.is_open()) {
		cout << "EOF,input" << endl;
		return x;
	}
	while (in >> temp.surname >> temp.dolsh) {
		string tmp;
		in >> tmp;
		temp.dateofbrith = str_to_date(tmp);
		in >> temp.salary;
		in >> temp.stash;
		x.push_back(temp); // Добавляем элемент в вектор
	}
	in.close();
	return x;
}

void print(people x, ofstream& out) {
	out << setw(10) << left << x.surname << ' ';

	out << setw(10) << left << x.dolsh << ' ';

	if (x.dateofbrith.d < 10)
		out << left << '0' << setw(2) << x.dateofbrith.d << '.';
	else
		out << left << setw(2) << x.dateofbrith.d << '.';

	if (x.dateofbrith.m < 10)
		out << left << '0' << setw(2) << x.dateofbrith.m << '.';
	else
		out << setw(2) << x.dateofbrith.m << '.';

	out << setw(4) << x.dateofbrith.y;

	out << setw(7) << right << x.salary;

	out << setw(4) << right << x.stash << endl;

}
bool operator<(date a, date b) {
	if (a.y != b.y)
		return a.y < b.y;
	if (a.m != b.m)
		return a.m < b.m;
	return a.d < b.d;
}
bool operator==(date a, date b) {
	return a.y == b.y && a.m == b.m && a.d == b.d;
}

bool operator < (people a, people b) {
	if (a.salary < b.salary)
		return true;
	if (a.salary == b.salary && a.dateofbrith < b.dateofbrith)
		return true;
	if (a.salary == b.salary && a.dateofbrith == b.dateofbrith && a.stash < b.stash)
		return true;

	return false;
}
void selectionSort(vector<people>& arr) {
	int n = arr.size();

	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			swap(arr[i], arr[minIndex]);
		}
	}
}
int main() {
	vector<people> x = inFile();
	selectionSort(x);
	ofstream out("output.txt");
	if (!out.is_open()) {
		cout << "EOF,output" << endl;
		return 1;
	}

	for (int i = 0; i < x.size(); i++)
		print(x[i], out);

	out.close();
	return 0;
}
