#include "SimpleMC2.h"
#include "DoubleDigital.h"
#include <iostream>

int main()
{
    double Expiry;
    double Low, Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    std::cout << "\nEnter expiry: ";
    std::cin >> Expiry;
    std::cout << "\nEnter low barrier: ";
    std::cin >> Low;
    std::cout << "\nEnter up barrier: ";
    std::cin >> Up;
    std::cout << "\nEnter spot: ";
    std::cin >> Spot;
    std::cout << "\nEnter vol: ";
    std::cin >> Vol;
    std::cout << "\nEnter r: ";
    std::cin >> r;
    std::cout << "\nEnter number of paths: ";
    std::cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low, Up);

    double result = SimpleMonteCarlo2(thePayOff, Expiry, Spot, Vol, r, NumberOfPaths);

    std::cout << "\nThe price is " << result << "\n";

    double tmp;
    std::cin >> tmp;

    return 0;
}
