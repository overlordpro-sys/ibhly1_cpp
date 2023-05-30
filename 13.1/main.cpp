#include <iostream>
int recurFib(int n);
int iterFib(int n);
int mult(int a, int b);
using namespace std;
int main() {
    cout << recurFib(8) << " " << iterFib(8) << "\n";
    cout << mult(0,4) << " " << mult(3,1) << " " << mult(7,8) << " " << mult(5,0);
}

int recurFib(int n) {
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    return recurFib(n-2) + recurFib(n-1);
}

int iterFib(int n) {
    int x = 0, y = 1, z = 1;
    for (int i = 0; i < n; i++) {
        x = y;
        y = z;
        z = x + y;
    }
    return x;
}

int mult(int a, int b) {
    if (b==0)
        return 0;
    if (b == 1)
        return a;
    return a + mult(a, b-1);
}
