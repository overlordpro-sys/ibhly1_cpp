// ages.cpp

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
// global definitions

struct student {
   string lastName;
   string firstName;
   int age;
};

struct listType {
   int number; // how many Students are in the list
   vector<student> list;
};

// function prototypes

void loadFile(const string &, listType &);
void printList(const listType &);
void addStudent(listType &, const student &);
void doAddStudent(listType &);
void swap(student &, student &);
void quickSort(vector<student> &, int, int);
void saveFile(const string &, const listType &);
ostream &operator<<(ostream &out, const student &);

int main() {
   listType data;

   loadFile("Mac HD:ap97:names.txt", data);
   printList(data);
   doAddStudent(data);
   quickSort(data.list, 0, data.number - 1);
   cout << endl;
   printList(data);
   saveFile("Mac HD:ap97:names.txt", data);
   return 0;
}

void loadFile(const string &fileName, listType &temp)
// precondition:  temp.list has a size of 0, will need to be resized
{
   ifstream inFile; // open inFile, link to external file

   inFile.open(fileName);
   if (inFile.fail()) {
      cerr << "Could not open " << fileName << endl;
      abort();
   }
   inFile >> temp.number;
   temp.list.resize(temp.number);
   for (int k = 0; k < temp.number; k++) {
      inFile >> temp.list[k].lastName;
      inFile >> temp.list[k].firstName;
      inFile >> temp.list[k].age;
   }
}

void printList(const listType &temp) {
   cout << endl;
   for (int k = 0; k < temp.number; k++)
      cout << k + 1 << " " << temp.list[k] << endl;
   cout << endl;
}

void doAddStudent(listType &temp) {
   student newData;
   do {
      cout << "Enter last name of Student (done to quit) ---> ";
      cin >> newData.lastName;
      if ("done" != newData.lastName) {
         cout << "Enter first name of Student ---> ";
         cin >> newData.firstName;
         cin.get(); // to dump return key stuck in cin
         cout << "Enter age of Student ---> ";
         cin >> newData.age;
         addStudent(temp, newData);
      }
   } while ("done" != newData.lastName);
}

void addStudent(listType &temp, const student &newStudent) {
   if (temp.list.size() == temp.number)  // if list is full
      temp.list.resize(temp.number * 2); // make list twice as big
   temp.list[temp.number] = newStudent;  // copy newStudent into list
   temp.number++;
}

void swap(student &a, student &b) {
   student temp = a;
   a = b;
   b = temp;
}

void quickSort(vector<student> &list, int first, int last) {
   int g = first, h = last;
   int midIndex;
   string dividingValue;

   midIndex = (first + last) / 2;
   dividingValue = list[midIndex].lastName;
   do {
      while (list[g].lastName < dividingValue)
         g++;
      while (list[h].lastName > dividingValue)
         h--;
      if (g <= h) {
         swap(list[g], list[h]);
         g++;
         h--;
      }
   } while (h > g);
   if (h > first)
      quickSort(list, first, h);
   if (g < last)
      quickSort(list, g, last);
}

void saveFile(const string &fileName, const listType &temp) {
   ofstream outFile(fileName);

   outFile << temp.number << endl;
   for (int k = 0; k < temp.number; k++)
      outFile << temp.list[k] << endl;
}

ostream &operator<<(ostream &out, const student &temp) {
   out << temp.lastName << " " << temp.firstName << " " << temp.age;
   return out;
}
