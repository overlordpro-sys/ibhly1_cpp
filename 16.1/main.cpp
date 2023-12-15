#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
   ifstream in("numbers.txt", std::ios::in);
   string input;
   map<int, int> map;
   while (getline(in, input))
      map[stoi(input)]++;
   int sum = 0, count = 0, mode, modeNum = 0;
   for (auto iter = map.begin(); iter != map.end(); iter++) {
      sum += (iter->first) * (iter->second);
      count += iter->second;
   }
   double mean = (double)sum / count, stdev = 0;
   for (auto iter = map.begin(); iter != map.end(); iter++) {
      stdev += pow(iter->first - mean, 2) * iter->second;
      if (iter->second > modeNum) {
         mode = iter->first;
         modeNum = iter->second;
      }
   }
   stdev /= (count - 1);
   stdev = sqrt(stdev);
   printf("Average: %f | Standard Dev: %f | Mode: %d", mean, stdev, mode);

   return 0;
}
