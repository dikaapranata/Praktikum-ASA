#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double Exp3(double a, int n) {
    if (n == 0) {
        return 1;
    } else {
        double x = Exp3(a, n / 2);
        cout << "Nilai x -> " << fixed << setprecision(2) << x << endl;
        if (n % 2 == 1) { // odd
            cout << "Fungsi n Ganjil x*x*a -> " 
                 << fixed 
                 << setprecision(2) 
                 << x * x * a
                 << endl;
            return x * x * a;
        } else { // even
            cout<< "Fungsi n Genap x*x -> "
                << fixed
                << setprecision(2)
                << x * x
                << endl;
            return x * x;
        }
    }
}

int main() {
    double a;
    int n;
    cin >> a >> n;

    double result = Exp3(a, n);
    cout<<fixed<<setprecision(2)<<result<<endl;

    return 0;
}