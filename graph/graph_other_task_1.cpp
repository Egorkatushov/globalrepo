#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
Дан неориентированный граф. Вывести Эйлеров путь или Эйлеров цикл, если он существует.
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

vector<int> euler(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> d(n, 0);
    for (int u = 0; u < n; ++u) {
        d[u] = graph[u].size();
    }

    // Проверка условий существования Эйлерова пути/цикла
    int count = 0;
    int s = 0;
    for (int u = 0; u < n; ++u) {
        if (d[u] % 2 != 0) {
            count++;
            s = u;
        }
    }

    if (count != 0 && count != 2) {
        return {};
    }

    stack* st = nullptr;
    push(st, s);
    vector<int> path;

    while (!empty(st)) {
        int u = st->inf;
        if (d[u] == 0) {
            path.push_back(pop(st));
        }
        else {
            int v = graph[u].back();
            graph[u].pop_back();
            auto it = find(graph[v].begin(), graph[v].end(), u);
            if (it != graph[v].end()) {
                graph[v].erase(it);
            }
            d[u]--;
            d[v]--;
            push(st, v);
        }
    }

    return path;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    cout << "Введите количество вершин и ребер: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);
    cout << "Введите ребра (вершины нумеруются с 0):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> result = euler(graph);
    if (!result.empty()) {
        if (result.front() == result.back()) {
            cout << "Эйлеров цикл: ";
        }
        else {
            cout << "Эйлеров путь: ";
        }
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
