#include <iostream>
#include <fstream>
#include <iomanip>
int main() {
    std::ifstream in("C:\\Users\\256676\\Documents\\C++ ICT\\ibhly1-cpp\\14.1\\squeeze.txt", std::ios::in);
    std::ofstream out("C:\\Users\\256676\\Documents\\C++ ICT\\ibhly1-cpp\\14.1\\squeezeout.txt", std::ios::out);

    char temp;
    std::string rest ="";
    int spaces = 0;
    while(in.get(temp)) {
        if (temp == ' ')
            spaces++;
        else {
            rest += temp;
        }
        if (temp == '\n') {
            out << std::setw(2) << spaces << "  " << rest;
            spaces = 0;
            rest = "";
        }
    }
    out << std::setw(2) << spaces << "  " << rest;
}
