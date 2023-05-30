#include <iostream>
#include <cmath>
#include <iomanip>

void promptUser(double &loanAmount, double &loanLength, double &interestRateLow, double &interestRateHigh);
double calculateMonthlyPayment(double loanAmount, double loanLength, double interestRate);
int main() {
    double loanAmount, loanLength, interestRateLow, interestRateHigh;
    promptUser(loanAmount, loanLength, interestRateLow, interestRateHigh);

    while (interestRateLow <= interestRateHigh) {
        std::cout << "Interest Rate: " << interestRateLow << "\tMonthly payment: " << calculateMonthlyPayment(loanAmount, loanLength, interestRateLow) << std::endl;
        interestRateLow += 0.0025;
    }
    return 0;
}

void promptUser(double &loanAmount, double &loanLength, double &interestRateLow, double &interestRateHigh) {
    std::cout << "Enter the loan amount: ";
    std::cin >> loanAmount;
    std::cout << "Enter the loan length in years: ";
    std::cin >> loanLength;
    std::cout << "Enter the interest rate low in decimal ex. .01: ";
    std::cin >> interestRateLow;
    std::cout << "Enter the interest rate high in decimal ex. .01: ";
    std::cin >> interestRateHigh;
}

double calculateMonthlyPayment(double loanAmount, double loanLength, double interestRate) {
    double monthlyInterestRate = interestRate / 12.0;
    double c = pow(1 + monthlyInterestRate, loanLength*12.0);
    return (loanAmount * monthlyInterestRate * c) / (c-1);
}
