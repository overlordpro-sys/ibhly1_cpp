#include "frog.h"
#include <iostream>
#include <string>

using std::cout, std::cin, std::string;
int main() {
   string input;
   int steps;
   frog frog1;
   cout << "How many steps to take?: ";
   cin >> input;
   steps = stoi(input);
   for (int i = 1; i <= steps; i++)
      frog1.move();
   cout << "Frog pos: " << frog1.getPos();
   return 0;
}
