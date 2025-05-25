//Дано дерево. Подсчитать сумму листьев.
#include <iostream>
#include <iomanip>
using namespace std;

struct tree {
    int inf;
    tree* left;
    tree* right;
    int height;
};

tree* node(int x) {
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int height(tree* t) {
    if (t != nullptr) {
        return t->height;
    }
    else {
        return 0;
    }
}

void newheight(tree* t) {
    int hl = height(t->left);
    int hr = height(t->right);
    t->height = (hl > hr ? hl : hr) + 1;
}

tree* povorot_right(tree* t) {
    tree* q = t->left;
    t->left = q->right;
    q->right = t;
    newheight(t);
    newheight(q);
    return q;
}

tree* povorot_left(tree* t) {
    tree* p = t->right;
    t->right = p->left;
    p->left = t;
    newheight(t);
    newheight(p);
    return p;
}

tree* balance(tree* t) {
    newheight(t);
    if (height(t->right) - height(t->left) == 2) {
        if (height(t->right->right) - height(t->right->left) < 0)
            t->right = povorot_right(t->right);
        return povorot_left(t);
    }
    if (height(t->right) - height(t->left) == -2) {
        if (height(t->left->right) - height(t->left->left) > 0)
            t->left = povorot_left(t->left);
        return povorot_right(t);
    }
    return t;
}

tree* insert(tree* t, int x) {
    if (!t) return node(x);
    if (x < t->inf)
        t->left = insert(t->left, x);
    else
        t->right = insert(t->right, x);
    return balance(t);
}

// Функция для подсчета суммы листьев
int suma(tree* t) {
    if (!t) return 0;
    if (!t->left && !t->right) // Если это лист
        return t->inf;
    return suma(t->left) + suma(t->right);
}

void input_tree(tree*& root) {
    int n, x;
    cout << "Количество элементов: ";
    cin >> n;
    cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        root = insert(root, x);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    tree* root = NULL;
    input_tree(root);

    int sum = suma(root);
    cout << "Сумма листьев AVL дерева: " << sum << endl;

    return 0;
}
