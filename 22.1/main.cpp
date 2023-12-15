#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void fillArray(vector<int> &vec, int quantity, int largest);
void screenOutput(vector<int> &vec);
void selectionSort(vector<int> &list);
void merge(vector<int> tempA, vector<int> tempB, vector<int> &C);
int main() {
   srand((unsigned)time(0));
   //    vector<int> one({1, 5, 10, 13}), two({2, 6, 11, 15}), three;

   vector<int> one, two, three;
   fillArray(one, 20, 100);
   fillArray(two, 20, 90);
   selectionSort(one);
   selectionSort(two);
   merge(one, two, three);
   screenOutput(three);
   return 0;
}

void fillArray(vector<int> &vec, int quantity, int largest) {
   for (int i = 1; i <= quantity; i++)
      vec.push_back(rand() % largest);
}

void screenOutput(vector<int> &vec) {
   for (auto it = vec.begin(); it != vec.end(); it++) {
      if ((it - vec.begin()) % 20 == 0)
         cout << "\n";
      cout << *it << " ";
   }
}

void selectionSort(vector<int> &list) {
   int temp;
   for (int j = 0; j < list.size() - 1; ++j) {
      int min = list.at(j);
      temp = j;
      for (int i = j + 1; i < list.size(); ++i) {
         if (min > list.at(i)) {
            min = list.at(i);
            temp = i;
         }
      }
      swap(list.at(j), list.at(temp));
   }
}

void merge(vector<int> A, vector<int> B, vector<int> &C) {
   while (A.size() != 0 || B.size() != 0) {
      if (B.size() == 0) {
         C.push_back(A[0]);
         A.erase(A.begin());
      } else if (A.size() == 0) {
         C.push_back(B[0]);
         B.erase(B.begin());
      } else {
         if (A[0] < B[0]) {
            C.push_back(A[0]);
            A.erase(A.begin());
         } else {
            C.push_back(B[0]);
            B.erase(B.begin());
         }
      }
   }
}
