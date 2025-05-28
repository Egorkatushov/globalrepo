#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

//Дан неориентированный граф. Вставить в граф ребро, соединяющее вершины A и B.
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

    int A, B;//новые ребра
    cin >> A >> B;

    
    if (find(Gr[A].begin(), Gr[A].end(), B) == Gr[A].end()) {//проверка на сущ ребра
        Gr[A].push_back(B);
        Gr[B].push_back(A);
        cout << "Ребро " << A << "-" << B << " добавлено." << endl;
    }
    else {
        cout << "Ребро " << A << "-" << B << " уже существует." << endl;
    }

    return 0;
}
