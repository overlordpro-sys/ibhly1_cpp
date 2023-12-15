#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct item {
   int myId, myInv;
   item(int id, int inv) : myId(id), myInv(inv) {}
};

struct storeType {
   vector<item> list;
   int count = 1;
   void printStore() {
      for (auto it = list.begin(); it != list.end(); it++) {
         printf("%-4dId: %-6d  Inv %-4d\n", count, it->myId, it->myInv);
         if (count % 10 == 0)
            cout << "\n";
         count++;
      }
   }
};

void loadStore(string filename, storeType &store);
void quickSort(vector<item> &list, int first, int last);
void testSearch(const storeType &store);
int bsearch(const storeType &store, int idToSearch);

int main() {
   storeType store;
   loadStore("file10.txt", store);
   quickSort(store.list, 0, store.list.size() - 1);
   store.printStore();
   testSearch(store);
   return 0;
}

void loadStore(string filename, storeType &store) {
   ifstream in(filename, ios::in);
   int id, inv;
   while (in >> id >> inv) {
      store.list.push_back(item(id, inv));
   }
}

void quickSort(vector<item> &list, int first, int last) {
   int g = first, h = last;
   int midIndex;
   int dividingValue;

   midIndex = (first + last) / 2;
   dividingValue = list[midIndex].myId;
   do {
      while (list[g].myId < dividingValue)
         g++;
      while (list[h].myId > dividingValue)
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

void testSearch(const storeType &store) {
   int idToFind, invReturn, index;

   cout << "Testing search algorithm" << endl << endl;
   cout << "Enter Id value to search for (-1 to quit) ---> ";
   cin >> idToFind;
   while (idToFind >= 0) {
      index = bsearch(store, idToFind);
      //	index = bsearch (store, idToFind, 0, store.number-1); recursive
      // version call
      cout << "Id # " << idToFind;
      if (-1 == index)
         cout << "     No such part in stock" << endl;
      else
         cout << "     Inventory = " << store.list[index].myInv << endl;
      cout << endl << "Enter Id value to search for (-1 to quit) ---> ";
      cin >> idToFind;
   }
}

int bsearch(const storeType &store, int idToSearch)
/*	precondition:  store.list is sorted by the id field.  store.number
   stores how many items are in the array. data is stored in the array list from
   positions 0..store.number-1. postcondition:  if idToSearch exists in the
   array, the function returns the index position of the item, otherwise it
   returns -1.  */
{
   vector<item> list = store.list;
   int front = 0, middle = list.size() / 2, end = list.size() - 1;

   while (front >= 0 && end <= list.size() - 1) {
      int temp = list[middle].myId;
      if (idToSearch == temp)
         return middle;
      else if (idToSearch < temp)
         end = middle - 1, middle = end / 2;
      else
         front = middle + 1, middle = (end + front) / 2;
   }
}