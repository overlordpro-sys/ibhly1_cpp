#include <iostream>
#include <limits.h>
#include <float.h>
int main() {
    std::cout << "2 + 3 = " << 2+3 << std::endl;
    std::cout << "17 % 4 = " << 17%4 << std::endl;
    std::cout << "4 + 9 = " << 4 + 9 << std::endl;
    std::cout << "46 / 7 = " << 46 / 7 << std::endl;
    std::cout << "46 % 7 = " << 46 % 7 << std::endl;
    std::cout << "2 * 3.0 = " << 2 * 3.0 << std::endl;
    std::cout << "float (25) / 4 = " << float (25) / 4 << std::endl;
    std::cout << "int (7.75) + 2 = " << int (7.75) + 2 << std::endl;
    std::cout << "int ('P') = " << int ('P') << std::endl;
    std::cout << "char (105) = " << char (105) << std::endl;

    std::cout << "The largest 2-byte integer = " << INT_MAX << std::endl;
    std::cout << "smallest 2-byte integer = " << INT_MIN << std::endl;
    std::cout << "largest unsigned (positives only) 2-byte integer = " << UINT_MAX << std::endl;
    std::cout << "largest 4-byte integer = " << LONG_MAX << std::endl;
    std::cout << "smallest 4-byte integer = " << LONG_MIN << std::endl;
    std::cout << "largest unsigned (positives only) 4-byte integer = " << ULONG_MAX << std::endl;

    std::cout << "largest 4-byte float = " << FLT_MAX << std::endl;
    std::cout << "smallest 4-byte float = " << FLT_MIN << std::endl;
    std::cout << "largest 8-byte float = " << DBL_MAX << std::endl;
    std::cout << "smallest 8-byte float = " << DBL_MIN << std::endl;
    return 0;
}
