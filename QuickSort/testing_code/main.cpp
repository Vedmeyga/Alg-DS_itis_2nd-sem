#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdio>

using namespace std;

// Функция для замены двух элементов
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Данная функция принимает последний элемент в качестве pivot (опорного), помещает
элемент pivot в правильное положение в отсортированном
массиве и помещает все меньшие (меньше, чем pivot)
слева от него и все большие элементы справа */
int partition(int array[], int low, int high) {
    int pivot = array[high];    // Опорный элемент
    int i = (low - 1);  // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        /* Если текущий элемент меньше или
        равен опорному */
        if (array[j] <= pivot) {
            i++;    // Увеличиваем индекс меньшего элемента
            swap(&array[i], &array[j]); // Выполняем замену элементов
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

/* Основной метод, который наследует Quicksort
  array[] - Массив, который нужно отсортировать,
  low - Индекс начала,
  high - Индекс конца */
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Индекс функции разделения, arr[p]
        int p = partition(array, low, high);
        /* Рекурсивная сортировка элементов до разделения
         и элементов после него */
        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }
}

// Вывод массива
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    for (int k = 0; k <= 100; k++) {
        ifstream fin("C:/Users/Ìàòâåé/Desktop/QuickSort/tests" + to_string(k + 1) + ".txt");
        int n;
        fin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            fin >> a[i];
        }
        fin.close();
        //printArray(a, n);
        cout << endl;
        auto begin = std::chrono::steady_clock::now();
        quickSort(a, 0, n - 1);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        cout << "for array witn " << n << " elements" << endl;
        cout << "time taken by qsort: " << elapsed_ms.count() << " microseconds";
        cout << endl;
        //printArray(a, n);
    }
    return 0;
}
