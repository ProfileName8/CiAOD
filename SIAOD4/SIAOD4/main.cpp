#include <iostream>

using namespace std;

void quickSort(int* arr, int size) {
    int i = 0;
    int j = size - 1;
    int mid = arr[size / 2];

    do  {
        while (arr[i] < mid) {
            i++;
        }
        while (arr[j] > mid) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        quickSort(arr, j + 1);
    }
    if (i < size) {
        quickSort(&arr[i], size - i);
    }
}

void reverseSort(int* arr, int size) {
    quickSort(arr, size);
    int middle = size / 2;
    for (int i = 0; i < middle; i++) {
        swap(arr[i], arr[size - i - 1]);

    }
}

void search(int* arr, int size) {
    int countIterations = 0;
    int flag = 0;
    int symbol;
    cin >> symbol;
    for (int i = 0; i < size; i++) {
        countIterations++;
        if (arr[i] == symbol) {
            countIterations++;
            flag = 1;
            cout << i << endl;
            cout
                << countIterations;
            break;
        }
    }
    if (flag == 0) {
        search(arr, size);
    }
}

int main() {
    setlocale(0, "Rus");
    int size;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    string choice;
    cin >> choice;

    if (choice == "1") {
        quickSort(arr, size);
    }
    if (choice == "2") {
        reverseSort(arr, size);
    }
    search(arr, size);
}