#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct item
{
    int myId, myInv;
    item(int id, int inv) : myId(id), myInv(inv){}
};

struct storeType {
    vector<item> list;
    int count = 1;
    void printStore() {
        for (auto it = list.begin(); it != list.end(); it++) {
            printf("%-4dId: %-6d  Inv %-4d\n", count , it->myId, it->myInv);
            if (count % 10 == 0)
                cout << "\n";
            count++;
        }
    }
};

void loadStore(string filename, storeType &store);
void quickSort (vector<item> &list, int first, int last);

int main()
{
    storeType store;
    loadStore("file10.txt", store);
    quickSort(store.list, 0, store.list.size()-1);
    store.printStore();
    return 0;
}

void loadStore(string filename, storeType &store) {
    ifstream in(filename, ios::in);
    int id, inv;
    while (in >> id >> inv) {
        store.list.push_back(item(id,inv));
    }
}

void quickSort (vector<item> &list, int first, int last)
{
    int g = first, h = last;
    int midIndex;
    int dividingValue;

    midIndex = (first + last) / 2;
    dividingValue = list[midIndex].myId;
    do
    {
        while (list[g].myId < dividingValue) g++;
        while (list[h].myId > dividingValue) h--;
        if (g <= h)
        {
            swap(list[g], list[h]);
            g++;
            h--;
        }
    }
    while (h > g);
    if (h > first) quickSort (list,first,h);
    if (g < last) quickSort (list,g,last);
}