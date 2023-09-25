/*
1) int* ptr = (int*)malloc(sizeof(int)) - int* ptr = new int
2) int* ptrArr = (int*)malloc(sizeof(int) * N) - int* ptrArr = new int[N]
3) free(ptr) - delete ptr
4) free(ptrArr) - delete[] ptrArr
В С++ необходимо ли освобождать динамическую память? Да, оператором delete.
Можно ли освободить одну и ту же выделенную память дважды? Нет, это приводит к недокументированному поведению.
А можно ли освободить невыделенную память? Нет.
Б) Треугольник Фибоначчи.У некоторых это задание было на программировании по С.Теперь
требуется адаптировать эту программу(или написать заново) на С++ с определенными требованиями(NB) :
-именно пользователь должен решать(посредством ввода в командную строку) сколько строк у пирамиды должно быть;
-перемещаться по массиву(-ам) необходимо только через указательную арифметику – Pointer Arithmetic[arr[i][j] - > *(*(arr + i) + j)];
-использовать только динамическое выделение памяти
*/

#include <iostream>
int** allocateMemory(int n) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[i + 1];
    }
    return arr;
}

// Функция для освобождения памяти, выделенной под треугольник Фибоначчи
void deallocateMemory(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

// Функция для заполнения треугольника Фибоначчи
void fillFibonacciTriangle(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i < 2 || j == 0 || j == i) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
		
        }
    }
}

// Функция для вывода треугольника Фибоначчи
void printFibonacciTriangle(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << " Введите количество строк: ";
    std::cin >> n;

    int** arr = allocateMemory(n);
    fillFibonacciTriangle(arr, n);
    printFibonacciTriangle(arr, n);
    deallocateMemory(arr, n);

    return 0;
}
