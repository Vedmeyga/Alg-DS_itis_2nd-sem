#include <iostream>

using namespace std;

// Ôóíêöèÿ äëÿ çàìåíû äâóõ ýëåìåíòîâ
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
            i++;    // Óâåëè÷èâàåì èíäåêñ ìåíüøåãî ýëåìåíòà
            swap(&array[i], &array[j]); //Âûïîëíÿåì çàìåíó ýëåìåíòîâ
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

/* Îñíîâíîé ìåòîä, êîòîðûé íàñëåäóåò Quicksort
  array[] - Ìàññèâ, êîòîðûé íóæíî îòñîðòèðîâàòü,
  low - Èíäåêñ íà÷àëà,
  high - Èíäåêñ êîíöà */
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Èíäåêñ ôóíêöèè ðàçäåëåíèÿ, arr[p]
        int p = partition(array, low, high);
        /* Ðåêóðñèâíàÿ ñîðòèðîâêà ýëåìåíòîâ äî ðàçäåëåíèÿ
         è ýëåìåíòîâ ïîñëå íåãî */
        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }
}

// Âûâîä ìàññèâà
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int n; //ðàçìåð ìàññèâà
    cout << "Enter array size:" << endl;
    cin >> n; //ââîäèì ðàçìåð ìàññèâà
    int arr[n];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //ââîäèì ýëåìåíò ìàññèâà
    }
    cout << "Sorted array:" << endl;
    quickSort(arr, 0, n - 1); //ïîëó÷àåì îòñîðòèðîâàííûé ìàññèâ
    printArray(arr, n);
    return 0;
}
