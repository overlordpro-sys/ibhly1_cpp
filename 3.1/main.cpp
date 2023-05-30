#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    double amount, paid, change;
    int cents, quarters, dimes, nickels;
    cout << "Purchase Amount:";
    cin >> amount;
    cout << endl << "Amount paid:";
    cin >> paid;

    change = (paid - amount);
    change = change - int(change) + .0001;
    cents = int(change * 100);
    quarters = cents / 25;
    cents %= 25;

    dimes = cents / 10;
    cents %= 10;

    nickels = cents / 5;
    cents %= 5;

    cout << endl << "Change - Quarters: " << quarters <<
                    "\nDimes: " << dimes <<
                    "\nNickels: " << nickels <<
                    "\nPennies: " << cents;
    return 0;
}
