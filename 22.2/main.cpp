#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void fillArray(vector<int> &vec, int quantity, int largest);
void screenOutput(vector<int> vec);
void selectionSort (vector<int> &list);
vector<int> merge (vector<int> &A, vector<int> tempB);
void mergeSort(vector<int> &vec);
int main() {
    srand((unsigned) time(0));
//    vector<int> one, two, three;
//    fillArray(one, 20, 100);
//    fillArray(two, 20, 90);
//    selectionSort(one);
//    selectionSort(two);
//    three = merge(one, two);
//    screenOutput(three);

    vector<int> vec({2,1, 5});
    fillArray(vec, 20, 100);
    mergeSort(vec);
    screenOutput(vec);
    return 0;
}

void fillArray(vector<int> &vec, int quantity, int largest) {
    for (int i = 1; i <= quantity; i++)
        vec.push_back(rand() % largest);
}

void screenOutput(vector<int> vec) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if ((it - vec.begin()) % 20 == 0)
            cout << "\n";
        cout << *it << " ";
    }
}

void selectionSort (vector<int> &list)
{
    int temp;
    for (int j = 0; j < list.size() - 1; ++j) {
        int min = list.at(j);
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

vector<int> merge (vector<int> &A, vector<int> tempB) {
    vector<int> tempA(A), final;
    while (tempA.size() != 0 || tempB.size() != 0) {
        if (tempB.size() == 0) {
            final.push_back(tempA[0]);
            tempA.erase(tempA.begin());
        } else if (tempA.size() == 0) {
            final.push_back(tempB[0]);
            tempB.erase(tempB.begin());
        } else {
            if (tempA[0] < tempB[0]) {
                final.push_back(tempA[0]);
                tempA.erase(tempA.begin());
            } else {
                final.push_back(tempB[0]);
                tempB.erase(tempB.begin());
            }
        }
    }
    return final;
}

void mergeSort(vector<int> &vec) {
    if (vec.size() > 1) {
        vector<int> first(vec.begin(), vec.begin() + vec.size() /2),
                    second(vec.begin() + vec.size() / 2, vec.end());
        mergeSort(first);
        mergeSort(second);
        vec = merge(first, second);
    }
}



