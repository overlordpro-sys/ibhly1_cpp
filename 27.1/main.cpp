#include <iostream>
#include <vector>

enum suitType{hearts, clubs, diamonds, spades, badsuit};
enum valueType{ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, badvalue};
using namespace std;
ostream& operator<<(ostream&Out, suitType suit) {
    switch (suit){
        case hearts: Out << "hearts"; break;
        case clubs: Out << "clubs"; break;
        case diamonds: Out << "diamonds"; break;
        case spades: Out << "spades"; break;
        case badsuit: Out << "badsuit"; break;
    }
    return Out;
}

ostream& operator<<(ostream&Out, valueType suit) {
    switch (suit){
        case ace: Out << "ace"; break;
        case two: Out << "two"; break;
        case three: Out << "three"; break;
        case four: Out << "four"; break;
        case five: Out << "five"; break;
        case six: Out << "six"; break;
        case seven: Out << "seven"; break;
        case eight: Out << "eight"; break;
        case nine: Out << "nine"; break;
        case ten: Out << "ten"; break;
        case jack: Out << "jack"; break;
        case queen: Out << "queen"; break;
        case king: Out << "king"; break;
        case badvalue: Out << "badvalue"; break;

    }
    return Out;
}

istream& operator>> (istream&In, suitType&suit) {
    string temp;
    In >> temp;
    for (int pos=0; pos<temp.length(); pos++)
        if (('A'<=temp[pos]) && (temp[pos]<='Z'))
            temp[pos] = temp[pos] + 32;  // make it all lowercase
    if (temp == "hearts")
        suit = hearts;
    else if (temp == "clubs")
        suit = clubs;
    else if (temp == "diamonds")
        suit = diamonds;
    else if (temp == "spades")
        suit = spades;
    else
        suit = badsuit;
    return In;
}

istream& operator>> (istream&In, valueType&value) {
    string temp;
    In >> temp;
    for (int pos=0; pos<temp.length(); pos++)
        if (('A'<=temp[pos]) && (temp[pos]<='Z'))
            temp[pos] = temp[pos] + 32;  // make it all lowercase
    if (temp == "ace")
        value = ace;
    else if (temp == "two")
        value = two;
    else if (temp == "three")
        value = three;
    else if (temp == "four")
        value = four;
    else if (temp == "five")
        value = five;
    else if (temp == "six")
        value = six;
    else if (temp == "seven")
        value = seven;
    else if (temp == "eight")
        value = eight;
    else if (temp == "nine")
        value = nine;
    else if (temp == "ten")
        value = ten;
    else if (temp == "jack")
        value = jack;
    else if (temp == "queen")
        value = queen;
    else if (temp == "king")
        value = king;
    else
        value = badvalue;
    return In;
}

int main() {
    vector<suitType> suit;
    vector<valueType> value;
    for (int i = 0; i < 13; i++) {
        suitType temp;
        valueType temp2;
        cout << "\nSuit: ";
        cin >> temp;
        cout << "\nValue: ";
        cin >> temp2;
        suit.push_back(temp);
        value.push_back(temp2);
    }
    for (int i = 0; i < 13; i++) {
        cout << value[i] << " of " << suit[i] << endl;
    }

}
