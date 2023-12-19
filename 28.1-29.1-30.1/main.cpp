#include "date.h"
#include <iostream>

int daysApart(date day1, date day2);

int main() {
   date myDate(1, 11, 2023);
   cin >> myDate;
   cout << myDate;

   return 0;
}
