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

//Многофазный простой выбор 3.3(Не работает)
void SortSM(int m[], int sz)
{
	int s_f = 5;
	int min_f = 0;
	int max_f = s_f;
	int l1 = sz/s_f;
	for (int i = 0;i<l1;i++)
		for (int k = min_f; k < max_f; k++)
		{
			int min_k = k;
			for (int j = k + 1; j < max_f; j++) {
				if (m[j] < m[min_k]) {
					min_k = j;
				}
			}
			int temp = m[k];
			m[k] = m[min_k];
			m[min_k] = temp;
			min_f += s_f;
			max_f += s_f;
		}
		
}

int main()
{
	const int f = 10;
	int m[f];
	for (int i = 0; i < f; i++)
	{
		m[i] = rand();
		cout << m[i] << " ";
	}
	cout << endl;
	SortS(m, f);
	for (int i = 0; i < sizeof(m); i++)
		cout << m[i] << " ";
}
