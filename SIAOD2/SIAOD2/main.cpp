#include <iostream>
#include <ctime>

using namespace std;

int QuickSort(int* array, int size) {
    int counter = 0;
    int i = 0;
    int j = size - 1;
    int mid = array[size / 2];

    do {
        while (array[i] < mid) {
            counter += 1;
            i++;
        }
        while (array[j] > mid) {
            counter += 1;
            j--;
        }
        if (i <= j) {
            counter += 2;
            swap(array[i], array[j]);
            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        counter += 1;
        QuickSort(array, j + 1);
    }
    if (i < size) {
        counter += 1;
        QuickSort(&array[i], size - i);
    }
    return counter;
}

void timer(int* array, int size) {
    unsigned int start_time = clock();
    int counter = QuickSort(array, size);
    unsigned int end_time = clock();
    unsigned int search_time = start_time - end_time;
    cout << "Time: " << search_time << endl;
    cout << "Counter: " << counter << endl;
}


void main() {
    int size;
    cin >> size;
    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    timer(array, size);
    if (size < 1000000) {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
    }
}