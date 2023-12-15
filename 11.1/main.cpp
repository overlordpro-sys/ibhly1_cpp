#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::endl, std::cin, std::string, std::vector,
    std::stringstream, std::find;

int main() {
   string input = "", grades = "";
   while (input != "-1") {
      cout << "Input your letter grades separated by a space (-1 to finish):";
      cin >> input;
      grades += input;
      cout << "\n";
   }

   bool hasF = false;
   int numClasses = 0;
   double gpaSum = 0;

   for (int i = 0; i < grades.length(); i++) {
      switch (grades.at(i)) {
      case 'A':
         gpaSum += 4;
         numClasses++;
         break;
      case 'B':
         gpaSum += 3;
         numClasses++;
         break;
      case 'C':
         gpaSum += 2;
         numClasses++;
         break;
      case 'D':
         gpaSum += 1;
         numClasses++;
         break;
      case 'F':
         numClasses++;
         hasF = true;
         break;
      }
   }

   if (numClasses < 4) {
      cout << "Ineligible, taking less than 4 classes";
   } else if (gpaSum / numClasses < 2) {
      cout << "Ineligible, gpa below 2.0";
      if (hasF) {
         cout << " and has F grade";
      }
   } else {
      if (hasF) {
         cout << "Ineligible, gpa above 2.0 but has F grade";
      } else {
         cout << "Eligible";
      }
   }
   cout << "GPA: " << gpaSum / numClasses;
}
