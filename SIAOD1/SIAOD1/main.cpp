#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctime>

using namespace std;

static unsigned long* selectionSort(int* arr, int length, bool swapFlag = false) {
	unsigned int start_time = clock(); 

	unsigned long counterSwap = 0;
	unsigned long counterIterations = 0;

	for (int i = 0; i < length - 1; ++i) {
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
		int minIndex = i;
		for (int j = i + 1; j < length; ++j) {
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
		counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
	}
	unsigned long* info = new unsigned long[3];
	info[0] = counterSwap;
	info[1] = counterIterations;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	printf("TIIIIMEEEEE  %d\n", search_time);
	printf("SWAP + ITER  %d\n", info[0] + info[1]);
	return info;
}


int main() {
	int n = 1000;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	selectionSort(arr, n, true);
	int count = 0;
	for (int j = 0; j < n; j++) {
		cout << arr[j];
		count++;
	}
	cout << count;
	return 0;
}