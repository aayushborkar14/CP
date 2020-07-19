#include <iostream>

using namespace std;

int euclid_gcd(int num1, int num2) {
    int dividend = num1 >= num2 ? num1 : num2;
    int divisor = num1 <= num2 ? num1 : num2;
    while (divisor != 0) {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int main() {
    int num1{ }, num2{ };
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Their gcd is " << euclid_gcd(num1, num2);
}
