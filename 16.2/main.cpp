#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <cmath>
using namespace std;

void compact(vector<int> &list);

int main() {
    ifstream in("numbers.txt", std::ios::in);
    string input;
    vector<int> vec;
    vector<int>::iterator itr;
    while (std::getline(in, input))
        vec.push_back(stoi(input));
    cout << "Before: ";
    for (itr = vec.begin(); itr != vec.end(); itr++) {
        if (itr==vec.end()-1)
            cout << *itr;
        else
            cout << *itr << ", ";
    }
    compact(vec);
    cout << "\nAfter: ";
    for (itr = vec.begin(); itr != vec.end(); itr++) {
        if (itr==vec.end()-1)
            cout << *itr;
        else
            cout << *itr << ", ";
    }
    return 0;
}

void compact(vector<int> &list) {
    vector<int>::iterator itr = list.begin();
    while (itr!=list.end()) {
        if (*itr == 0)
            itr = list.erase(itr);
        else
            itr++;
    }
}

