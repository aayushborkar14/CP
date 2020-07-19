#include<iostream>
#include<cmath>

using namespace std;

long int sumOfSquare(int n) {
    long int sum{};
    sum = ((n*(n+1)*((2*n)+1))/6);      //there's a formula for this, 
                                        //I recommend to read Elementary number Theory by D.M. Burton
    return sum;
}

long int squareOfSum(int n) {
    long int square{};
    square = pow(((n*(n+1))/2), 2);     //there's a formula for this too
    return square;
}

int main() {
    long int sum{squareOfSum(100) - sumOfSquare(100)};
    cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is " << sum;
}
