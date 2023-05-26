/*
Requires:
PayOff1.cpp
Random1.cpp
SimpleMC.cpp
*/
#include <SimpleMC.h>
#include <iostream>

using namespace std;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry: ";
    cin >> Expiry;

    cout << "\nEnter strike: ";
    cin >> Strike;

    cout << "\nEnter spot: ";
    cin >> Spot;

    cout << "\nEnter vol: ";
    cin >> Vol;

    cout << "\nEnter r: ";
    cin >> r;

    cout << "\nEnter number of paths: ";
    cin >> NumberOfPaths;

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);

    double resultCall = SimpleMonteCarlo2(callPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    double resultPut = SimpleMonteCarlo2(putPayOff,
                                         Expiry,
                                         Spot,
                                         Vol,
                                         r,
                                         NumberOfPaths);

    cout << "\nThe prices are " << resultCall << " for the call and "
         << resultPut << " for the put\n";

    double tmp;
    cin >> tmp;
    return 0;
}
