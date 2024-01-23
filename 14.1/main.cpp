#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
   std::ifstream in("squeeze.txt", std::ios::in);
   std::ofstream out("squeezeout.txt", std::ios::out);

   char temp;
   std::string rest = "";
   int spaces = 0;
   while (in.get(temp)) {
      if (temp == ' ')
         spaces++;
      else {
         rest += temp;
      }
      if (temp == '\n') {
         out << std::setw(2) << spaces << "  " << rest;
         spaces = 0;
         rest = "";
      }
   }
   out << std::setw(2) << spaces << "  " << rest;
}
