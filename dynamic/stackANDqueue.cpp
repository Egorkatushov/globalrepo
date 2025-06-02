#include<iostream>
#include<cctype>


using namespace std;

struct  stack{
	int inf;
	stack* next;
};

bool prost(int n) {//находим простое число 
	if (n == 1)
		return false;
	for (int i = 2;i <= sqrt(n);i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
void push(stack*& h, int x) {//вставка
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}
int pop(stack*& h) {// удаление
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack*& h) {
	stack* head1 = NULL;
	while (h)
		push(head1, pop(h));
	h = head1;
}

stack* resultat(stack*& h) {
	stack *res = NULL;
	stack* tmp = NULL;
	while (h) {
		int x = pop(h);
		push(res, x);
		if (prost(x)) {
			push(res, 0);
		}
	}
	reverse(res);//переворачиваем
	return res;

}

int main() {
	int n;
	cout << " n= ";
	cin >> n;
	stack *head = NULL;
	int x;
	for (int i = 0;i < n;i++) {
		cin >> x;
		push(head, x);
	}
	reverse(head);
	stack* res = resultat(head);
	while (res)
		cout << pop(res) << " ";
	cout << endl;
	return 0;
}
//Создать очередь, содержащую целые числа. Удалить первый и последний четный элемент. 


struct queue {
    int inf;
    queue* next;
};

// Функция добавления элемента в очередь
void push(queue*& h, queue*& t, int x) {
    queue* r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        h = t = r;
    }
    else {
        t->next = r;
        t = r;
    }
}

// Функция удаления элемента из очереди
int pop(queue*& h, queue*& t) {
    queue* r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

// Функция для удаления первого и последнего четных элементов
void remove(queue*& h, queue*& t) {
    if (!h) return; // Если очередь пуста

    queue* tempH = NULL, * tempT = NULL; // Временная очередь для хранения элементов
    int firstEvenPos = -1, lastEvenPos = -1;
    int currentPos = 0;
    queue* current = h;
    while (current) {
        if (current->inf % 2 == 0) {
            if (firstEvenPos == -1) {
                firstEvenPos = currentPos;
            }
            lastEvenPos = currentPos;
        }
        currentPos++;
        current = current->next;
    }

    // Если нет четных элементов или только один четный элемент
    if (firstEvenPos == -1) return;
    if (firstEvenPos == lastEvenPos) {
        // Удаляем единственный четный элемент
        currentPos = 0;
        while (h) {
            int x = pop(h, t);
            if (currentPos != firstEvenPos) {
                push(tempH, tempT, x);
            }
            currentPos++;
        }
    }
    else {
        // Удаляем первый и последний четные элементы
        currentPos = 0;
        while (h) {
            int x = pop(h, t);
            if (currentPos != firstEvenPos && currentPos != lastEvenPos) {
                push(tempH, tempT, x);
            }
            currentPos++;
        }
    }

    // Возвращаем элементы в исходную очередь
    h = tempH;
    t = tempT;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, x;
    cout << "Введите количество элементов: ";
    cin >> n;

    queue* h = NULL, * t = NULL; // Исходная очередь

    cout << "Введите элементы: ";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        push(h, t, x); // Заполняем очередь
    }

    cout << "Исходная очередь: ";
    queue* temp = h;
    while (temp) {
        cout << temp->inf << " ";
        temp = temp->next;
    }
    cout << endl;

    remove(h, t); // Удаляем первый и последний четные элементы

    cout << "Очередь после удаления: ";
    while (h) {
        cout << pop(h, t) << " ";
    }
    cout << endl;

    return 0;
}
//Создать очередь из целых чисел. Выполнить циклический сдвиг очереди так, чтобы на первом месте был первый минимальный элемент. 


// Структура узла очереди
struct queue {
    int inf;
    queue* next;
};

// Добавление элемента в очередь
void push(queue*& h, queue*& t, int x) {
    queue* r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        h = t = r;
    }
    else {
        t->next = r;
        t = r;
    }
}

// Удаление элемента из очереди
int pop(queue*& h, queue*& t) {
    queue* r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

// Функция для поиска первого минимального элемента
int find(queue* h) {
    if (!h) return -1;

    int minVal = h->inf;
    int minPos = 0;
    int currentPos = 0;
    queue* current = h->next;

    while (current) {
        currentPos++;
        if (current->inf < minVal) {
            minVal = current->inf;
            minPos = currentPos;
        }
        current = current->next;
    }

    return minPos;
}

// Функция циклического сдвига
void sdvig(queue*& h, queue*& t) {
    if (!h || !h->next) return; // Если очередь пуста или содержит 1 элемент

    int shiftPos = find(h);
    if (shiftPos <= 0) return; // Если минимальный уже первый

    // Создаем временную очередь
    queue* tempH = NULL, * tempT = NULL;

    // Перекладываем элементы до минимального в конец
    for (int i = 0; i < shiftPos; i++) {
        push(tempH, tempT, pop(h, t));
    }

    // Теперь h указывает на первый минимальный элемент
    // Добавляем элементы из временной очереди в конец основной
    while (tempH) {
        push(h, t, pop(tempH, tempT));
    }
}

// Функция печати очереди
void print(queue* h) {
    while (h) {
        cout << h->inf << " ";
        h = h->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    queue* head = NULL, * tail = NULL;
    int n, x;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, tail, x);
    }

    cout << "Исходная очередь: ";
    print(head);

    sdvig(head, tail);

    cout << "Очередь после сдвига: ";
    print(head);

    // Очистка памяти
    while (head) {
        pop(head, tail);
    }

    return 0;
}
//Создать стек, содержащий буквы латинского алфавита. В новый стек после первой гласной буквы (первой, введенной из файла или с клавиатуры) вставить вопросительный знак.
struct stack {
    char inf;  // теперь храним символы вместо чисел
    stack* next;
};

// Функция для проверки, является ли символ гласной
bool isVowel(char c) {
    c = tolower(c); // приводим к нижнему регистру
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

void push(stack*& h, char x) { // вставка
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

char pop(stack*& h) { // удаление
    if (!h) return ; 
    char i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack*& h) {
    stack* head1 = NULL;
    while (h)
        push(head1, pop(h));
    h = head1;
}

stack* process(stack*& h) {
    stack* res = NULL;
    stack* temp = NULL;
    bool vowelFound = false;

    // Сначала переворачиваем исходный стек
    reverse(h);

    // Обрабатываем элементы
    while (h) {
        char x = pop(h);
        push(res, x);

        // Если нашли первую гласную и еще не вставляли '?'
        if (!vowelFound && isVowel(x)) {
            push(res, '?');
            vowelFound = true;
        }
    }

    // Переворачиваем результат обратно
    reverse(res);
    return res;
}

int main() {
    int n;
    cout << " n= ";
    cin >> n;
    cin.ignore(); // очищаем буфер ввода

    stack* head = NULL;
    char x;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, x);
    }

    stack* res = process(head);

    cout << endl;
    while (res)
        cout << pop(res) << " ";
    cout << endl;

    return 0;
}
