#include <iostream>
using namespace std;

bool isTree(int** Matrix, int n)//Matrix - ������� ��������� �����, n - ���-�� ������
{
    int num_of_edges = 0;//���-�� ����
    for (int i=0;i<n;i++)//���������� ���-�� ���� � �����
        for (int j = i + 1; j < n; j++)
        {
            if (Matrix[i][j] == 1)
            {
                num_of_edges++;
            }
        }
    if (num_of_edges != n - 1)
    {
        return 0;
    }
    bool* visited = new bool[n];//���������� �������
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;//���������� �� ��������
    }
    int* stack = new int[n];//���� ��� ������ ����� � �������
    int top = -1;//���� ����, top - ������� ������� �����
    stack[++top] = 0;//��������� ������� 0

    while (top >= 0)//���� ���� �� ����
    {
        int node = stack[top--];// node - �������
        visited[node] = true;// node - ����������
        for (int neighbor = 0; neighbor < n; neighbor++)//�������� �������
        {
            if (Matrix[node][neighbor] == 1)
            {
                if (visited[neighbor])//���� ����� �������=�uhfa yt lthtdj
                {
                    delete[]visited;
                    delete[]stack;
                    return false;
                }
                stack[++top] = neighbor;//�� �������=>��������� � ����
            }
        }
    }
    delete[]visited;
    delete[]stack;
    return true;//���� ����-������
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "������� ���������� ������ �����: ";
    cin >> n;
    int** Matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        Matrix[i] = new int[n];
    }
    cout << "������� ������� ��������� ����� (������: " << n << "x" << "):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> Matrix[i][j];
        }
    if (isTree(Matrix, n))
    {
        cout << "���� �������� �������" << endl;
    }
    else
    {
        cout << "���� �� �������� �������" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] Matrix[i];
    }
    delete[] Matrix;
    return 0;

}


