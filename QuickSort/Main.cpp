#include <iostream>

using namespace std;

// Функция для замены двух элементов
void swap(int* a, int* b) {
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
            swap(&array[i], &array[j]); //Выполняем замену элементов
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
    int n; //размер массива
    cout << "Enter array size:" << endl;
    cin >> n; //вводим размер массива
    int arr[n];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //вводим элемент массива
    }
    cout << "Sorted array:" << endl;
    quickSort(arr, 0, n - 1); //получаем отсортированный массив
    printArray(arr, n);
    return 0;
}
