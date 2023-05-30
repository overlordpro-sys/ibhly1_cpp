#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void constructorTest() {
    string word1, word2("Hello world\0"), word3("Hello world\n");
    cout << word1 << word2 << word3;
}

void assignmentTest() {
    string word1 = "Hello world\0";
    string word2 = word1;
    // doesn't work?
//    string word3 = 't';
}

void accessTest() {
    string word1 = "test String \n lol";
    int len = word1.length();
    int index = word1.find("\n");
    int index2 = word1.find('l');
    string word2 = word1.substr(0, 3);
    cout << word1 << endl << len << endl << index << endl << index2 << endl << word2;
}

void indexingTest() {
    string word1 = "lalalalallala";
    for (int i = 0; i < word1.length(); i++) {
        word1[i] -= 32;
    }
    cout << word1;
}

void modifierTest() {
    string word1 = "part1", word2 = "part2";
    word1+=word2;
    word1+='l';
    cout << word1;
}

void getlineTest() {
    string word1;
    getline(cin, word1);
    cout << word1;
}

void comparisonTest() {
    string word1 = "Acb", word2 = "Abc";
    cout << (word1 > word2);
}

void selectionSort (vector<string> &list)
{
    int temp;
    for (int j = 0; j < list.size() - 1; ++j) {
        string min = list.at(j);
        temp = j;
        for (int i = j+1; i < list.size(); ++i) {
            if (min > list.at(i)) {
                min = list.at(i);
                temp = i;
            }
        }
        swap(list.at(j), list.at(temp));
    }
}

void tester() {
    ifstream in("test.txt", ios::in);
    vector<string> list;
    string line;
    while (getline(in, line)) {
//        cout << line << "\n";
        list.push_back(line);
    }
    selectionSort(list);
    for (auto iter = list.begin(); iter!=list.end(); iter++) {
        cout << *iter << "\n";
    }
}

int main() {
    tester();
    return 0;
}


