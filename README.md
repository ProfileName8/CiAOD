#include <iostream>

using namespace std;
//Пузырьком
void SortP(int m[], int sz)
{
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (m[j] > m[j + 1])
			{
				int l = m[j];
				m[j] = m[j + 1];
				m[j + 1] = l;
			}
		}
}

//Простой выбор
void SortS(int m[], int sz)
{
	int k = sz;
	int f = 0;
	while (k > 0) {
		int j = 0;
		int max = 0;
		for (int i = 1; i <= k; i++)
		{
			if (m[i] > max)
			{
				max = m[i];
				j = i;
			}
		}

		max = m[j];
		m[j] = m[k];
		m[k] = max;
		k = k - 1;
	}
}

//Многофазная (Не работает)
void PhasS(int m[], int sz)
{
	int s = 0;
	while (s<=sizeof(m))
	{
		s += 4;
		for (int i = s; i < s+s+1; i++)
			for (int j = s; j < s+s - i - 1; j++)
			{
				if (m[j] > m[j + 1])
				{
					int l = m[j];
					m[j] = m[j + 1];
					m[j + 1] = l;
				}
			}
		for (int i = 0 ; i < sz; i++)
			cout << m[i] << " ";
		cout << endl << endl;
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
	cout << endl<<endl;
	SortS(m, f);
	for (int i = 0; i < f; i++)
		cout << m[i] << " ";
}
