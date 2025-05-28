#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

//Дан ориентированный граф. Вывести все истоки графа.
vector<vector<int>> Gr;  // Список смежности
vector<bool> visited;    // Массив посещённых вершин
int N;                   // Количество вершин

// Обход в глубину из вершины v
void dfs(int v) {
    visited[v] = true;
    for (int u : Gr[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

// Проверка, является ли v истоком
bool isSource(int v) {
    visited.assign(N, false);  // Сбрасываем посещения
    dfs(v);                    // Запускаем DFS из v
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {     // Если хоть одна вершина недостижима
            return false;      // v — не исток
        }
    }
    return true;               // Все вершины достижимы → v исток
}

int main() {
    int M;  // Количество рёбер
    cin >> N >> M;

    Gr.resize(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        Gr[x].push_back(y);  // Граф ориентированный
    }

    cout << "Истоки графа: ";
    for (int v = 0; v < N; v++) {
        if (isSource(v)) {
            cout << v << " ";
        }
    }
    cout << endl;

    return 0;
}
