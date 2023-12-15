#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int> &list, int first, int last);
void screenOutput(vector<int> vec);
void fillArray(vector<int> &vec, int quantity, int largest);

int main() {
   vector<int> test;
   fillArray(test, 40, 100);
   quickSort(test, 0, test.size() - 1);
   screenOutput(test);
   return 0;
}

void screenOutput(vector<int> vec) {
   for (auto it = vec.begin(); it != vec.end(); it++) {
      if ((it - vec.begin()) % 20 == 0)
         cout << "\n";
      cout << *it << " ";
   }
}

void fillArray(vector<int> &vec, int quantity, int largest) {
   for (int i = 1; i <= quantity; i++)
      vec.push_back(rand() % largest);
}

void quickSort(vector<int> &list, int first, int last) {
   int g = first, h = last;
   int midIndex, dividingValue, temp;
   midIndex = (first + last) / 2;
   dividingValue = list[midIndex];
   do {
      while (list[g] < dividingValue)
         g++;
      while (list[h] > dividingValue)
         h--;
      if (g <= h) {
         swap(list[g], list[h]);
         g++;
         h--;
      }
   } while (g < h);
   if (h > first)
      quickSort(list, first, h);
   if (g < last)
      quickSort(list, g, last);
}
