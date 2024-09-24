#include <iostream> 
#include <cmath> 
#define _USE_MATH_DEFINES 
#include <math.h> 
#include <vector>
#include <iomanip> 
#include <sstream>
#include <algorithm>
#include <chrono>

using namespace std;


   // (1) ЗАДАНИЕ
/*
* const double PI = 3.14159265358979323846;

double factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

double erf(double x) {
    double sum = 0;
    int num_terms = 0;
    for (int n = 0; n < 1000; n++) {
        double term = pow(-1, n) * pow(x, 2 * n + 1) / (factorial(n) * (2 * n + 1));
        sum += term;
        num_terms++;
        if (abs(term) < 1e-6) {
            break;
        }
    }
    return 2 * sum / sqrt(PI);
}

int main() {
    double x_values[] = { 0.5, 1.0, 5.0, 10.0 };

    for (int i = 0; i < 4; i++) {
        double x = x_values[i];
        double result = erf(x);
        int num_terms = 0; 
        for (int n = 0; n < 1000; n++) {
            double term = pow(-1, n) * pow(x, 2 * n + 1) / (factorial(n) * (2 * n + 1));
            if (abs(term) < 1e-6) {
                break;
            }
            num_terms++;
        }
        cout << "erf(" << x << ") = " << result << ", num_terms = " << num_terms << endl;
    }

    return 0;
}
*/




// (2) ЗАДАНИЕ

/*
pair<double, int> phi(double x) {
    //Первое значение - это вычисленная сумма ряда phi(x).
    //Второе значение - это количество членов ряда, которые были суммированы, прежде чем была достигнута желаемая точность(0.5e-8).
    double sum = 0;
    int num_terms = 0;
    for (int k = 1; k <= 10000; k++) {
        double term = 1.0 / k - 1.0 / (k + x);
        sum += term;
        num_terms++;
        if (abs(term) < 0.5e-8) {//возможно *x
            break;
        }
    }
    return make_pair(sum, num_terms);
}

int main() {
    for (double x = 0; x <= 1; x += 0.1) {
        pair<double, int> result = phi(x);
        cout << "x = " << x << ", phi(x) = " << result.first << ", num_terms = " << result.second << endl;
    }
    return 0;
}
*/




//(3) ЗАДАНИЕ
/*
double func3(double x, double accuracy = 3e-8) {
    double term = 1 / sqrt(1 + x) - 1 / sqrt(1 - x);
    int k = 2;
    double sum = 0;
    while (fabs(term) > accuracy) {
        sum += term;
        term = 1 / sqrt(pow(k, 3) + x) - 1 / sqrt(pow(k, 3) - x);
        k++;
    }
    return sum;
}

double func31(double x, double accuracy = 3e-8) {
    double term = 1 / sqrt(1 + x) - 1 / sqrt(1 - x);
    int k = 2;
    double sum = 0;
    while (fabs(term) > accuracy) {
        sum += term;
        term = 1 / sqrt(pow(k, 3) + x) - 1 / sqrt(pow(k, 3) - x);
        k++;
    }
    return k;
}

int main() {
    for (double x = 0; x < 1; x += 0.1) {
        double F = func3(x);
        cout << "x: " << x << ", F(x): " << F << ", k: " << func31(x) << ", Time: " << func31(x) * 500 << "ms" << endl;
    }
    cout << endl;
    cout << "x: " << 0.5 << ", F(x): " << func3(0.5) << endl;
    cout << "x: " << 0.999999999 << ", F(x): " << func3(0.999999999) << endl;
}
*/



//(4) ЗАДАНИЕ
/*
int main()
{
    double term = 0.5;
    double k1 = 2;
    double sum = 0;
    double accuracy = 1e-10;

    auto start_time = chrono::high_resolution_clock::now();
    while (fabs(term) > accuracy) {
        sum += term;
        term = 1 / (k1 * k1 + 1);
        k1++;
    }
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end_time - start_time;
    double time1 = duration.count();

    double term1 = pow(M_PI, 2) / 6 - pow(M_PI, 4) / 90 + 0.5;
    double k2 = 2;
    double sum1 = 0;

    start_time = chrono::high_resolution_clock::now();
    while (fabs(term1) > accuracy) {
        sum1 += term1;
        term1 = 1 / (pow(k2, 4) * (k2 * k2 + 1));
        k2++;
    }
    end_time = chrono::high_resolution_clock::now();
    duration = end_time - start_time;
    double time2 = duration.count();

    cout << "F(x) : " << sum << ", k1: " << k1 << ", time: " << time1 << " seconds" << endl;
    cout << "F2(X) : " << sum1 << ", k2: " << k2 << ", time: " << time2 << " seconds" << endl;

    return 0;
}
*/




//----------------------- 2 ЛАБА
/*
   int sign(double b)
{
    if (b == 0)return 0;
    if (b > 0)return 1;
    else return -1;
}
bool roots(double a, double b, double c) {
    return b * b - 4 * a * c > 1e-10;
}
int main() {
    setlocale(LC_ALL, "Rus");
    double accuracy = 10e+30;
    double a, b, c, x1, x2, x3, x4;
    cout << "Введите a, b, c: ";
    cin >> a >> b >> c;
       //a *= accuracy;
       //b *= accuracy;
       //c *= accuracy;
if (b == 0 && c != 0) {
    cout << "Нет" << endl;
    return 0;
}
double d = b * b - 4 * a * c;
if (!roots(a, b, c)) {
    cout << "Нет допустимых корней" << endl;
    return 0;
}
if (abs(d) < 1e-10) {
    x1 = x2 = -b / (2 * a);
}
else {
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);
    x3 = -(b + sign(b) * sqrt(b * b - 4 * a * c)) / (2 * a);
    x4 = c / (a * x3);
}
cout << endl << "x1 = " << x1 << endl;
cout << "x2 = " << x2 << endl;
cout << endl << "x3 = " << x3 << endl;
cout << "x4 = " << x4 << endl;
return 0;
}
*/

//Корни:
//1) 1 5 6


//----------------------- 3 ЛАБА




// Функция для выполнения гауссова исключения
vector<vector<double>> gaussianElimination(vector<vector<double>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size() - 1; // Количество переменных

    // Прямое исключение
    for (int i = 0; i < n; ++i) {
        // Найти опорный элемент
        double pivot = matrix[i][i];
        if (fabs(pivot) < 1e-6) {
            // Если опорный элемент равен нулю, поменять местами с строкой ниже
            bool foundPivot = false;
            for (int j = i + 1; j < n; ++j) {
                if (fabs(matrix[j][i]) > 1e-6) {
                    swap(matrix[i], matrix[j]);
                    pivot = matrix[i][i];
                    foundPivot = true;
                    break;
                }
            }
            if (!foundPivot) {
                cout << "Не существует единственного решения." << endl;
                return matrix;
            }
        }

        // Разделить строку на опорный элемент
        for (int j = i; j <= m; ++j) {
            matrix[i][j] /= pivot;
        }

        // Устранить переменную из строк ниже
        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i];
            for (int k = i; k <= m; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    // Обратное исключение
    for (int i = n - 1; i >= 0; --i) {
        // Устранить переменную из строк выше
        for (int j = i - 1; j >= 0; --j) {
            double factor = matrix[j][i];
            for (int k = i; k <= m; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    return matrix;
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Пример 1: 10*x₁ + x₂ = 1, x₁ + 2x₂ = 4
    vector<vector<double>> matrix1 = {
        {10, 1, 1},
        {1, 2, 4}
    };

    cout << "Введенная 1:" << endl;
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1[0].size() - 1; ++j) {
            if (matrix1[i][j] >= 0) {
                cout << "+ " << matrix1[i][j] << "x" << j + 1 << " ";
            }
            else {
                cout << "- " << -matrix1[i][j] << "x" << j + 1 << " ";
            }
        }
        if (matrix1[i][matrix1[0].size() - 1] >= 0) {
            cout << " = " << matrix1[i][matrix1[0].size() - 1] << endl;
        }
        else {
            cout << " = " << -matrix1[i][matrix1[0].size() - 1] << endl;
        }
    }

    matrix1 = gaussianElimination(matrix1);

    cout << "Выведенная 1:" << endl;
    for (int i = 0; i < matrix1.size(); ++i) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(2) << matrix1[i][matrix1[0].size() - 1] << endl;
    }

    // Пример 2: 2.34x₁ - 4.21x₂ - 11.61x₃ = 14.41, 8.04x₁ + 5.22x₂ + 0.27x₃ = -6.44, 3.92x₁ - 7.99x₂ + 8.37x₃ = 55.56
    vector<vector<double>> matrix2 = {
        {2.34, -4.21, -11.61, 14.41},
        {8.04, 5.22, 0.27, -6.44},
        {3.92, -7.99, 8.37, 55.56}
    };

    cout << "Введенная 2:" << endl;
    for (int i = 0; i < matrix2.size(); ++i) {
        for (int j = 0; j < matrix2[0].size() - 1; ++j) {
            if (matrix2[i][j] >= 0) {
                cout << "+ " << matrix2[i][j] << "x" << j + 1 << " ";
            }
            else {
                cout << "- " << -matrix2[i][j] << "x" << j + 1 << " ";
            }
        }
        if (matrix2[i][matrix2[0].size() - 1] >= 0) {
            cout << " = " << matrix2[i][matrix2[0].size() - 1] << endl;
        }
        else {
            cout << " = " << -matrix2[i][matrix2[0].size() - 1] << endl;
        }
    }

    matrix2 = gaussianElimination(matrix2);

    cout << "Выведенная 2:" << endl;
    for (int i = 0; i < matrix2.size(); ++i) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(2) << matrix2[i][matrix2[0].size() - 1] << endl;
    }

    // Пример 3: 4.43x₁ - 7.21x₂ + 8.05x₃ + 1.23x₄ - 2.56x₅ = 2.62, -1.29x₁ + 6.47x₂ + 2.96x₃ + 3.22x₄ + 6.12x₅ = -3.97, 6.12x₁ + 8.31x₂ + 9.41x₃ + 1.78x₄ - 2.88x₅ = -9.12, -2.57x₁ + 6.93x₂ - 3.74x₃ + 7.41x₄ + 5.55x₅ = 8.11, 1.46x₁ + 3.62x₂ + 7.83x₃ + 6.25x₄ - 2.35x₅ = 7.23
    vector<vector<double>> matrix3 = {
        {4.43, -7.21, 8.05, 1.23, -2.56, 2.62},
        {-1.29, 6.47, 2.96, 3.22, 6.12, -3.97},
        {6.12, 8.31, 9.41, 1.78, -2.88, -9.12},
        {-2.57, 6.93, -3.74, 7.41, 5.55, 8.11},
        {1.46, 3.62, 7.83, 6.25, -2.35, 7.23}
    };

    cout << "Введенная 3:" << endl;
    for (int i = 0; i < matrix3.size(); ++i) {
        for (int j = 0; j < matrix3[0].size() - 1; ++j) {
            if (matrix3[i][j] >= 0) {
                cout << "+ " << matrix3[i][j] << "x" << j + 1 << " ";
            }
            else {
                cout << "- " << -matrix3[i][j] << "x" << j + 1 << " ";
            }
        }
        if (matrix3[i][matrix3[0].size() - 1] >= 0) {
            cout << " = " << matrix3[i][matrix3[0].size() - 1] << endl;
        }
        else {
            cout << " = " << -matrix3[i][matrix3[0].size() - 1] << endl;
        }
    }

    matrix3 = gaussianElimination(matrix3);

    cout << "Выведенная 3:" << endl;
    for (int i = 0; i < matrix3.size(); ++i) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(2) << matrix3[i][matrix3[0].size() - 1] << endl;
    }

    return 0;
}
