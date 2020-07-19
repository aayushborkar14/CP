#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> primes;     //declare vector to store primes
    primes.push_back(2);    //push back 2 to primes
    for (int i=3; i<2000000; i+=2) {     //loop from 3 to 1999999, increment by 2 cuz 2 is only even prime
        bool prime = true;               //init prime to true
        for (auto p : primes) {          
            //atleast one prime factor of i is less than sqrt(i), so abort if p*p>i
            if (p*p>i) {
                break;
            }
            if (i%p == 0) {    //if p divides i, p is not prime
                prime = false;
                break;
            }
        }
        if (prime) {
            primes.push_back(i);      //push back if prime
        }
    }
    unsigned long long int sum{};
    for (auto p : primes) {
        sum += p;
    }
    cout << "The sum of all primes below 2 million is " << sum;
}
