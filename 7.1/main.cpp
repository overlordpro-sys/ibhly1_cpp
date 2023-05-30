#include <iostream>
void get2Values(int &i1, int &i2);
void get2Values(double &d1, double &d2);
void print2Values(const int i1, const int i2);
void print2Values(const double d1, const double d2);
template <class dataType>
void print2Values(const dataType d1, const dataType d2);
template <class dataType>
void swap(dataType &i1, dataType &i2);

int main() {
    double d1, d2;
    int i1, i2;
    get2Values(i1, i2);
    get2Values(d1, d2);
    print2Values(i1, i2);
    print2Values(d1, d2);
    swap(i1, i2);
    swap(d1, d2);
    print2Values(i1, i2);
    print2Values(d1, d2);
    return 0;
}

void get2Values(int &i1, int &i2) {
    std::cout << "Enter two integers: ";
    std::cin >> i1 >> i2;
}

void get2Values(double &d1, double &d2) {
    std::cout << "Enter two doubles: ";
    std::cin >> d1 >> d2;
}

void print2Values(const int i1, const int i2) {
    std::cout << "The two integers are: " << i1 << " and " << i2 << std::endl;
}

void print2Values(const double d1, const double d2) {
    std::cout << "The two doubles are: " << d1 << " and " << d2 << std::endl;
}

template <class dataType>
void print2Values(const dataType d1, const dataType d2) {
    std::cout << "The two values are: " << d1 << " and " << d2 << std::endl;
}

template <class dataType>
void swap(dataType &i1, dataType &i2){
    dataType temp = i1;
    i1 = i2;
    i2 = temp;
};