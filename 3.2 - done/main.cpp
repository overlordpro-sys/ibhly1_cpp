#include <iostream>
#include <string>
using namespace std;
int main() {
   string input, firstHalf, secondHalf, make, model;
   int sum = 0, letterNum;
   cout << "Car Make: ";
   cin >> make;
   cout << "\nCar Model: ";
   cin >> model;
   cout << "\nInput a license plate: ";
   cin >> input;
   firstHalf = input.substr(0, 3);
   secondHalf = input.substr(3, 3);
   string::iterator iterator;
   for (iterator = firstHalf.begin(); iterator != firstHalf.end(); iterator++)
      sum += *iterator;
   sum += stoi(secondHalf);
   letterNum = sum % 26;
   cout << "Make = " << make << endl;
   cout << "Model = " << model << endl;
   cout << input << " = " << char(65 + letterNum) << sum << endl;
   return 0;
}
