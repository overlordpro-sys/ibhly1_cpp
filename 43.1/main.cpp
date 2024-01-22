#include "linkedlist.cpp"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <random>
using namespace std;

struct product {
   int id, inv;
   product(int tempId, int tempInv);
};

product::product(int tempId, int tempInv) : id(tempId), inv(tempInv) {}

void loadList(string filename, vector<linkedlist<product> *> &productList);
void printHashList(vector<linkedlist<product> *> productList);
void printHashListStats(vector<linkedlist<product> *> productList);
double getPercentNulls(vector<linkedlist<product> *> productList);
int hashCode(int id);

int hashCodeOpt(int id, double scalar1, double scalar2) {
   ostringstream ss;
   ss << std::setw(5) << std::setfill('0') << id * 600;
   string num = ss.str();

   int one = stoi(num.substr(0, 2));
   int two = stoi(num.substr(1));
   double temp = hypot(one, two) * scalar1;
   double temp2 = pow(temp, scalar2);

   return static_cast<int>(fmod(temp2, 599));
}

void loadListOpt(string filename, vector<linkedlist<product> *> &productList,
                 double scalar1, double scalar2) {
   ifstream in(filename, ios::in);
   int id, inv;
   while (in >> id >> inv) {
      int hash = hashCodeOpt(id, scalar1, scalar2);
      if (productList[hash] == nullptr) {
         productList[hash] = new linkedlist<product>();
      }
      productList[hash]->addLast(product(id, inv));
   }
}

void doRNG(string filename) {
   std::random_device rd;  // Obtain a random number from hardware
   std::mt19937 eng(rd()); // Seed the generator

   // Define the range for doubles
   std::uniform_real_distribution<> distr1(0.0, 200.0);
   std::uniform_real_distribution<> distr2(0.0, 8.0);
   double randomDouble1 = distr1(eng);
   double randomDouble2 = distr2(eng);
   double percent = 100;
   do {
      vector<linkedlist<product> *> productList(600);
      randomDouble1 = distr1(eng);
      randomDouble2 = distr2(eng);
      loadListOpt(filename, productList, randomDouble1, randomDouble2);
      percent = getPercentNulls(productList);
      cout << "Percent: " << percent << "\tScalar 1: " << setprecision(20)
           << randomDouble1 << "\tScalar 2: " << setprecision(20)
           << randomDouble2 << endl;
   } while (percent > 47.9);
}

int main() {
   // vector<linkedlist<product> *> productList(
   //     600); // Change to vector of pointers
   string filename = "FILE400.txt";

   // doRNG(filename);
   vector<linkedlist<product> *> productList(600);
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
   ostringstream ss;
   ss << std::setw(5) << std::setfill('0') << id * 600;
   string num = ss.str();

   int one = stoi(num.substr(0, 2));
   int two = stoi(num.substr(1));
   double temp = hypot(one, two) * 83.331283790763919228;
   double temp2 = pow(temp, 6.6013252137033919809);

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

int getLongestLength(vector<linkedlist<product> *> productList) {
   int max = 0;
   for (linkedlist<product> *products : productList) {
      if (products != nullptr) {
         int temp = products->length();
         if (temp > max) {
            max = temp;
         }
      }
   }
   return max;
}

double getAverageLength(vector<linkedlist<product> *> productList) {
   double sum = 0;
   for (linkedlist<product> *products : productList) {
      if (products != nullptr) {
         sum += products->length();
      }
   }
   return sum / 600;
}

double getPercentNulls(vector<linkedlist<product> *> productList) {
   double nulls = 0;
   for (linkedlist<product> *products : productList) {
      if (products == nullptr) {
         nulls++;
      }
   }
   return nulls / 600 * 100;
}

void printHashListStats(vector<linkedlist<product> *> productList) {
   cout << "% of NULL pointers: " << getPercentNulls(productList)
        << "\nAverage length of linked lists: " << getAverageLength(productList)
        << "\nLongest length of linked list: " << getLongestLength(productList)
        << endl;
}
