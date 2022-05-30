#include <iostream>
#include <ctime>
using namespace std;
void sorter(int& n1, int& n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main()
{
    setlocale(0, "");
    int n;
    cin >> n;
    clock_t start, end;
    start = clock();
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = 1 + rand();
        cout << A[i] << " ";
    }
    cout << endl;
    int offset = 0;
    bool b;
    do
    {
        b = false;
        for (int i = 0; i < n; i++)
        {
            if (i * 2 + 2 + offset < n)
            {
                if ((A[i + offset] > A[i * 2 + 1 + offset]) || (A[i + offset] > A[i * 2 + 2 + offset]))
                {
                    if (A[i * 2 + 1 + offset] < A[i * 2 + 2 + offset])
                    {
                        sorter(A[i + offset], A[i * 2 + 1 + offset]);
                        b = true;
                    }
                    else if (A[i * 2 + 2 + offset] < A[i * 2 + 1 + offset])
                    {
                        sorter(A[i + offset], A[i * 2 + 2 + offset]);
                        b = true;
                    }
                }
                if (A[i * 2 + 2 + offset] < A[i * 2 + 1 + offset])
                {
                    sorter(A[i * 2 + 1 + offset], A[i * 2 + 2 + offset]);
                    b = true;
                }
            }
            else if (i * 2 + 1 + offset < n)
            {
                if (A[i + offset] > A[i * 2 + 1 + offset])
                {
                    sorter(A[i + offset], A[i * 2 + 1 + offset]);
                    b = true;
                }
            }
        }
        if (!b) {
            ++offset;
        }
    } while (offset + 2 < n);
    cout << endl << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
    end = clock();
    double seconds = ((double)end - start) / ((double)CLOCKS_PER_SEC);
    cout << endl << "Time: " << seconds << " sec";
    return 0;
}