//
// Created by 256676 on 5/19/2023.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;
class date{
    public:
        date ();	// default constructor, date is set to valid values of your choice
        date (int month, int day, int year);	// constructor with initial values of month, day, and year
//        date (const date& temp);    // copy constructor, self is constructed as a copy of temp
        void setDate (int month, int day, int year);  // set values for date
        void getDate ();  // get date from keyboard
        void print() const;   // public print function
        date operator++();
        date operator++(int);
        date operator--();
        date operator--(int);

    private:
        int myMonth, myDay, myYear;
        int daysInMonth (int month, int year);	// suggested private member function
};
date::date() : myMonth(1), myDay(1), myYear(2023){}

date::date(int month, int day, int year) : myMonth(month), myDay(day), myYear(year){}

int date::daysInMonth (int month, int year) {
    switch (month){
        case 1 : return 31;
        case 2 : return (year / 100 % 4 == 0 && year % 4 == 0 && !year%100==0) ? 29 : 28;
        case 3 : return 31;
        case 4 : return 30;
        case 5 : return 31;
        case 6 : return 30;
        case 7 : return 31;
        case 8 : return 31;
        case 9 : return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
    return -1;
}

void date::setDate(int month, int day, int year) {
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
    if (day < 1 || day > daysInMonth(month, year)){
        cout << "Invalid Day" << endl;
        return;
    }
    myMonth = month, myDay = day, myYear = year;
}

void date::getDate() {
    int month, day, year;
    cout << "Month: ";
    cin >> month;
    cout << "Day: ";
    cin >> day;
    cout << "Year: ";
    cin >> year;
    setDate(month, day, year);
}

void date::print() const {
    printf("%d/%d/%d", myMonth, myDay, myYear);
}

istream& operator>>(istream& in, date& temp) {
    int month, day, year;
    in >> month;
    in.get();
    in >> day;
    in.get();
    in >> year;
    temp.setDate(month, day, year);
    return in;
}

ostream& operator<<(ostream& out, const date& temp) {
    temp.print();
    return out;
}

date date::operator++() {
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

date date::operator++(int) {
    date temp = *this;
    ++(*this);
    return temp;
}

date date::operator--() {
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

date date::operator--(int) {
    date temp = *this;
    --(*this);
    return temp;
}
#endif //DATE_H
