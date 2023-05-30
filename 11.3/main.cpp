#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>

void addDice(int &player, int &other1,int &other2, bool &forfeit, bool &done, int dice);


using std::cout, std::endl, std::cin, std::string, std::vector, std::to_string, std::setw;

int main() {
    vector<string> in_list;
    vector<string> out_list;
    for (char game = '1'; game-'0' <= 5; game++) {
        string scanner = "";
        int currPlayer = 1, aPos = 0, bPos = 0, cPos = 0;
        bool aFF = false, bFF = false, cFF = false, done = false;
        string input = "";
        string output = "";

        cout << "Input the dice rolls for game " << game << " separated by a comma and terminating with 0: ";
        cin >> scanner;
        input += "Line #";
        input += game;
        input += ": " + scanner;
        in_list.push_back(input);
        for (int i = 0; i < scanner.length() && !done; i++) {
            if (isdigit(scanner.at(i))) {
                int diceNum = int(scanner.at(i)-'0');
                if (diceNum > 0 && diceNum <= 8) {
                    switch (currPlayer) {
                        case 1:
                            if (aFF)
                                i--;
                            addDice(aPos, bPos, cPos, aFF, done, diceNum);
                            break;
                        case 2:
                            if (bFF)
                                i--;
                            addDice(bPos, cPos, aPos, bFF, done, diceNum);
                            break;
                        case 3:
                            if (cFF)
                                i--;
                            addDice(cPos, aPos, bPos, cFF, done, diceNum);
                            break;
                    }
                    if (currPlayer < 3)
                        currPlayer++;
                    else
                        currPlayer = 1;
                }
            }
        }
        output+="Output #" + to_string(game-'0') + ": A-";
        if (aPos >= 30) {
            output+="END";
        } else if (aPos == 0) {
            output+="START";
        } else {
            output+= to_string(aPos);
        }
        output+=", B-";
        if (bPos >= 30) {
            output+="END";
        } else if (bPos == 0) {
            output+="START";
        } else {
            output+= to_string(bPos);
        }
        output+=", C-";
        if (cPos >= 30) {
            output+="END";
        } else if (cPos == 0) {
            output+="START";
        } else {
            output+= to_string(cPos);
        }
        out_list.push_back(output);
    }

    for (int i = 0; i < in_list.size(); i++) {
        cout << setw(50) << std::left << in_list.at(i) << setw(40) << std::left << out_list.at(i) << "\n";
    }
    return 0;
}

void addDice(int &player,int &other1, int &other2, bool &forfeit, bool &done, int dice) {
    if (forfeit) {
        forfeit = false;
        return;
    }
    if (dice == 4)
        dice=-4;
    if (dice == 6) {
        dice = 0;
        forfeit = true;
    }
    player += dice;
    if (player >= 30)
        done = true;
    if (player == other1)
        other1 = 0;
    if (player == other2)
        other2 = 0;
}


