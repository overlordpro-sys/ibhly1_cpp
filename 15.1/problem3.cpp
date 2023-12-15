#include "frog.h"
#include <cstdio>
#include <iostream>

using std::cout, std::cin, std::string;
int main() {
   string input;
   int steps, times;
   frog frog1, frog2;
   cout << "How many steps to have both frogs take?: ";
   cin >> input;
   steps = stoi(input);
   for (int i = 1; i <= steps; i++) {
      frog1.move();
      frog2.move();
      if (frog1.getPos() == frog2.getPos())
         times++;
   }
   printf("Frog 1 Pos: %d | Frog 2 Pos: %d | Times on same space: %d",
          frog1.getPos(), frog2.getPos(), times);
   return 0;
}
