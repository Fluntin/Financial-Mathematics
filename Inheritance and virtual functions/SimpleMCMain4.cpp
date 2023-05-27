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

    unsigned long optionType;
    std::cout << "\nEnter 0 for call, otherwise put: ";
    std::cin >> optionType;

    PayOff* thePayOffPtr;
    if (optionType == 0)
        thePayOffPtr = new PayOffCall(Strike);
    else
        thePayOffPtr = new PayOffPut(Strike);

    double result = SimpleMonteCarlo2(*thePayOffPtr, Expiry, Spot, Vol, r, NumberOfPaths);

    std::cout << "\nThe price is " << result << "\n";

    double tmp;
    std::cin >> tmp;

    delete thePayOffPtr;

    return 0;
}
