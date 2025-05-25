#include<iostream>
#include<set>
#include<algorithm>
#include<numeric>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include<sstream>

using namespace std;
//Дана последовательность целых чисел. Найти все такие цифры, которые встречаются в двузначных числах, 
// но не встречаются в трехзначных. 
// Работать только с цифрами, которые встречаются в данной последовательности, 
// а не со всеми цифрами от 0 до 9
bool f1(int x) {
	return x >= 10 && x <= 100;//проверка на двухзначное число
}
bool f2(int x) {
	return x >= 100 && x <= 1000;//проверка на трехзначнок число
}
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << " n= "; cin >> n;
	set<int> a, b, c;
	for (int i = 0; i < n; i++) {
		int s;
		cout << "s=";
		cin >> s;
		a.insert(s);
	}
	for (set<int>::iterator it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	cout << endl;
	for (set<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
		int x = *iter;
		if (f1(x)) while (x) { b.insert(x % 10); x /= 10; }
		if (f2(x)) while (x) { c.insert(x % 10); x /= 10; }
	}
	for (set<int>::iterator it = b.begin(); it != b.end(); it++)
		cout << *it << " ";
	cout << endl;
	for (set<int>::iterator it = c.begin(); it != c.end(); it++)
		cout << *it << " ";
	cout << endl;
	set<int> res;
	set_difference(b.begin(), b.end(), c.begin(), c.end(), inserter(res, res.begin()));
	for (set<int>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << " ";
	cout << endl;
}

//Дан текст, состоящий из предложений, разделенных знаками препинания из набора «.?!». 
// Предложения в свою очередь состоят из слов, отделенных друг от друга пробелами. 
// Найти слова (без учета регистра), 
// которые встречаются только в восклицательных предложениях.

//string str_tolewer(string s) {
//	for (int i = 0; i < s.length(); i++)
//		s[i] = tolower(s[i]);
//	return s;
//}
//set<string> set_word(string s) {
//	set<string> set_s;
//	if (s[s.length() - 1] != ' ')
//		s += " ";
//	while (s != "") {
//		set_s.insert(str_tolewer(s.substr(0, s.find(' '))));
//		s.erase(0, s.find(' ') + 1);
//	}
//	return set_s;
//}
//int main() {
//	string s, a;
//	setlocale(LC_ALL, "rus");
//	cout << "Введите текст";
//	getline(cin, s);
//	set<string> r, p, v, t;
//	while (s != "") {
//		int pos = s.find_first_of(".!?");
//		a = s.substr(0, pos);
//		t = set_word(a);
//		if (s[pos] == '.') p.insert(t.begin(), t.end());
//		if (s[pos] == '!')v.insert(t.begin(), t.end());
//		if (s[pos] == '?')r.insert(t.begin(), t.end());
//		s.erase(0, pos + 2);
//	}
//	set<string> res;
//		set_union(p.begin(), p.end(), r.begin(), r.end(), inserter(res, res.begin()));
//		for (set<string>::iterator i = res.begin(); i != res.end(); i++)
//			cout << *i << " ";
//		cout << endl;
//		set<string> rus;
//		set_difference(v.begin(),v.end(),res.begin(),res.end(), inserter(rus, rus.begin()));
//		for (set<string>::iterator i = rus.begin(); i != rus.end(); i++)
//			cout << *i << " ";
//		cout << endl;
//	
//	}


	



//Во входном файле задан набор слов и целых чисел, разделенных пробелами. 
//Найти все слова, 
//встречающиеся столько же раз, 
//сколько первое число (Первое число - в первоначальном наборе данных, а не в итоговом).


//int main() {
//    setlocale(LC_ALL, "rus");
//    ifstream f("1.txt"); // Открываем файл с данными
//    if (!f.is_open()) {
//        cout << "Ошибка открытия файла!" << endl;
//        return 1;
//    }
//
//    string k="0123456789";
//    map<string, int> wordCount,numbers; //  для хранения  слов
//    vector<string> ; // Вектор для хранения чисел
//    string word;
//    int number;
//    string firstNumber;
//   
//    while (f >> word) {// Читаем слова и числа из файла
//        if (word.find_first_not_of(k)==string::npos) { // Проверяем, является ли строка числом
//            if (numbers.empty())
//                firstNumber = word;
//            numbers[word]++;
//        }
//        else {
//            wordCount[word]++; // Увеличиваем счетчик для слова
//        }
//    }
//
//    f.close(); // Закрываем файл
//
//    if (numbers.empty()) {
//        cout << "В файле не найдено чисел!" << endl;
//        return 1;
//    }
//
//    
//    number = numbers[firstNumber];// Первое число из файла
//
//   
//    cout << "Слова, встречающиеся " << firstNumber << " раз: " << endl; // Находим и выводим слова, число котороых равно первому числу
//    for (const auto& pair : wordCount) {
//        if (pair.second == number) {
//            cout << pair.first <<endl;
//        }
//    }
//
//    return 0;
//}
