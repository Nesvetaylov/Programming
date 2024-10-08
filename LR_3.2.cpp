// (3.2.1) ЗАДАНИЕ
/*
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления определителя матрицы 3x3
double determinant(double a[3][3]) {
    return a[0][0] * (a[1][1] * a[2][2] - a[2][1] * a[1][2]) -
        a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) +
        a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
}

// Функция для решения системы линейных уравнений методом Крамера
void solveSystem(double a[3][3], double b[3], double x[3]) {
    double detA = determinant(a);

    if (fabs(detA) < 1e-10) {
        cout << "Система имеет бесконечно много решений или не имеет решений." << endl;
        return;
    }

    double temp[3][3];

    // Заменяем первый столбец матрицы A на вектор b
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        temp[i][0] = b[i];
    }
    x[0] = determinant(temp) / detA;

    // Заменяем второй столбец матрицы A на вектор b
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        temp[i][1] = b[i];
    }
    x[1] = determinant(temp) / detA;

    // Заменяем третий столбец матрицы A на вектор b
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        temp[i][2] = b[i];
    }
    x[2] = determinant(temp) / detA;
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Задаем матрицу системы и вектор свободных членов
    double a[3][3] = {
        {1.00, 0.80, 0.64},
        {1.00, 0.90, 0.81},
        {1.00, 1.10, 1.21}
    };
    double b[3] = { erf(0.80), erf(0.90), erf(1.10) };

    // Создаем вектор для хранения решения
    double x[3];

    // Решаем систему линейных уравнений
    solveSystem(a, b, x);

    // Выводим решение
    cout << fixed << setprecision(6);
    cout << "Решение системы:" << endl;
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;
    cout << "x3 = " << x[2] << endl;

    // Вычисляем сумму x1 + x2 + x3
    double sum = x[0] + x[1] + x[2];
    cout << "x1 + x2 + x3 = " << sum << endl;

    // Выводим значение erf(1.0)
    cout << "erf(1.0) = " << erf(1.0) << endl;

    return 0;
}
*/

// (3.2.2) ЗАДАНИЕ
/*
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления определителя матрицы 3x3
double determinant(double a[3][3]) {
    return a[0][0] * (a[1][1] * a[2][2] - a[2][1] * a[1][2]) -
        a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) +
        a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
}

// Функция для решения системы линейных уравнений методом Гаусса
void solveSystem(double a[3][3], double b[3], double x[3]) {
    int i, j, k;
    double factor;

    // Прямой ход метода Гаусса
    for (k = 0; k < 3; k++) {
        // Поиск главного элемента
        for (i = k + 1; i < 3; i++) {
            if (fabs(a[i][k]) > fabs(a[k][k])) {
                // Меняем строки местами
                for (j = k; j < 3; j++) {
                    swap(a[i][j], a[k][j]);
                }
                swap(b[i], b[k]);
            }
        }

        // Обнуляем элементы ниже главной диагонали
        for (i = k + 1; i < 3; i++) {
            factor = a[i][k] / a[k][k];
            for (j = k; j < 3; j++) {
                a[i][j] -= factor * a[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Обратный ход метода Гаусса
    for (k = 2; k >= 0; k--) {
        // Вычисляем неизвестные
        x[k] = b[k];
        for (j = k + 1; j < 3; j++) {
            x[k] -= a[k][j] * x[j];
        }
        x[k] /= a[k][k];
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Задаем матрицу системы и вектор свободных членов
    double a[3][3] = {
        {0.1, 0.2, 0.3},
        {0.4, 0.5, 0.6},
        {0.7, 0.8, 0.9}
    };
    double b[3] = { 0.1, 0.3, 0.5 };

    // Создаем вектор для хранения решения
    double x[3];

    // Вычисляем определитель матрицы
    double detA = determinant(a);

    if (fabs(detA) < 1e-10) {
        // Определитель равен нулю, значит система имеет бесконечно много решений или не имеет решений
        cout << "Определитель матрицы равен нулю." << endl;

        // Приводим матрицу к ступенчатому виду
        solveSystem(a, b, x);

        // Проверяем, есть ли противоречия в системе
        if ((fabs(a[2][2]) < 1e-10 && fabs(b[2]) > 1e-10) ||
            (fabs(a[1][1]) < 1e-10 && fabs(b[1]) > 1e-10)) {
            cout << "Система не имеет решений." << endl;
        }
        else {
            cout << "Система имеет бесконечно много решений." << endl;

            // Выражаем решение через свободные переменные
            if (fabs(a[2][2]) < 1e-10) {
                // x3 - свободная переменная
                cout << "x1 = " << x[0] << " - " << a[0][2] / a[0][0] << " * x3" << endl;
                cout << "x2 = " << x[1] << " - " << a[1][2] / a[1][1] << " * x3" << endl;
                cout << "x3 - свободная переменная" << endl;
            }
            else if (fabs(a[1][1]) < 1e-10) {
                // x2 - свободная переменная
                cout << "x1 = " << x[0] << " - " << a[0][1] / a[0][0] << " * x2" << endl;
                cout << "x2 - свободная переменная" << endl;
                cout << "x3 = " << x[2] << endl;
            }
        }
    }
    else {
        // Определитель не равен нулю, значит система имеет единственное решение
        solveSystem(a, b, x);
        cout << "Решение системы:" << endl;
        cout << "x1 = " << x[0] << endl;
        cout << "x2 = " << x[1] << endl;
        cout << "x3 = " << x[2] << endl;
    }

    return 0;
}
*/

//(3.1) ЗАДАНИЕ

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double** matrix, int n, int i) {
    int max = 0;
    max = fabs(matrix[i][0]);
    for (int j = 0; j < n; j++) {
        if (max < fabs(matrix[i][j])) {
            max = fabs(matrix[i][j]);
        }
    }
    return max;
}

int main() {
    int i, j, n, m;
    cout << "n: ";
    cin >> n;
    cout << "m: ";
    cin >> m;
    m += 1;
    double** matrix = new double* [n];
    double** matrixsave = new double* [n];
    for (i = 0; i < n; i++) {
        matrix[i] = new double[m];
        matrixsave[i] = new double[m];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << "[" << i + 1 << "][" << j + 1 << "]= ";
            cin >> matrix[i][j];
            matrixsave[i][j] = matrix[i][j];
        }
    }

    double tmp;
    int k;
    double* xx = new double[m];

    for (i = 0; i < n; i++) {
        int max_row = i;
        for (int r = i + 1; r < n; r++) {
            if (fabs(matrix[r][i]) > fabs(matrix[max_row][i])) {
                max_row = r;
            }
        }

        if (max_row != i) {
            swap(matrix[i], matrix[max_row]);
            swap(matrixsave[i], matrixsave[max_row]);
        }

        tmp = matrix[i][i];
        for (j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++) {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }
    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--) {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
    }
    cout << endl;
    for (i = 0; i < n; i++)
        cout << "x[" << i << "]=" << xx[i] << endl;
    cout << endl;
    for (i = 0; i < n; i++) {
        double sum = 0;
        for (j = 0; j < m - 1; j++) {
            sum += matrixsave[i][j] * xx[j];
        }
        cout << fixed << setprecision(20) << "nevyazka =" << matrixsave[i][m - 1] - sum << " Sum=" << sum << endl;
    }
}


