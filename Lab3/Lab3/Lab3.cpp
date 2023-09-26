#include <iostream>
#include <cassert>

using namespace std;


int opCount = 0;//считать операции
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        opCount++;
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}
void Print_Massiv(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
bool isSorted(int a[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (a[i] < a[i - 1])
            return 0;
    }
    return 1;
}


void TestQuickSort()
{
    int a1[] = { 6,3,8,9,7, -2, 11, 15, 0 };
    int n1 = sizeof(a1) / sizeof(a1[0]);
    opCount = 0;
    QuickSort(a1, 0, n1 - 1);
    assert(isSorted(a1, n1));
    cout << "Кол-во операций: " << opCount << endl;
    int a2[] = { 1,2,3,4,5 };
    int n2 = sizeof(a2) / sizeof(a2[0]);
    opCount = 0;
    QuickSort(a2, 0, n2 - 1);
    assert(isSorted(a2, n2));
    cout << "Кол-во операций: " << opCount << endl;
    int a3[] = { 5,4,3,2,1 };
    int n3 = sizeof(a3) / sizeof(a3[0]);
    opCount = 0;
    QuickSort(a3, 0, n3 - 1);
    assert(isSorted(a3, n3));
    cout << "Кол-во операций: " << opCount << endl;
    int a4[] = {5, 4, 6, 9, 3};
    int n4 = sizeof(a4) / sizeof(a4[0]);
    opCount = 0;
    QuickSort(a4, 0, n4 - 1);
    assert(isSorted(a4, n4));
    cout << "Кол-во операций: " << opCount << endl;
    cout << "Тесты пройдены!" << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    TestQuickSort();
    return 0;
}

