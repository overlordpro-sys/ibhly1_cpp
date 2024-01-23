#include "frog.h"
#include <iostream>
#include <string>

using std::cout, std::cin, std::string;
int main() {
   string input;
   int target;
   frog frog1;
   cout << "How many target from origin to move to?: ";
   cin >> input;
   target = stoi(input);
   while (abs(frog1.getPos()) != target)
      frog1.move();
   cout << "Frog total steps: " << frog1.getSteps()
        << "\tCurrent Position: " << frog1.getPos();
   return 0;
}
