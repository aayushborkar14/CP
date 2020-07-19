#include <iostream>

using namespace std;

bool checkDivisibility(int a) { 
    bool divisible = true;     //initialise to true
    for (int i=2; i<=20 && divisible; i++) {    //i goes from 2 to 20, loop runs until i<=20 and divisivle is true
        if (a%i == 0) {
            divisible = true;     //if a is divisible by i, set divisible to true
        } else {
            divisible = false;    //if not divisible by i, set to false
        }
    }
    return divisible;
}

int main() {
    int num{};
    bool notFound = true;
    for (int i=2; i<=1000000000 && notFound; i+=2) {
        if (checkDivisibility(i)) {
            num = i;
            notFound = false;
        }        
    }
    if (num==0) {
        cout << "Not Found";
    } else {
        cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is " << num;
    }
}
