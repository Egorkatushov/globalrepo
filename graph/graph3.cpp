#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
//Дан неориентированный граф. Подсчитать степень каждой вершины.
int main() {
	setlocale(LC_ALL, "rus");
	int N, M; // N - количество вершин, M - количество рёбер
	cin >> N >> M;

	vector<vector<int>> Gr(N);//список смежности

	for (int i = 0; i < M; i++) {//заполняем его 
		int x, y;
		cin >> x >> y;
		Gr[x].push_back(y);
		Gr[y].push_back(x); // Граф неориентированный
	}
	cout << "Степень:" << endl;
	for (int v = 0;v < N;v++) {
		cout << " v = " << Gr[v].size() << endl;
	}
	return 0;
}
