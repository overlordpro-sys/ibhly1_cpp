#include <iostream>
void promptUser(bool &single, double &income);
double calculateSingleTax(double income);
double calculateMarried(double income);

int main() {
   bool single;
   double income;
   promptUser(single, income);
   std::cout << "Filing status" << (single ? "Single" : "Married") << std::endl;
   std::cout << "Taxable income" << income << std::endl;
   if (single)
      std::cout << "Your tax is: " << calculateSingleTax(income) << std::endl;
   else
      std::cout << "Your tax is: " << calculateMarried(income) << std::endl;
   return 0;
}

void promptUser(bool &single, double &income) {
   char temp;
   std::cout << "Are you single? (y/n): ";
   std::cin >> temp;
   single = (temp == 'y' || temp == 'Y') ? true : false;
   std::cout << "Enter your income: ";
   std::cin >> income;
}

double calculateSingleTax(double income) {
   if (income <= 24650)
      return income * 0.15;
   else if (income <= 59750)
      return 3697.50 + (income - 24650) * 0.28;
   else
      return 13525.50 + (income - 59750) * 0.31;
}

double calculateMarried(double income) {
   if (income <= 41200)
      return income * 0.15;
   else if (income <= 99600)
      return 6180 + (income - 41200) * 0.28;
   else
      return 22532 + (income - 99600) * 0.31;
}
