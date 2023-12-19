#include "../28.1-29.1-30.1/date.h"
#include <iostream>
#include <map>

using namespace std;

int daysApart(date day1, date day2);

int main() {
   // Find days between for the following dates
   // 6/27/96 and 6/27/96
   // 6/27/96 and 6/28/96
   // 6/28/96 and 6/27/96
   // 1/1/95 and 1/1/96
   // 1/1/96 and 1/1/95

   // 2/25/96 and 3/10/96
   // 3/10/96 and 2/25/96
   // 12/25/96 and 1/6/97
   // 1/6/97 and 12/25/96

   map<date, date> dateMap = {
       {date(6, 27, 1996), date(6, 27, 1996)},
       {date(6, 27, 1996), date(6, 28, 1996)},
       {date(6, 28, 1996), date(6, 27, 1996)},
       {date(1, 1, 1995), date(1, 1, 1996)},
       {date(1, 1, 1996), date(1, 1, 1995)},
       {date(2, 25, 1996), date(3, 10, 1996)},
       {date(3, 10, 1996), date(2, 25, 1996)},
       {date(12, 25, 1996), date(1, 6, 1997)},
       {date(1, 6, 1997), date(12, 25, 1996)},
   };

   // Find days apart for each pair of dates
   for (auto it : dateMap) {
      cout << it.first << " and " << it.second << " are "
           << daysApart(it.first, it.second) << " days apart" << endl;
   }
   return 0;
}

int daysApart(date day1, date day2) {
   int days = 0;
   while (day1 != day2) {
      if (day1 < day2) {
         day1++;
      } else {
         day1--;
      }
      days++;
   }
   return days;
}