#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;
//Дан список целых чисел. Построить дерево бинарного поиска. Дан узел Х.
 //Если он существует в дереве, найти его "внуков" (дети детей этого узла).
struct tree {
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};
//создание нового узла
tree* node(int x) {
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = nullptr;
	n->parent = nullptr;
	return n;
}
//вставка элемента в дерево бинарного поиска

void insert(tree*& tr, int x) {
	tree* n = node(x);
	if (!tr)
		tr = n;//если дереао пустое-корень
	else {
		tree* y = tr;
		while (y) {
			if (n->inf > y->inf) {//правая ветка
				if (y->right)
					y = y->right;
				else {
					n->parent = y;//становиться правым ребенком
					y->right = n;
					break;
				}
			}
			else if (n->inf < y->inf) {//левая ветка
				if (y->left)
					y = y->left;
				else {
					n->parent = y;//левый ребенок
					y->left = n;
					break;
				}
			}
			else {//элементы уже есть
				delete n;
				break;
			}
		}
	}
}

//поиск узла по значению
tree* find(tree* tr, int x) {
	if (tr && x == tr->inf)//нащли или долшли до конца ветки
		return tr;
	if (x < tr->inf)
		return find(tr->left, x);//по левой ветке
	else
		return find(tr->right, x);//по правой ветке
}
//поиск внуков
vector<int> find_grandchildern(tree* node) {
	vector<int> grandchildren;
	if (!node)
		return grandchildren;
	if (node->left) {// проверка левого ребенка и его детей
		if (node->left->left)
			grandchildren.push_back(node->left->left->inf);
		if (node->left->right)
			grandchildren.push_back(node->left->right->inf);
	}
	if (node->right) {//правый ребонок и его дети
		if (node->right->left)
			grandchildren.push_back(node->right->left->inf);
		if (node->right->right)
			grandchildren.push_back(node->right->right->inf);
	}
	return grandchildren;
}

//симетричный обход для вывода дерева
void inorder(tree* tr) {
	if (tr) {
		inorder(tr->left);
		cout << tr->inf << " ";
		inorder(tr->right);
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	tree* r = nullptr;
	vector<int> numbers;
	int x, target;

	cout << "Количество:";
	int n; cin >> n;

	cout << "Элементы:";
	for (int i = 0;i < n;i++) {
		cin >> x;
		numbers.push_back(x);
		insert(r, x);
	}
	cout << "Обход симетричный:";
	inorder(r);
	cout << endl;

	cout << "Введите узел для поиска";
	cin >> target;

	tree* v = find(r, target);
	if (!v) {
		cout << " Узел " << target << " нету в дереве " << endl;
	}
	else {
		vector<int> grandchildren = find_grandchildern(v);
		if (grandchildren.empty()) {
			cout << " У узла " << target << " нет внуков " << endl;
		}
		else {
			cout << " Внуки " << target << " = ";
			for (size_t i = 0;i < grandchildren.size();i++) {
				cout << grandchildren[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}





//Дан список целых чисел. Построить дерево бинарного поиска. 
 //Найти сумму внутренних узлов дерева.
struct tree {
    int inf;
    tree* left;
    tree* right;
    tree* parent;
};

// Создание нового узла
tree* node(int x) {
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = nullptr;
    n->parent = nullptr;
    return n;
}

// Вставка элемента в дерево бинарного поиска
void insert(tree*& tr, int x) {
    tree* n = node(x);
    if (!tr)
        tr = n; // если дерево пустое - корень
    else {
        tree* y = tr;
        while (y) {
            if (n->inf > y->inf) { // правая ветка
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y;
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf) { // левая ветка
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y;
                    y->left = n;
                    break;
                }
            }
            else { // элемент уже есть
                delete n;
                break;
            }
        }
    }
}

// Симметричный обход для вывода дерева
void inorder(tree* tr) {
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

//является ли узел внутренним
bool internal(tree* node) {
    return node && (node->left || node->right);
}

//подсчет узлов
bool summa(tree* tr, int& s) {
    if (tr) {
        if (internal(tr)) {
            s += tr->inf;
        }
        summa(tr->left, s);
        summa(tr->right, s);
    }
    return tr;
}
int main() {
    setlocale(LC_ALL, "rus");
    tree* r = nullptr;
    vector<int>numbers;
    int x;

    cout << "Количество :";
    int n; cin >> n;

    cout << "Элементы :";
    for (int i = 0;i < n;i++) {
        cin >> x;
        numbers.push_back(x);
        insert(r, x);
    }
    cout << "Симметричный обход :";
    inorder(r);
    cout << endl;
    int sum = 0;
    summa(r, sum);

    if (r && !internal(r)) {
        sum -= r->inf;
    }

    cout << "Сумма узлов: " << sum << endl;
    return 0;
}
