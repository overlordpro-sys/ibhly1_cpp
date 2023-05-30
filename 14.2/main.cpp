#include <iostream>
#include <fstream>
#include <iomanip>
int main() {
    std::ifstream in("numbers.txt", std::ios::in);
    std::string input;
    int sum = 0, i = 0;
    while (std::getline(in, input))
    {
        i++;
        sum+=stoi(input);
    }
    std::cout << "Sum: " << sum << "\t Numbers: " << i << "\n Average: " << std::fixed << std::setprecision(2) << (double)sum/i;
}
