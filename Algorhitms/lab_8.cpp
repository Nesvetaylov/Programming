#include <iostream>
using namespace std;

bool isTree(int** Matrix, int n)//Matrix - матрица смежности графа, n - кол-во вершин
{
    int num_of_edges = 0;//кол-во рёбер
    for (int i=0;i<n;i++)//определяем кол-во рёбер в графк
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
    bool* visited = new bool[n];//посещенные вершины
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;//изначально не посещена
    }
    int* stack = new int[n];//стек для обхода графа в глубину
    int top = -1;//стек пуст, top - верхний элемент стека
    stack[++top] = 0;//начальная вершина 0

    while (top >= 0)//пока стек не пуст
    {
        int node = stack[top--];// node - вершина
        visited[node] = true;// node - посещенныя
        for (int neighbor = 0; neighbor < n; neighbor++)//проверка соседей
        {
            if (Matrix[node][neighbor] == 1)
            {
                if (visited[neighbor])//если сосед посещён=Юuhfa yt lthtdj
                {
                    delete[]visited;
                    delete[]stack;
                    return false;
                }
                stack[++top] = neighbor;//не посещён=>добавляем в стек
            }
        }
    }
    delete[]visited;
    delete[]stack;
    return true;//если граф-дерево
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите количество вершин графа: ";
    cin >> n;
    int** Matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        Matrix[i] = new int[n];
    }
    cout << "Введите матрицу смежности графа (размер: " << n << "x" << "):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> Matrix[i][j];
        }
    if (isTree(Matrix, n))
    {
        cout << "Граф является деревом" << endl;
    }
    else
    {
        cout << "Граф не является деревом" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] Matrix[i];
    }
    delete[] Matrix;
    return 0;

}


