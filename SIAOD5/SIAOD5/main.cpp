#include <iostream>

using namespace std;

void quickSort(int* arr, int size) {
	int i = 0;
	int j = size - 1;
	int mid = arr[size / 2];

	do {
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

void binarySearch(int* arr, int size) {
	int key;
	cout << "Enter the key to search: ";
	cin >> key;

	int counter = 0;
	int left = 0;
	int right = size - 1;
	int mid;
	bool flag = false;
	while (left < right) {
		counter++;
		mid = (left + right) / 2;

		counter++;
		if (arr[mid] == key) {
			flag = true;
			break;
		}
		counter++;
		if (key > arr[mid]) {
			left = mid + 1;
		}
		counter++;
		if (key < arr[mid]) {
			right = mid;
		}
	}
	if (flag == true) {
		cout << "Index of key in array: " << mid << endl;
		cout << "Iterations: " << counter;
	}
	else {
		cout << "There is no such key in this array";
	}
}

void binaryReverseSearch(int* arr, int size) {
	int key;
	cout << "Enter the key to search: ";
	cin >> key;

	int counter = 0;
	int left = 0;
	int right = size - 1;
	int mid;
	bool flag = false;
	while (left < right) {
		counter++;
		mid = (left + right) / 2;

		counter++;
		if (arr[mid] == key) {
			flag = true;
			break;
		}
		counter++;
		if (key > arr[mid]) {
			right = mid;
		}
		counter++;
		if (key < arr[mid]) {
			left = mid + 1;
		}
	}
	if (flag == true) {
		cout << "Index of key in array: " << mid << endl;
		cout << "Iterations: " << counter;
	}
	else {
		cout << "There is no such key in this array";
	}
}

int main() {
	int choice;
	int size;
	cout << "Enter size of array: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}

	cout << endl;
jump:
	cout << "1 - Search with ascending sort;" << endl;
	cout << "2 - Search with descending sort;" << endl;
	cout << "Enter the number of choice to search: ";
	cin >> choice;
	switch (choice) {
	case 1: {
		quickSort(arr, size);
		binarySearch(arr, size);
		break;
	}
	case 2: {
		reverseSort(arr, size);
		binaryReverseSearch(arr, size);
		break;
	}
	default:
		goto jump;
	}
}