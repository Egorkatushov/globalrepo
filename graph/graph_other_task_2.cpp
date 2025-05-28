#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Дан ориентированный граф. Если это возможно, реализовать топологическую сортировку


struct stack {
    int inf;
    stack* next;
};

void push(stack*& h, int x) {
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack*& h) {
    int i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

bool empty(stack* h) {
    return h == nullptr;
}

void dfs(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    stack* st = nullptr;
    push(st, u);
    visited[u] = true;

    while (!empty(st)) {
        int c = pop(st);
        result.push_back(c);

        for (size_t i = 0; i < graph[c].size(); ++i) {
            int v = graph[c][i];
            if (!visited[v]) {
                visited[v] = true;
                push(st, v);
            }
        }
    }
}

vector<int> topologicalSort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> result;

    for (int u = 0; u < n; ++u) {
        if (!visited[u]) {
            dfs(u, graph, visited, result);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    cout << "Введите количество вершин и ребер: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);
    cout << "Введите ориентированные ребра (вершины нумеруются с 0):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> sorted = topologicalSort(graph);
    if (sorted.size() == n) {
        cout << "Топологическая сортировка: ";
        for (size_t i = 0; i < sorted.size(); i++) {
            cout << sorted[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Граф содержит цикл, топологическая сортировка невозможна" << endl;
    }

    return 0;
}
