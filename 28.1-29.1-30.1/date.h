//
// Created by 256676 on 5/19/2023.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;
class date {
 public:
   date(); // default constructor, date is set to valid values of your choice
   date(int month, int day,
        int year); // constructor with initial values of month, day, and year
   //        date (const date& temp);    // copy constructor, self is
   //        constructed as a copy of temp
   void setDate(int month, int day, int year); // set values for date
   void getDate();                             // get date from keyboard
   void print() const;                         // public print function
   date operator++();
   date operator++(int);
   date operator--();
   date operator--(int);
   int operator-(date const &rhs);
   int myMonth, myDay, myYear;

 private:
   int daysInMonth(int month, int year); // suggested private member function
};
inline date::date() : myMonth(1), myDay(1), myYear(2023) {}

inline date::date(int month, int day, int year)
    : myMonth(month), myDay(day), myYear(year) {}

inline int date::daysInMonth(int month, int year) {
   switch (month) {
   case 1:
      return 31;
   case 2:
      return (year / 100 % 4 == 0 && year % 4 == 0 && !year % 100 == 0) ? 29
                                                                        : 28;
   case 3:
      return 31;
   case 4:
      return 30;
   case 5:
      return 31;
   case 6:
      return 30;
   case 7:
      return 31;
   case 8:
      return 31;
   case 9:
      return 30;
   case 10:
      return 31;
   case 11:
      return 30;
   case 12:
      return 31;
   }
   return -1;
}

inline void date::setDate(int month, int day, int year) {
   if (year < 100) {
      if (year >= 25)
         year += 1900;
      else if (year >= 1)
         year += 2000;
      else
         year = 2000;
   }
   if (month < 1 || month > 12) {
      cout << "Invalid Month" << endl;
      return;
   }
   if (day < 1 || day > daysInMonth(month, year)) {
      cout << "Invalid Day" << endl;
      return;
   }
   myMonth = month, myDay = day, myYear = year;
}

inline void date::getDate() {
   int month, day, year;
   cout << "Month: ";
   cin >> month;
   cout << "Day: ";
   cin >> day;
   cout << "Year: ";
   cin >> year;
   setDate(month, day, year);
}

inline void date::print() const { printf("%d/%d/%d", myMonth, myDay, myYear); }

inline istream &operator>>(istream &in, date &temp) {
   int month, day, year;
   cout << "Month: ";
   in >> month;
   in.get();
   cout << "Day: ";
   in >> day;
   in.get();
   cout << "Year: ";
   in >> year;
   temp.setDate(month, day, year);
   return in;
}

inline ostream &operator<<(ostream &out, const date &temp) {
   temp.print();
   return out;
}

inline date date::operator++() {
   myDay++;
   if (myDay > daysInMonth(myMonth, myYear)) {
      myDay = 1;
      myMonth++;
   }
   if (myMonth > 12) {
      myMonth++;
      myYear++;
   }
   return *this;
}

inline date date::operator++(int) {
   date temp = *this;
   ++(*this);
   return temp;
}

inline date date::operator--() {
   myDay--;
   if (myDay < 1) {
      myMonth--;
      if (myMonth < 1) {
         myYear--;
         myMonth = 12;
      }
      myDay = daysInMonth(myMonth, myYear);
   }
   return *this;
}

inline date date::operator--(int) {
   date temp = *this;
   --(*this);
   return temp;
}

inline bool operator==(const date &lhs, const date &rhs) {
   return lhs.myYear == rhs.myYear && lhs.myMonth == rhs.myMonth &&
          lhs.myDay == rhs.myDay;
}

inline bool operator!=(const date &lhs, const date &rhs) {
   return !(lhs.myYear == rhs.myYear && lhs.myMonth == rhs.myMonth &&
            lhs.myDay == rhs.myDay);
}

inline bool operator<(const date &lhs, const date &rhs) {
   if (lhs.myYear < rhs.myYear)
      return true;
   if (lhs.myYear > rhs.myYear)
      return false;
   if (lhs.myMonth < rhs.myMonth)
      return true;
   if (lhs.myMonth > rhs.myMonth)
      return false;
   if (lhs.myDay < rhs.myDay)
      return true;
   if (lhs.myDay > rhs.myDay)
      return false;
   return false;
}

inline bool operator>(const date &lhs, const date &rhs) {
   if (lhs.myYear > rhs.myYear)
      return true;
   if (lhs.myYear < rhs.myYear)
      return false;
   if (lhs.myMonth > rhs.myMonth)
      return true;
   if (lhs.myMonth < rhs.myMonth)
      return false;
   if (lhs.myDay > rhs.myDay)
      return true;
   if (lhs.myDay < rhs.myDay)
      return false;
   return false;
}

#endif // DATE_H
