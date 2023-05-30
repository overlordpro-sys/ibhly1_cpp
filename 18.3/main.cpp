#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
bool move(vector<vector<int>> &board, vector<vector<int>> &access, int &row, int &col);
void printMtrx(vector<vector<int>> &mtrx);
void loadMtrx(vector<vector<int>> &mtrx);
void updateAccess(vector<vector<int>> &access, int &row, int &col);


int main() {
    vector<vector<int>> board(9, vector<int>(9, 0));
    vector<vector<int>> access(9, vector<int>(9, 0));
    srand((unsigned) time(0));

    loadMtrx(access);
    int test = 0;
    int row = 1, col = 1, count = 2;
    board[1][1] = 1;
    printMtrx(access);
    while (!move(board, access, row, col)) {
        board[row][col] = count;
        count++;
        printMtrx(access);
    }
    printMtrx(board);

    cout << "\n" << "Number of moves: " << count-1;
    return 0;
}

void loadMtrx(vector<vector<int>> &mtrx) {
    ifstream stream("access.txt", ios::in);
    for (int row = 1; row <= 8; row++){
        for (int col = 1; col <= 8; col++){
            int temp;
            stream >> temp;
            mtrx[row][col] = temp;
        }
    }
}

void updateAccess(vector<vector<int>> &access, int &row, int &col) {
    vector<int> colMove({1 , 2, 2, 1, -1, -2, -2, -1});
    vector<int> rowMove({-2, -1, 1, 2, 2, 1, -1, -2});
    for (int i = 0; i < colMove.size(); i++) {
        int newRow = row + rowMove[i], newCol = col + colMove[i];
        if (newRow >= 1 && newRow <= 8 && newCol >= 1 && newCol <= 8)
            access[newRow][newCol]--;
    }
}

bool move(vector<vector<int>> &board, vector<vector<int>> &access, int &row, int &col) {
    int minIndex = -1, minAccess = 10;
    vector<int> colMove({1 , 2, 2, 1, -1, -2, -2, -1});
    vector<int> rowMove({-2, -1, 1, 2, 2, 1, -1, -2});
    for (int i = 0; i < rowMove.size(); i++) {
        int newRow = row + rowMove[i], newCol = col + colMove[i];
        if (newRow >= 1 && newRow <= 8 && newCol >= 1 && newCol <= 8 && board[newRow][newCol] == 0 && access[newRow][newCol] < minAccess) {
            minIndex = i;
            minAccess = access[newRow][newCol];
        }
    }
    if (minIndex == -1)
        return true;
    row += rowMove[minIndex];
    col += colMove[minIndex];
    updateAccess(access, row, col);
    return false;
}

void printMtrx(vector<vector<int>> &mtrx) {
    cout << "   ";
    for (int i = 1; i <= 8; i++)
        cout << setw(2) << i << " ";
    cout << "\n";
    for (int row = 1; row <= 8; row++) {
        cout << setw(2) << row << " ";
        for (int col = 1; col <= 8; col++) {
            cout << setw(2) << mtrx[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}





