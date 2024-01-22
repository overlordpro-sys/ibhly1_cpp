#include "linkedlist.cpp"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct product {
   int id, inv;
   product(int tempId, int tempInv);
};

product::product(int tempId, int tempInv) : id(tempId), inv(tempInv) {}

void loadList(string filename, vector<linkedlist<product> *> &productList);
void printHashList(vector<linkedlist<product> *> productList);
void printHashListStats(vector<linkedlist<product> *> productList);
int hashCode(int id);

int main() {
   vector<linkedlist<product> *> productList(
       600); // Change to vector of pointers
   string filename = "FILE400.txt";
   loadList(filename, productList);
   printHashList(productList);
   printHashListStats(productList);
   return 0;
}

void loadList(string filename, vector<linkedlist<product> *> &productList) {
   ifstream in(filename, ios::in);
   int id, inv;
   while (in >> id >> inv) {
      int hash = hashCode(id);
      if (productList[hash] == nullptr) {
         productList[hash] = new linkedlist<product>();
      }
      productList[hash]->addLast(product(id, inv));
   }
}

int hashCode(int id) {
   ostringstream oss;
   oss << fixed << setprecision(5) << setw(5) << setfill('0') << id;
   string str = oss.str();
   int one = stoi(str.substr(0, 2));
   int two = stoi(str.substr(1));
   double temp = hypot(one, two) * 251.04229273894168;
   double temp2 = pow(temp, 7.778787910153129);
   return static_cast<int>(fmod(temp2, 599));
}

void printHashList(vector<linkedlist<product> *> productList) {
   int i = 0;
   for (linkedlist<product> *products : productList) {
      cout << i << ": ";
      if (products != nullptr) {
         listNode<product> *temp = products->getFirst();
         while (temp != nullptr) {
            product prod = temp->item;
            cout << "Id: " << prod.id << "/Inv: " << prod.inv << "\t";
            temp = temp->next;
         }
      }
      i++;
      cout << "\n";
   }
}

int getLongestList(vector<linkedlist<product> *> productList) {
   int max = 0;
   for (linkedlist<product> *products : productList) {
      int temp = products->length();
      cout << temp;
      // TODO Counting incorrect MUST FIX
      if (temp > max) {
         max = temp;
      }
   }
   return max;
}

int getNumNulls(vector<linkedlist<product> *> productList) {
   int nulls = 0;
   for (linkedlist<product> *products : productList) {
      if (products == nullptr) {
         nulls++;
      }
   }
   return nulls;
}

void printHashListStats(vector<linkedlist<product> *> productList) {
   cout << "Longest List: " << getLongestList(productList)
        << "\nMax Nulls: " << getNumNulls(productList) << endl;
}
