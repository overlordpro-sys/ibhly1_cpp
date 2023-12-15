#include "dice.h"
#include <iostream>
#include <string>

using std::string, std::cin, std::cout;
int main() {
   cout << 0 / 200;
   string input = "";
   while (input != "-1") {
      int numTimes = 0;
      dice die1(6), die2(6);
      cout << "Enter the number for a pair of dice to calculate the "
              "probability of (-1 to exit):";
      cin >> input;
      int target = std::stoi(input);
      if (target >= 2 && target <= 12) {
         for (int i = 0; i < 1000; i++) {
            int num1 = die1.roll(), num2 = die2.roll();
            if (num1 + num2 == target)
               numTimes++;
         }
      } else {
         cout << "Invalid target number"
              << "\n";
         continue;
      }
      cout << numTimes << "\n";
      cout << "Number: " << target << "\t Probability: "
           << (double)numTimes / (die1.numRolls() + die2.numRolls()) << "\n";
   }
   return 0;
}
