#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double S0, U, D, R;

    // Entering data
    cout << "Enter S0: "; 
    cin >> S0;
    cout << "Enter U: "; 
    cin >> U;
    cout << "Enter D: "; 
    cin >> D;
    cout << "Enter R: "; 
    cin >> R;
    cout << endl;

    // Making sure that 0<S0, -1<D<U, -1<R
    if (S0 <= 0.0 || U <= -1.0 || D <= -1.0 || U <= D || R <= -1.0) {
        cout << "Illegal data ranges" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    // Checking for arbitrage
    if (R >= U || R <= D) {
        cout << "Arbitrage exists" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    cout << "Input data checked" << endl;
    cout << "There is no arbitrage" << endl << endl;

    // Compute risk-neutral probability
    double q = (R - D) / (U - D);
    cout << "q = " << q << endl;

    // Compute stock price at node n=3, i=2
    int n = 3, i = 2;
    double stockPrice = S0 * pow(1 + U, i) * pow(1 + D, n - i);
    cout << "n = " << n << endl;
    cout << "i = " << i << endl;
    cout << "S(n,i) = " << stockPrice << endl;

    return 0;
}
