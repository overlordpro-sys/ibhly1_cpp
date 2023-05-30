#include <iostream>
#include <iomanip>
#include <vector>

using std::cout, std::endl, std::cin, std::string, std::vector, std::to_string, std::setw;

int main() {
    vector<string> in_list;
    vector<string> out_list;

    for (int game = 1; game <= 5; game++) {
        int aPos = 0, bPos = 0;
        bool doingA = true, done = false;
        string input = "";
        string output = "";
        input += ("Line #" + to_string(game) + ": ");
        char scanner = ' ';
        do {
            cout << "Game " + to_string(game) +":Input the dice rolls for each player scanner order one by one. Press enter after each roll. Input 0 when finished:";
            cin >> scanner;
            if (isdigit(scanner)) {
                int num = int(scanner - '0');
                if (num >= 0 && num <= 8) {
                    input+= to_string(num) + ",";
                    if (num == 4 || num == 6) {
                        num*=-1;
                    }
                    if (!done) {
                        if (doingA) {
                            aPos+=num;
                            if (aPos >= 40)
                                done=true;
                            if (aPos==bPos)
                                bPos=0;
                        } else {
                            bPos += num;
                            if (bPos >= 40)
                                done=true;
                            if (aPos == bPos)
                                aPos = 0;
                        }
                        doingA = !doingA;
                    }
                }
            }
        } while (scanner != '0');
        in_list.push_back(input);
        output+="Output #" + to_string(game) + ": A-";
        if (aPos >= 40) {
            output+="END";
        } else if (aPos == 0) {
            output+="START";
        } else {
            output+= to_string(aPos);
        }
        output+=", B-";
        if (bPos >= 40) {
            output+="END";
        } else if (bPos == 0) {
            output+="START";
        } else {
            output+= to_string(bPos);
        }
        out_list.push_back(output);
        input="";
        output="";
    }
    for (int i = 0; i < 5; i++) {
        cout << setw(50) << std::left << in_list.at(i) << setw(40) << std::left << out_list.at(i) << "\n";
    }
    return 0;
}
