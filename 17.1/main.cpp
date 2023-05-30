#include <iostream>
#include "dice.h"
int main() {
    dice die1(6), die2(6), die3(6);
    int roll1, roll2, roll3, count = 1;
    do {
        roll1 = die1.roll();
        roll2 = die2.roll();
        roll3 = die3.roll();
        std::cout << roll1 << " " << roll2 << " " << roll3 << " " << std::endl;
    }
    while (roll1 == roll2 || roll2 == roll3 || roll1 == roll3);
    std::cout << "Rolls: " << count;

    return 0;
}
