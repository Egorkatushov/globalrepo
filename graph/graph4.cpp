#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

//Дан ориентированный граф. Вывести все вершины, недостижимые из данной.
vector<vector<int>> Gr;
vector<bool> visited;

void dfs(int v) {//обход в глубины
	visited[v] = true;
	for (int i = 0;i < Gr[v].size();i++) {
		int u = Gr[v][i];
		if (!visited[u]) {
			dfs(u);
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	int N, M, S;// N-вершины, M-ребра, S-старт
	cin >> N >> M >> S;

	Gr.resize(N);
	visited.assign(N, false);

	for (int i = 0;i < M;i++) {//заполняем
		int x, y;
		cin >> x >> y;
		Gr[x].push_back(y);//ориентирован
	}
	dfs(S);//стартуем 
	cout << "Недостижимые из" << S << "вершины: ";

	for (int v = 0;v < N;v++) {
		if (!visited[v]) {
			cout << v << " ";
		}
	}
	cout << endl;
	return 0;
}

