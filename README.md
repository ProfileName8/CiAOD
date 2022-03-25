#include <iostream>

using namespace std;
//Выбор 1.3 2.3
void SortS(int m[], int sz)
{
	for (int i = 0; i < sz - 1; i++) {
		int min_i = i;
		for (int j = i + 1; j < sz; j++) {
			if (m[j] < m[min_i]) {
				min_i = j;
			}
		}
		int temp = m[i];
		m[i] = m[min_i];
		m[min_i] = temp;
	}
}

//Многофазный простой выбор 3.3
void SortSM(int m[], int sz)
{
	int s_f = 5;
	int min_f = 0;
	int max_f = s_f;
	int l1 = sz / s_f;
	for (int k = 0; k < l1; k++) {
		for (int i = min_f; i < max_f - 1; i++) {
			int min_i = i;
			for (int j = i; j < max_f; j++) {
				if (m[j] < m[min_i]) {
					min_i = j;
				}
			}
			int temp = m[i];
			m[i] = m[min_i];
			m[min_i] = temp;
		}
		min_f = min_f + s_f;
		max_f = max_f + s_f;
	}
	for (int i = 0; i < sz - 1; i++) {
		int min_i = i;
		for (int j = i + 1; j < sz; j++) {
			if (m[j] < m[min_i]) {
				min_i = j;
			}
		}
		int temp = m[i];
		m[i] = m[min_i];
		m[min_i] = temp;
	}
};

int main()
{
	const int f = 100;
	int m[f];
	for (int i = 0; i < f; i++)
	{
		m[i] = rand();
		cout << m[i] << " ";
	}
	cout << endl<< endl;
	SortSM(m, f);
	for (int i = 0; i < f; i++)
		cout << m[i] << " ";
}
