#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

void magicSquares();
void reverseInt();
void lcm();
int isMagicSquare(int sum);

int main() {
    magicSquares();
//    reverseInt();
//    lcm();
    return 0;
}

void magicSquares() {
    int n;
    std::cout << "Enter integer to to go up to for magic squares: ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int squared = pow(i, 2), temp = isMagicSquare(squared);
        if (temp!=-1) {
            std::cout << i << " squared = " << squared << std::endl;
            std::cout << squared << " = sum of 1 to " << temp << std::endl;
        }
    }
}

int isMagicSquare (int sum) {
    int temp = 0, increment = 1;
    while (temp <= sum) {
        temp+=increment;
        if (temp == sum)
            return increment;
        increment++;
    }
    return -1;
}

void reverseInt() {
    std::string input;
    int output;
    std::cout << "Input an integer to be reversed: ";
    std::cin >> input;
    std::reverse(input.begin(), input.end());
    output = std::stoi(input);
    std::cout << output;
}

void lcm() {
    int n1, n2, max;

    std::cout << "Enter two numbers: ";
    std::cin >> n1 >> n2;

    max = (n1 > n2) ? n1 : n2;
    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            std::cout << "LCM = " << max;
            break;
        }
        else
            ++max;
    } while (true);
}