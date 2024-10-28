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
