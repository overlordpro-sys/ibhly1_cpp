#include <cmath>
#include <iostream>

using namespace std;
double fToC(double temp) { return 5.0 / 9.0 * (temp - 32.0); }

double cToF(double temp) { return 9.0 / 5.0 * temp + 32; }

double sphereRadius(double radius) { return 4 / 3 * M_PI * pow(radius, 3); }

double hypot(double a, double b) { return sqrt(pow(a, 2) + pow(b, 2)); }

int main() {
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "212 degrees F ---> " << fToC(212) << " degrees C" << endl;
   cout << "98.6 degrees F ---> " << fToC(98.6) << " degrees C" << endl;
   cout << "10 degrees F ---> " << fToC(10) << " degrees C" << endl;

   cout << "-15 degrees C ---> " << cToF(-15) << " degrees F" << endl;
   cout << "0 degrees C ---> " << cToF(0) << " degrees F" << endl;
   cout << "70 degrees C ---> " << cToF(70) << " degrees F" << endl;

   cout << "Volume of radius 1.0 sphere ---> " << sphereRadius(1.0)
        << " units cubed" << endl;
   cout << "Volume of radius 2.25 sphere ---> " << sphereRadius(2.25)
        << " units cubed" << endl;
   cout << "Volume of radius 7.50 sphere ---> " << sphereRadius(7.50)
        << " units cubed" << endl;

   cout << "Hypotenuse of 3.0 and 4.0 ---> " << hypot(3.0, 4.0) << endl;
   cout << "Hypotenuse of 6.75 and 12.31 ---> " << hypot(6.75, 12.31) << endl;
   return 0;
}