#include<iostream>
#include<cctype>


using namespace std;

//Создать двусвязный список, содержащий целые числа. После всех чисел, равных минимальному числу, вставить последний четный элемент.
int mina = 10000000;
int last_even = 0;  // Будем хранить последний четный элемент

struct list {
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
    if (x < mina) {
        mina = x;
    }

    // Обновляем последний четный элемент
    if (x % 2 == 0) {
        last_even = x;
    }
}

void print(list* h) {
    list* p = h;
    while (p != NULL) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

void insert_after(list*& h, list*& t, list* r, int y) {
    list* p = new list;
    p->inf = y;

    if (r == t) {  // Если вставляем после хвоста
        r->next = p;
        p->prev = r;
        p->next = NULL;
        t = p;     // Обновляем хвост
    }
    else {         // Вставляем в середину
        p->next = r->next;
        p->prev = r;
        r->next->prev = p;
        r->next = p;
    }
}

void insertion(list*& h, list*& t) {
    if (last_even == 0) {  // Если нет четных элементов
        cout << "В списке нет четных " << endl;
        return;
    }

    list* p = h;
    while (p) {
        if (p->inf == mina) {
            insert_after(h, t, p, last_even);
            p = p->next;  // Пропускаем только что вставленный элемент
        }
        p = p->next;
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    cout << " количество ";
    int n;
    cin >> n;

    list* h = NULL;
    list* t = NULL;

    cout << " элементы  ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if (temp < mina) mina = temp;

        push(h, t, temp);
    }

    cout << "Исходный  ";
    print(h);

    insertion(h, t);

    cout << "Результат ";
    print(h);

     //Освобождение памяти
    while (h) {
        list* temp = h;
        h = h->next;
        delete temp;
    }

    return 0;
}


//Создать двусвязный список, содержащий целые числа.  Перенести в конец списка числа, меньшие Х.
struct list {
    int inf;
    list* next;
    list* prev;
};

// Добавление элемента в конец списка
void push(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->next = nullptr;
    if (!h && !t) {
        r->prev = nullptr;
        h = t = r;
    }
    else {
        t->next = r;
        r->prev = t;
        t = r;
    }
}

// Удаление узла из списка (без освобождения памяти)
void del_node(list*& h, list*& t, list* r) {
    if (!r) return;

    // Если удаляется единственный элемент
    if (r == h && r == t) {
        h = t = nullptr;
    }
    // Если удаляется голова
    else if (r == h) {
        h = h->next;
        if (h) h->prev = nullptr;
    }
    // Если удаляется хвост
    else if (r == t) {
        t = t->prev;
        if (t) t->next = nullptr;
    }
    // Если удаляется элемент из середины
    else {
        r->prev->next = r->next;
        r->next->prev = r->prev;
    }
}

// Перенос чисел меньших X в конец списка
void move_smaller_to_end(list*& h, list*& t, int X) {
    if (!h) return;

    // Сначала подсчитаем количество элементов меньших X
    int count = 0;
    list* current = h;
    while (current) {
        if (current->inf < X) count++;
        current = current->next;
    }
    //переносим элементы в конец списка
    current = h;
    while (current && count > 0) {
        list* next_node = current->next;

        if (current->inf < X) {
            int v = current->inf;
            del_node(h, t, current);
            delete current;
            push(h, t, v);
            count--;//уменьшаем счетчик 
        }
        current = next_node;//новый узел 
    }
}

// Вывод списка
void print(list* h) {
    list* p = h;
    while (p != nullptr) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    list* h = nullptr;
    list* t = nullptr;

    // Ввод данных
    int n, x;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, t, x);
    }

    cout << "Исходный список: ";
    print(h);

    int X;
    cout << "Введите X: ";
    cin >> X;

    move_smaller_to_end(h, t, X);

    cout << "Список после переноса элементов < " << X << ": ";
    print(h);

    // Очистка памяти
    while (h) {
        list* tmp = h;
        h = h->next;
        delete tmp;
    }

    return 0;
}
//Создать двусвязный список, содержащий целые числа. Выполнить быструю сортировку, меняя указатели, а не значения.
struct list
{
	int inf;
	list* next;
	list* prev;
};
void push(list*& h, list*& t, int x) {
	list* r = new list;
	r->inf = x;
	r->next = nullptr;
	if (!h && !t) {
		r->prev = nullptr;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void print(list* h) {
	list* p = h;
	while (p != nullptr) {
		cout << p->inf << " ";
		p = p->next;
	}
	cout << endl;
}

list* gett(list* c) {//ищем полследный узел
	while (c && c->next) {
		c = c->next;
	}
	return c;
}
//делим список
list* partition(list* t, list* h) {
	int x = h->inf;//опроный элемент 
	list* i = t->prev;

	for (list* j = t;j != h;j = j->next) {
		if (j->inf > x) {
			if (i == nullptr) {
				i = t;
			}
			else {
				i = i->next;
			}
			swap(i->inf, j->inf);
		}
	}
	if (i == nullptr) {
		i = t;
	}
	else {
		i = i->next;
	}
	swap(i->inf, h->inf);
	return i;
}

void quick(list* t, list* h) {//функция быстрой сортировки 
	if (h != nullptr && t != h && t != h->next) {
		list* p = partition(t, h);
		quick(t, p->prev);
		quick(p->next, h);
	}
}

void sort(list*& h) {//основная функция быстрой сортировки 
	list* tmp = gett(h);
	quick(h, tmp);
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << " количество ";cin >> n;
	list* h = nullptr;
	list* t = nullptr;
	cout << "элементы" << endl;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		push(h, t, x);  // Добавляем элементы в список
	}
	cout << " исхожный " << endl;
	print(h);
	sort(h);
	cout << "готовый" << endl;
	print(h);
	while (h) {
		list* tmp = h;
		h = h->next;
		delete tmp;
	}
	return 0;
}
