#include <iostream>
#include <cmath>

using namespace std;

int n = 0;

int get_triangular() {
    n++;
    return (0.5*n*(n+1));
}

int no_of_divisors(int num) {
    int num_of_divisors = 0;
    for (int i=1; i<=sqrt(num); i++) {
        if (num % i == 0){
            num_of_divisors += 2;
        }
    }
    return num_of_divisors;
}

int main() {
    int num_of_divisors;
    int triangular;
    while (!(num_of_divisors > 500)) {
        triangular = get_triangular();
        num_of_divisors = no_of_divisors(triangular);
    }
    cout << triangular << "\n";
}