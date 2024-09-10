#include <iostream> 
#include <cmath> 

using namespace std;


/*    (1) ЗАДАНИЕ
const double PI = 3.14159265358979323846;

double factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

double erf(double x) {
    double sum = 0;
    for (int n = 0; n < 100; n++) {
        double term = pow(-1, n) * pow(x, 2 * n + 1) / (factorial(n) * (2 * n + 1));
        sum += term;
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
        cout << "erf(" << x << ") = " << result << endl;
    }

    return 0;
}
*/



/* (2) ЗАДАНИЕ
#include <iostream>
#include <cmath>

using namespace std;

double phi(double x) {
  double sum = 0;
  for (int k = 1; k <= 10000; k++) {
    sum += 1.0 / (k * (k + x));
  }
  return sum;
}

int main() {
  for (double x = 0; x <= 1; x += 0.1) {
    cout << "x = " << x << ", phi(x) = " << phi(x) << endl;
  }
  return 0;
}
*/



/*  (3) ЗАДАНИЕ
#include <iostream>
#include <cmath>

using namespace std;

double phi(double x, int n) {
    double sum = 0;
    for (int k = 1; k <= n; ++k) {
        sum += 1.0 / (k * (k + x));
    }
    return sum;
}

int main() {
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
    }
    return 0;
}
*/

#include <iostream>
#include <cmath>

using namespace std;

double phi(double x) {
    double sum = 0;
    for (int k = 1; k <= 10000; k++) {
        sum += 1.0 / (k * (k + x));
    }
    return sum;
}

int main() {
    for (double x = 0; x <= 1.0; x += 0.1) {
        cout << "x = " << x << ", phi(x) = " << phi(x) << endl;
    }
    return 0;
}