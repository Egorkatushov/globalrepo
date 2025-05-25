// Дано дерево. Подсчитать сумму листьев
#include <iostream>
using namespace std;

struct Tree {
    int inf;
    Tree* left;
    Tree* right;
    Tree* parent;
    char color;
};

Tree* node(int x, Tree* parent = nullptr, char color = 'r') {
    Tree* n = new Tree;
    n->inf = x;
    n->left = n->right = nullptr;
    n->parent = parent;
    n->color = color;
    return n;
}

void povorotleft(Tree*& root, Tree* x) {
    Tree* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) {
        root = y;
    }
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void povorotright(Tree*& root, Tree* x) {
    Tree* y = x->left;
    x->left = y->right;
    if (y->right) y->right->parent = x;
    y->parent = x->parent;
    if (!x->parent) {
        root = y;
    }
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->right = x;
    x->parent = y;
}

void balance(Tree*& root, Tree* z) {
    Tree* parent = nullptr;
    Tree* grand_parent = nullptr;

    while ((z != root) && (z->color != 'b') && (z->parent->color == 'r')) {
        parent = z->parent;
        grand_parent = parent->parent;

        // родитель - левый ребенок деда
        if (parent == grand_parent->left) {
            Tree* uncle = grand_parent->right;

            //  дядя красный - только перекрашивание
            if (uncle != nullptr && uncle->color == 'r') {
                grand_parent->color = 'r';
                parent->color = 'b';
                uncle->color = 'b';
                z = grand_parent;
            }
            else {
                //  z - правый ребенок - левый поворот
                if (z == parent->right) {
                    povorotleft(root, parent);
                    z = parent;
                    parent = z->parent;
                }

                //  z - левый ребенок - правый поворот
                povorotright(root, grand_parent);
                swap(parent->color, grand_parent->color);
                z = parent;
            }
        }
        //  родитель - правый ребенок деда
        else {
            Tree* uncle = grand_parent->left;

            //  дядя красный - только перекрашивание
            if (uncle != nullptr && uncle->color == 'r') {
                grand_parent->color = 'r';
                parent->color = 'b';
                uncle->color = 'b';
                z = grand_parent;
            }
            else {
                //  z - левый ребенок - правый поворот
                if (z == parent->left) {
                    povorotright(root, parent);
                    z = parent;
                    parent = z->parent;
                }

                //  z - правый ребенок - левый поворот
                povorotleft(root, grand_parent);
                swap(parent->color, grand_parent->color);
                z = parent;
            }
        }
    }

    root->color = 'b';
}

void insert(Tree*& root, Tree* parent, int value, char color) {
    if (!root) {
        root = node(value, parent, color);
        if (root->color == 'r' && root->parent && root->parent->color == 'r') {
            balance(root, root);
        }
        return;
    }
    if (value < root->inf) {
        insert(root->left, root, value, color);
    }
    else {
        insert(root->right, root, value, color);
    }
}

void newtree(Tree*& root) {
    int n, value;
    char color;

    cout << "Введите количество узлов: ";
    cin >> n;

    if (n <= 0) return;

    cout << "Корень (значение и цвет, например: 10 b): ";
    cin >> value >> color;

    char node_color;
    if (color == 'b') {
        node_color = 'b';
    }
    else {
        node_color = 'r';
    }
    root = node(value, nullptr, node_color);

    for (int i = 1; i < n; ++i) {
        cout << "Узел " << i + 1 << " (значение и цвет): ";
        cin >> value >> color;

        char node_color;
        if (color == 'b') {
            node_color = 'b';
        }
        else {
            node_color = 'r';
        }
        insert(root, nullptr, value, node_color);
    }
}
void print(Tree* root) {
    if (!root) return;
    cout << root->inf << "(" << root->color << ") ";
    print(root->left);
    print(root->right);
}

int suma(Tree* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->inf;
    return suma(root->left) + suma(root->right);
}

int main() {
    setlocale(LC_ALL, "rus");
    Tree* root = nullptr;

    cout << "Ввод дерева\n";
    newtree(root);

    cout << "\nДерево: ";
    print(root);

    cout << "\nСумма листьев: " << suma(root) << endl;

    return 0;
}
