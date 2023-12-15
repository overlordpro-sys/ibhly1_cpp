#include <iomanip>;
#include <iostream>

void table();
void stars();
using std::cout, std::endl, std::cin, std::setw;

int main() {
   //    table();
   stars();
   return 0;
}

void table() {
   int rows, cols;
   cout << "Enter # of rows:";
   cin >> rows;
   cout << "Enter # of cols:";
   cin >> cols;
   cout << setw(5) << "";
   for (int i = 1; i <= cols; i++) {
      cout << setw(5) << i;
   }
   cout << "\n\n";
   for (int r = 1; r <= rows; r++) {
      cout << setw(5) << r;
      for (int c = 1; c <= cols; c++) {
         cout << setw(5) << r * c;
      }
      cout << "\n";
   }
}

void stars() {
   int lines, width;
   cout << "Enter desired number of lines:";
   cin >> lines;
   cout << '\n';
   width = lines * 2 - 1;

   for (int i = 1; i <= width; i += 2) {
      cout << setw((width - i) / 2) << "";
      for (int stars = 1; stars <= i; stars++) {
         cout << "*";
      }
      cout << setw((width - i) / 2) << "";
      cout << "\n";
   }
}