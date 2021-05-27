#include <iostream>

using namespace std;

// ������� ��� ������ ���� ���������
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* ������ ������� ��������� ��������� ������� � �������� pivot (��������), ��������
������� pivot � ���������� ��������� � ���������������
������� � �������� ��� ������� (������, ��� pivot)
����� �� ���� � ��� ������� �������� ������ */
int partition(int array[], int low, int high) {
    int pivot = array[high];    // ������� �������
    int i = (low - 1);  // ������ �������� ��������

    for (int j = low; j <= high - 1; j++) {
        /* ���� ������� ������� ������ ���
        ����� �������� */
        if (array[j] <= pivot) {
            i++;    // ����������� ������ �������� ��������
            swap(&array[i], &array[j]); //��������� ������ ���������
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

/* �������� �����, ������� ��������� Quicksort
  array[] - ������, ������� ����� �������������,
  low - ������ ������,
  high - ������ ����� */
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // ������ ������� ����������, arr[p]
        int p = partition(array, low, high);
        /* ����������� ���������� ��������� �� ����������
         � ��������� ����� ���� */
        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }
}

// ����� �������
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int n; //������ �������
    cout << "Enter array size:" << endl;
    cin >> n; //������ ������ �������
    int arr[n];
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //������ ������� �������
    }
    cout << "Sorted array:" << endl;
    quickSort(arr, 0, n - 1); //�������� ��������������� ������
    printArray(arr, n);
    return 0;
}
