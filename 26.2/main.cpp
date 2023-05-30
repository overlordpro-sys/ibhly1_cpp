#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

bool compareGreater(pair<string,int> &a, pair<string,int> &b);
int main() {
    ifstream in("input.txt", std::ios::in);
    string input;
    map<string, int> map;
    int count = 0;
    string chars = "!,.";
    while (in >> input) {
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        for (char c : chars)
            input.erase(remove(input.begin(), input.end(), c), input.end());
        map[input]++;
        count++;
    }

    vector<pair<string,int>> temp;
    for (auto it : map) {
        temp.push_back(it);
    }
    sort(temp.begin(), temp.end(), compareGreater);

    cout << "Number of words used = " << temp.size() << endl;
    cout << "Total # of words = " << count << endl;
    for (int i = 1; i <= 30; i++) {
        printf("%-4d%-5d%-12s\n", i, temp[i].second, temp[i].first.c_str());
    }
    return 0;
}

bool compareGreater(pair<string,int> &a, pair<string, int> &b) {
    return a.second > b.second;
}


