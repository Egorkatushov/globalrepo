#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
//Дан неориентированный граф. Вывести количество вершин, смежных с данной.
int main() {
	int N, M;//N-количество вершин,M-количество ребер
	cin >> N >> M;

	vector<vector<int>>Gr(N);//список смежности
	for (int i = 0;i < M;i++) {//заполняем его 
		int x, y;
		cin >> x >> y;
		Gr[x].push_back(y);
		Gr[y].push_back(x);//неориентированный граф

	}
	int v;//то что нужно найти
	cin >> v;
	cout << Gr[v].size() << endl;//количество смежных вершин

	return 0;

}
