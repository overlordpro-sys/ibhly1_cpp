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
             << "The value of integer = " << integer
             << "\t The byte size of integer is " << sizeof(integer)
             << " bytes.\n"
             << "The value of longer = " << longer
             << "\t The byte size of longer is " << sizeof(longer)
             << " bytes.\n"
             << "The value of unsignInt = " << unsignInt
             << "\t The byte size of unsignInt is " << sizeof(unsignInt)
             << " bytes.\n"
             << "The value of unsignedLonger = " << unsignedLonger
             << "\t The byte size of unsignedLonger is "
             << sizeof(unsignedLonger) << " bytes.\n"
             << "The value of oneDigit = " << oneDigit
             << "\t The byte size of oneDigit is " << sizeof(oneDigit)
             << " bytes.\n"
             << "The value of doubleFloat = " << doubleFloat
             << "\t The byte size of doubleFloat is " << sizeof(doubleFloat)
             << " bytes.\n"
             << "The value of longerDouble = " << longerDouble
             << "\t The byte size of longerDouble is " << sizeof(longerDouble)
             << " bytes.\n"
             << "The value of boolean = " << boolean
             << "\t The byte size of boolean is " << sizeof(boolean)
             << " bytes.\n";
   return 0;
}
