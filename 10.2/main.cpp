#include <iomanip>
#include <iostream>

using std::cout, std::endl, std::cin, std::setw;
void loan();
void interest();

int main() {
   loan();
   return 0;
}

void loan() {
   double principal, annual_rate, monthly_pay, monthly_rate, month = 1;
   cout << "Principal amount/Amount borrowed:";
   cin >> principal;
   cout << "Annual rate(in decimal form):";
   cin >> annual_rate;
   monthly_rate = annual_rate / 12;
   cout << "Monthly pay:";
   cin >> monthly_pay;

   cout << setw(5) << "Month" << setw(12) << "Principal" << setw(12)
        << "Interest" << setw(12) << "Payment" << setw(20) << "New Balance";
   do {
      cout << "\n";
      double interest = principal * monthly_rate;
      double balance = principal + interest - monthly_pay;
      cout << setw(5) << month << setw(12) << principal << setw(12) << interest
           << setw(12) << monthly_pay << setw(14) << std::fixed
           << std::setprecision(2) << balance;
      principal = balance;
      month++;
   } while (principal > monthly_pay);
}

void interest() {}
