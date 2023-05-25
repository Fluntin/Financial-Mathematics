#include <Random1.h>
#include <iostream>
#include <cmath>

using namespace std;

double SimpleMonteCarlo1(double Expiry, double Strike, double Spot, double Vol, double r, unsigned long NumberOfPaths)
{
    double variance = Vol * Vol * Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    double movedSpot = Spot * exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);
    return mean;
}

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter strike: ";
    cin >> Strike;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter vol: ";
    cin >> Vol;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter number of paths: ";
    cin >> NumberOfPaths;

    double result = SimpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, NumberOfPaths);
    cout << "The price is " << result << "\n";

    double tmp;
    cin >> tmp;

    return 0;
}
