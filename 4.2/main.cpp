#include <iostream>
#include <cmath>

using namespace std;
int main() {
    double a, b, c, posRoot, negRoot;
    cout << "a coefficient: "; cin >> a;
    cout << "b coefficient: "; cin >> b;
    cout << "c coefficient: "; cin >> c;

    posRoot = (-b+ sqrt(b*b - 4*a*c))/(2*a);
    negRoot = (-b- sqrt(b*b - 4*a*c))/(2*a);

    cout << "positive root: " << posRoot << endl;
    cout << "negative root: " << negRoot << endl;
    return 0;
}