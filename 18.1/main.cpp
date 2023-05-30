#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
int live(vector<vector<int>> &mtrx, int x, int y);
void printmtrx(vector<vector<int>> &mtrx);

int main() {
    vector<vector<int>> mtrx(22, vector<int>(22, 0));
    ifstream in("life100.txt", ios::in);
    int x, y;
    while (in >> x >> y)
        mtrx[x][y] = 1;
    cout << "\n";
    for (int i = 0; i < 5; i++) {
        vector<vector<int>> copy(mtrx);
        for (int row = 1; row <= 20; row++) {
            for (int col = 1; col <= 20; col++) {
                int neighbors = live(mtrx, row, col);
                if (neighbors == 3)
                    copy[row][col] = 1;
                if (neighbors <= 1 || neighbors >= 4)
                {
                    copy[row][col] = 0;
                }
            }
        }
        mtrx = copy;
    }
    printmtrx(mtrx);
    return 0;
}

int live(vector<vector<int>> &mtrx, int x, int y) {
    int neighbors = 0;
    for (int row = x-1; row <= x+1; row++) {
        for (int col = y-1; col <= y+1; col++) {
            if (!(row == x && col == y) && mtrx[row][col] == 1)
                neighbors++;
        }
    }
    return neighbors;
}

void printmtrx(vector<vector<int>> &mtrx) {
    cout << "    12345678901234567890" << endl;
    for (int row = 1; row <= 20; row++) {
        cout << setw(2) << row << "  ";
        for (int col = 1; col <= 20; col++) {
            if (mtrx[row][col] == 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}



