#include "SimpleMC2.h"
#include "PayOff2.h"
#include <iostream>

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    std::cout << "\nEnter expiry: ";
    std::cin >> Expiry;
    std::cout << "\nEnter strike: ";
    std::cin >> Strike;
    std::cout << "\nEnter spot: ";
    std::cin >> Spot;
    std::cout << "\nEnter vol: ";
    std::cin >> Vol;
    std::cout << "\nEnter r: ";
    std::cin >> r;
    std::cout << "\nEnter number of paths: ";
    std::cin >> NumberOfPaths;

    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);

    double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);

    std::cout << "The prices are " << resultCall << " for the call and " << resultPut << " for the put\n";

    double tmp;
    std::cin >> tmp;

    return 0;
}
