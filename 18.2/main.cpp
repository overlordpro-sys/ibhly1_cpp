#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
bool move(vector<vector<int>> &board, int &count, int &x, int &y);
void printmtrx(vector<vector<int>> &mtrx);
int main() {
    vector<vector<int>> board(10, vector<int>(9, 0));
    bool done = false;
    srand((unsigned) time(0));

    int x = 1, y = 1, count = 2;
    board[1][1] = 1;
    while (!move(board, count, y, x));
    printmtrx(board);
    cout << "\n" << "Number of moves: " << count-1;
    cout << "Curr pos: " << x << y;
    return 0;
}

// there are some random conditions where it no work
bool move(vector<vector<int>> &board, int &count, int &x, int &y) {
    vector<int> hor( {1 , 2, 2, 1, -1, -2, -2, -1});
    vector<int> vert({-2,-1, 1, 2,  2,  1, -1, -2});
    while (hor.size() != 0) {
        int random = rand() % hor.size(), newX = x + hor.at(random), newY = y + vert.at(random);
        if (newX >= 1 && newX <= 8 && newY >= 1 && newY <= 8 && board[newX][newY] == 0) {
            board[newX][newY] = count;
            count++;
            x = newX;
            y = newY;
            return false;
        }
        hor.erase(hor.begin() + random);
        vert.erase(vert.begin() + random);
    }
    if (hor.size() == 0) {
        return true;
    }
    return false;
}

void printmtrx(vector<vector<int>> &mtrx) {
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
}





