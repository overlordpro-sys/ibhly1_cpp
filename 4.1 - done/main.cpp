#include <iomanip>
#include <iostream>

using namespace std;
int main() {
   double hours, rate, grosspay, fTax, fica, sTax, netpay;
   const double fTaxRate = .15, ficaRate = .08, sTaxRate = .032;
   cout << "Hours worked? ";
   cin >> hours;
   cout << "Hourly rate? ";
   cin >> rate;
   grosspay = hours * rate;
   fTax = grosspay * fTaxRate;
   fica = grosspay * ficaRate;
   sTax = grosspay * sTaxRate;
   netpay = grosspay - fTax - fica - sTax;

   cout << setw(25) << left << "Hours worked" << setprecision(2) << fixed
        << hours << endl;
   cout << setw(25) << left << "Hourly rate" << setprecision(2) << fixed << rate
        << endl
        << endl;
   cout << setw(25) << left << "Gross pay" << setprecision(2) << fixed
        << grosspay << endl
        << endl;
   cout << setw(25) << left << "Federal tax (15%)" << setprecision(2) << fixed
        << fTax << endl;
   cout << setw(25) << left << "FICA (8%)" << setprecision(2) << fixed << fica
        << endl;
   cout << setw(25) << left << "State tax (3.2%)" << setprecision(2) << fixed
        << sTax << endl
        << endl;
   cout << setw(25) << left << "Net pay" << setprecision(2) << fixed << netpay
        << endl;

   return 0;
}
