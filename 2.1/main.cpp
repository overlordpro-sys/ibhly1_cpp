#include <iostream>

int main() {
   int integer = 1;
   long longer = -2222222;
   unsigned int unsignInt = 12;
   unsigned long unsignedLonger = 222222;
   float oneDigit = .2;
   double doubleFloat = 0.22222;
   long double longerDouble = 222.22222;
   bool boolean = false;

   std::cout << "\n"
             << integer << "\n"
             << longer << "\n"
             << unsignInt << "\n"
             << unsignedLonger << "\n"
             << oneDigit << "\n"
             << doubleFloat << "\n"
             << longerDouble << "\n"
             << boolean;
   return 0;
}
