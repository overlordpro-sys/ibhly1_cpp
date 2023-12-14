#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
enum cellType {black, white};
void printMtrx(vector<vector<cellType>> &mtrx);
void deleteCell(vector<vector<cellType>> &mtrx, int row, int col);

int main() {
    vector<vector<cellType>> grid(22, vector<cellType>(22, white));

    // init grid
    ifstream in("digital.txt", ios::in);
    int x, y;
    while (in >> x >> y)
        grid[x][y] = black;
    deleteCell(grid, 3, 4);
    printMtrx(grid);
    return 0;
}

void printMtrx(vector<vector<cellType>> &mtrx) {
    cout << "   ";
    for (int i = 1; i <= 20; i++)
        cout << setw(2) << i;
    cout << "\n";
    for (int row = 1; row <= 20; row++) {
        cout << setw(2) << row << " ";
        for (int col = 1; col <= 20; col++) {
            if (mtrx[row][col] == 1)
                cout << setw(2) << " ";
            else
                cout << setw(2) << "*";
        }
        cout << "\n";
    }
    cout << "\n";
}

void deleteCell(vector<vector<cellType>> &mtrx, int row, int col) {
    if (row >= 1 && row <= 20 && col <= 20 && col >= 1 && mtrx[row][col] == black) {
        mtrx[row][col] = white;
        deleteCell(mtrx, row-1, col);
        deleteCell(mtrx, row+1, col);
        deleteCell(mtrx, row, col-1);
        deleteCell(mtrx, row, col+1);
    }
}