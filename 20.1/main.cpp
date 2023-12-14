// sorting template program

#include "D:\VisualStudio\ibhly1_cpp\17.1\dice.h"
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 500;

void fillArray(vector<int> &temp);
void screenOutput(const vector<int> &temp);
void swap(int &a, int &b);
void bubbleSort(vector<int> &list);
void selectionSort(vector<int> &list);
void insertionSort(vector<int> &list);
void mergeSort(vector<int> &list);
void quickSort(vector<int> &list);
void sortMenu(vector<int> &temp);

int main() {
   vector<int> list = vector<int>();

   sortMenu(list);
   return 0;
}

void fillArray(vector<int> &temp)
/* Asks the user for two inputs:  1)  the number of data to generate, and
   2) the largest possible random integer to create.  Then
   proceeds to fill the array, from 1..number, where number is stored in
   temp[0]. */
{
   int size;
   int numGen;
   cout << "How many numbers to you wish to generate? ";
   cin >> numGen;
   cout << endl << "Largest integer to generate? ";
   cin >> size;
   dice die(size); // allocate dice object
   for (int loop = 0; loop <= numGen - 1; loop++)
      temp.push_back(die.roll());
   screenOutput(temp);
}

void screenOutput(const vector<int> &temp)
// prints out the contents of the array in tabular form, 12 columns
{
   cout << setiosflags(ios::right) << endl;
   for (int loop = 1; loop <= temp.size(); loop++) {
      cout << setw(6) << temp[loop - 1];
      if (loop % 12 == 0)
         cout << endl;
   }
   cout << endl;
}

void swap(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}

void bubbleSort(vector<int> &list) {
   cout << endl << "Bubble Sort" << endl << endl;
   for (int outer = 0; outer < list.size() - 1; outer++) {
      for (int inner = 0; inner < list.size() - outer - 1; inner++) {
         if (list[inner] > list[inner + 1]) {
            swap(list[inner], list[inner + 1]);
         }
      }
   }
}

void selectionSort(vector<int> &list) {
   cout << endl << "Selection Sort" << endl << endl;
   int min;
   int temp;

   for (int outer = 0; outer < list.size() - 1; outer++) {
      min = outer;
      for (int inner = outer + 1; inner < list.size(); inner++) {
         if (list[inner] < list[min]) {
            min = inner;
         }
      }
      swap(list[outer], list[min]);
   }
}

void insertionSort(vector<int> &list) {
   cout << endl << "Insertion Sort" << endl << endl;
   for (int outer = 1; outer < list.size(); outer++) {
      int position = outer;
      int key = list[position];

      while (position > 0 && list[position - 1] > key) {
         list[position] = list[position - 1];
         position--;
      }
      list[position] = key;
   }
}

void mergeSort(vector<int> &list) {
   cout << endl << "MergeSort" << endl << endl;
}

void quickSort(vector<int> &list) {
   cout << endl << "QuickSort" << endl << endl;
}

void sortMenu(vector<int> &temp) {
   char choice, print;

   do {
      cout << "Sorting algorithm menu" << endl << endl;
      cout << "(1) Bubble sort" << endl;
      cout << "(2) Selection sort" << endl;
      cout << "(3) Insertion sort" << endl;
      cout << "(4) Recursive mergesort" << endl;
      cout << "(5) Quicksort" << endl;
      cout << "(6) Quit" << endl << endl;
      cout << "Choice ---> ";
      cin >> choice;
      cin.get(); // to dump return key
      cout << endl;
      if ('1' <= choice && choice <= '5') {
         fillArray(temp);
         switch (choice) {
         case '1':
            bubbleSort(temp);
            break;
         case '2':
            selectionSort(temp);
            break;
         case '3':
            insertionSort(temp);
            break;
         case '4':
            mergeSort(temp);
            break;
         case '5':
            quickSort(temp);
            break;
         }
         cout << endl << "Print list to screen (y/n)? ";
         cin >> print;
         cin.get();
         if (print == 'y' || print == 'Y')
            screenOutput(temp);
         cout << endl << "Hit return to continue ";
         temp.clear();
         cin.get();
      }
   } while (choice != '6');
}
