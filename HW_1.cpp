//#include <iostream> 
//#include <cmath> 

//using namespace std;


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




//  (3) ЗАДАНИЕ
/*
double phi(double x, int n, bool print_terms = false) {
    double sum = 0;
    for (int k = 1; k <= n; ++k) {
        double term = 1.0 / (k * (k + x));
        sum += term;
        if (print_terms) {
            cout << "k = " << k << ", term = " << term << endl;
        }
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");
    for (double x = 0; x <= 1.0; x += 0.1) {
        int n = 1;
        double prev_sum = phi(x, n);
        double sum = phi(x, n + 1);
        while (abs(sum - prev_sum) > 0.5e-8) {
            n++;
            prev_sum = sum;
            sum = phi(x, n);
        }
        cout << "x = " << x << ", sum = " << sum << endl;
        cout << "Члены суммирования для n = " << n << ":" << endl;
        phi(x, n, true);
        cout << endl;
    }
    return 0;
}
*/





//(4) ЗАДАНИЕ


/*
double phi(double x) {
    double sum = 0;
    for (int k = 1; k <= 10000; k++) {
        sum += 1.0 / (k * (k + x));
    }
    return sum;
}

int main() {
    double sum = 1.0 / 6 - 1.0 / 90;
    int numTerms = 0;
    for (int n = 4; n <= 10000; n++) {
        sum += 1.0 / (n * (n + 1));
        numTerms++;
    }

    cout << "Number of terms: " << numTerms << endl;
    cout << "The value of the sum is: " << sum << endl;

    return 0;
}
*/




//Хорошая формула

#include <iostream>
#include <chrono>

using namespace std;

double phi(double x) {
    double sum = 0;
    for (int k = 1; k <= 10000; k++) {
        sum += 1.0 / (k * (k + x));
    }
    return sum;
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    double sum = 1.0 / 6 - 1.0 / 90;
    int numTerms = 0;
    for (int n = 4; n <= 10000; n++) {
        sum += 1.0 / (n * (n + 1));
        numTerms++;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Number of terms: " << numTerms << endl;
    cout << "The value of the sum is: " << sum << endl;
    cout << "Time elapsed: " << elapsed.count() << " seconds" << endl;

    return 0;
}



/*
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    // Начало отсчета времени
    auto start = chrono::high_resolution_clock::now();

    double sum = 0;
    int n = 1;
    double error = 1;

    while (error > 1e-10) {
        sum += 1.0 / (n * n + 1);
        error = 1.0 / (n * n + 1);
        n++;
    }

    // Конец отсчета времени
    auto end = chrono::high_resolution_clock::now();

    // Вычисление времени выполнения
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Сумма ряда: " << sum << endl;
    cout << "Время вычисления: " << elapsed_seconds.count() << " секунд" << endl;

    return 0;
}
*/




//----------------------- 2 ЛАБА
/*
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Функция для решения квадратного уравнения
pair<double, double> solveQuadraticEquation(double a, double b, double c) {
    // Проверка на нулевой коэффициент при x^2
    if (abs(a) < numeric_limits<double>::epsilon()) {
        // Если a равно нулю, уравнение линейное
        if (abs(b) < numeric_limits<double>::epsilon()) {
            // Если b также равно нулю, то уравнение не имеет решения
            return make_pair(numeric_limits<double>::quiet_NaN(), numeric_limits<double>::quiet_NaN());
        }
        else {
            // Решение линейного уравнения
            return make_pair(-c / b, numeric_limits<double>::quiet_NaN());
        }
    }

    // Вычисление дискриминанта
    double discriminant = b * b - 4 * a * c;

    // Проверка на отрицательный дискриминант
    if (discriminant < 0) {
        // Уравнение не имеет действительных корней
        return make_pair(numeric_limits<double>::quiet_NaN(), numeric_limits<double>::quiet_NaN());
    }

    // Вычисление корней
    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);

    return make_pair(x1, x2);
}

int main() {
    setlocale(LC_ALL, "Rus");
    double a, b, c;

    cout << "Введите коэффициенты a, b, c для уравнения ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;

    // Вычисление корней квадратного уравнения
    pair<double, double> roots = solveQuadraticEquation(a, b, c);

    // Вывод результатов
    if (isnan(roots.first) && isnan(roots.second)) {
        cout << "Уравнение не имеет действительных корней." << endl;
    }
    else if (isnan(roots.second)) {
        cout << "Уравнение имеет один корень: " << roots.first << endl;
    }
    else {
        cout << "Уравнение имеет два корня: " << roots.first << " и " << roots.second << endl;
    }

    return 0;
}
*/
