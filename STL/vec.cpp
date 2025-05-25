#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
 
using namespace std;
//Дан набор целых чисел. Удалить все минимальные числа.
//int main() {
//	setlocale(LC_ALL, "rus");
//	int n;
//	cout << " n= ";cin >> n;
//	vector<int>a;////создаем вектор 
//	int x;
//	for (int i = 0;i < n;i++) {////заполняем его 
//		cout << "a[" << i << "]=";
//		cin >> x;
//		a.push_back(x);
//	}
//	for (vector<int>::iterator iter = a.begin(); iter != a.end();iter++)////  выводим его 
//		cout << *iter;
//	cout << endl;
//
//	cout << " Удаление мин элементов";
//	int s = *min_element(a.begin(), a.end());////ищем минимальный элемент 
//	a.erase(remove(a.begin(),a.end(),s),a.end());////удаляем его 
//	for (vector<int>::iterator iter = a.begin(); iter != a.end();iter++)////и выводим результат 
//		cout << *iter;
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
//Дана последовательность целых чисел. Вывести данные в обратном порядке.
// Заменить числа, попадающие в интервал [a, b] числом x. Отсортировать элементы. 
// Вставить новый элемент в отсортированную последовательность (Оптимальным способом. 
// Вставить в конец и потом опять отсортировать - не оптимально). Удалить все повторяющиеся элементы.


//bool bek(int s, int d) {
//	return s > d;
//}
//int main() {
//	setlocale(LC_ALL, "rus");
//	int n;
//	cout << " n= ";cin >> n;
//	vector<int>v;////создаем вектор 
//	int e;
//	for (int i = 0;i < n;i++) {////заполняем его 
//		cout << "a[=" << i << "]";
//		cin >> e;
//		v.push_back(e);
//	}
//	for (vector<int>::iterator iter = v.begin();iter != v.end();iter++)////выводим 
//		cout << *iter;
//	cout << endl;
//
//	cout << "Обратный порядок";
//	for (int i = v.size() - 1;i >= 0;i--)////выводим вектор в обратным порядке
//		cout << v[i] << " ";
//
//	cout << "Замена из диапозона [a,b] ";
//	int a = 2, b=5,x=0;
//	cin >> a >> b;
//	replace_if(v.begin(), v.end(), [&a, &b] (int x) { return x >= a && x <= b; },x);////заменяем все числа попадающие в диапозон 
//	for (vector<int>::iterator iter = v.begin();iter != v.end();iter++)
//		cout << *iter;
//	cout << endl;
//
//	cout << "Сортировка";
//	sort(v.begin(), v.end(), bek);////производим сортировку 
//	for (vector<int>::iterator iter = v.begin();iter != v.end();iter++)
//		cout << *iter;
//	cout << endl;
//	
//	cout << " Вставить новый элемент в отсортированную последовательность ";
//	int y = 8;
//	auto pos = lower_bound(v.begin(), v.end(), y);
//	v.insert(pos, y);////вставляем новый элемент 
//	for (vector<int>::iterator iter = v.begin();iter != v.end();iter++)
//		cout << *iter;
//	cout << endl;
//
//	cout << "Удаление";
//	vector<int>::iterator it = unique(v.begin(), v.end());////удаляем повторные элементы  
//	v.erase(it, v.end());
//	for (vector<int>::iterator iter = v.begin();iter != v.end();iter++)
//		cout << *iter;
//	cout << endl;
//	return 0;
//}


//Используя библиотеки numeric и functional, найти первые n чисел Фибоначчи.

//vector<int>fib(int n) {////создаем числа фибоначи 
//	if (n <= 0)
//		return {};
//	vector<int>f(n);
//	if (n > 0)
//		f[0] = 0;
//	if (n > 1)
//		f[1] = 1;
//	partial_sum(f.begin(), f.end() - 2, f.begin() + 2, plus<int>());
//	return f;
//}
//int main() {
//	setlocale(LC_ALL, "rus");
//	int n;
//	cout << " n= ";cin >> n;
//	vector<int>a = fib(n);
//
//	cout << "Первые числа фибоначи = ";
//	for (vector<int>::iterator iter = a.begin(); iter != a.end();iter++)
//		cout << *iter;
//	cout << endl;
//	return 0;
//
//
//}
