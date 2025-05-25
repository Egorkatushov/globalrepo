#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;//левый элемент 
	int r = 2 * i + 2;//правый элемент 

	if (l<n && arr[l]>arr[largest])// левый больший корня
		largest = l;
	if (r<n && arr[r]>arr[largest])// правый больше корня
		largest = r;
	if (largest != i) {//если большой элемент не корень 
		swap(arr[i], arr[largest]);//меняем местами

		heapify(arr, n, largest);//рекурсивно преобразуем
	}
}

void heapsort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)//строим кучу
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--) {//извлекаем элементы из кучи
		swap(arr[0], arr[i]);//ставим корень в конец 

		heapify(arr, i, 0);//уменьшвем кучу
	}
}

void sortj(int m[][100], int rows, int cols) {
	for (int c = 0; c < cols; c++) {
		int* j = new int[rows];
		for (int r = 0; r < rows; r++) {
			j[r] = m[r][c];
		}

		heapsort(j, rows);
		for (int r = 0; r < rows; r++) {
			m[r][c] = j[r];
		}
		delete[] j;
	}
}
void read(const string& input, int m[][100], int& rows, int& cols) {
	ifstream file(input);
	if (!file.is_open()) {
		cout << "EOF in input" << endl;
		return;
	}
	file >> rows >> cols;//читаем столбцы и строки
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			file >> m[r][c];
		}
	}
	file.close();
}
void write(const string& output, int m[][100], int& rows, int& cols) {
	ofstream file(output);
	if (!file.is_open()) {
		cout << "EOF in output" << endl;
		return;
	}
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			file << m[r][c] << " ";
		}
		file << endl;
	}
	file.close();
}
int main() {
	int m[100][100];
	int rows, cols;
	read("input.txt", m, rows, cols);

	sortj(m, rows, cols);
	write("output.txt", m, rows, cols);
	cout << endl;
	return 0;
}
 //диагонали
void sortDiagonals(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;

    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int sum = 0; sum <= rows + cols - 2; ++sum) {
        vector<int> diagonal;
        for (int i = 0; i < rows; ++i) {
            int j = sum - i;
            if (j >= 0 && j < cols) {
                diagonal.push_back(matrix[i][j]);
            }
        }

        // Сортировка пузырьком
        for (int i = 0; i < diagonal.size(); ++i) {
            for (int j = 0; j < diagonal.size() - i - 1; ++j) {
                if (diagonal[j] > diagonal[j + 1]) {
                    swap(diagonal[j], diagonal[j + 1]);
                }
            }
        }

        // Возвращаем элементы на диагональ
        int index = 0;
        for (int i = 0; i < rows; ++i) {
            int j = sum - i;
            if (j >= 0 && j < cols) {
                matrix[i][j] = diagonal[index++];
            }
        }
    }
}

vector<vector<int>> read(const string& input){
    ifstream file(input);
    vector<vector<int>> matrix;

    if (!file.is_open()) {
        cerr << "EOF" << endl;
        return matrix;
    }

    int rows, cols;
    file >> rows >> cols;

    matrix.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(file >> matrix[i][j])) {
                cerr << "eof" << endl;
                return vector<vector<int>>();
            }
        }
    }

    file.close();
    return matrix;
}

void write(const string&input,   vector<vector<int>>& matrix) {
    ofstream file(input);

    if (!file.is_open()) {
        cout << "EOF read" << endl;
        return;
    }

    for (const auto& row : matrix) {
        for (int val : row) {
            file << val << " ";
        }
        file << endl;
    }

    file.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    vector<vector<int>> matrix = read(inputFile);
    if (matrix.empty()) {
        cout << endl;
        return 1;
    }

    sortDiagonals(matrix);
    write(outputFile, matrix);

    cout << outputFile << endl;
    return 0;
}

 //Функция для пузырьковой сортировки
void shellSortAscending(vector<vector<int>>& matrix, int col, int rows) {
	for (int d = rows / 2; d > 0; d /= 2) {
		for (int i = d; i < rows; ++i) {
			int temp = matrix[i][col];
			int j;
			for (j = i; j >= d && matrix[j - d][col] > temp; j -= d) {
				matrix[j][col] = matrix[j - d][col];
			}
			matrix[j][col] = temp;
		}
	}
}

 //Сортировка Шелла для столбца (по убыванию)
void shellSortDescending(vector<vector<int>>& matrix, int col, int rows) {
	for (int d = rows / 2; d > 0; d /= 2) {
		for (int i = d; i < rows; ++i) {
			int temp = matrix[i][col];
			int j;
			for (j = i; j >= d && matrix[j - d][col] < temp; j -= d) {
				matrix[j][col] = matrix[j - d][col];
			}
			matrix[j][col] = temp;
		}
	}
}

 //Основная функция сортировки столбцов
void sortMatrixColumns(vector<vector<int>>& matrix) {
	if (matrix.empty()) return;

	int rows = matrix.size();
	int cols = matrix[0].size();

	for (int col = 0; col < cols; ++col) {
		if (col % 2 == 0) {  // Нечетные столбцы (индексация с 0) → по возрастанию
			shellSortAscending(matrix, col, rows);
		}
		else {             // Четные столбцы → по убыванию
			shellSortDescending(matrix, col, rows);
		}
	}
}
vector<vector<int>> read(const string& input){
    ifstream file(input);
    vector<vector<int>> matrix;

    if (!file.is_open()) {
        cerr << "EOF" << endl;
        return matrix;
    }

    int rows, cols;
    file >> rows >> cols;

    matrix.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(file >> matrix[i][j])) {
                cerr << "eof" << endl;
                return vector<vector<int>>();
            }
        }
    }

    file.close();
    return matrix;
}

void write(const string&input,   vector<vector<int>>& matrix) {
    ofstream file(input);

    if (!file.is_open()) {
        cout << "EOF read" << endl;
        return;
    }

    for (const auto& row : matrix) {
        for (int val : row) {
            file << val << " ";
        }
        file << endl;
    }

    file.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    vector<vector<int>> matrix = read(inputFile);
    if (matrix.empty()) {
        cout << endl;
        return 1;
    }

    sortMatrixColumns(matrix);
    write(outputFile, matrix);

    cout << outputFile << endl;
    return 0;
}

