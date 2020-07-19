#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> primes;        //declare vector
    primes.push_back(2);    //push back 2 to primes
    for (int i=3; i<200000; i+=2) {     //loop from 3 to 1999999, increment by 2 cuz 2 is only even prime
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
    cout << "The 10001st prime is " << primes.at(10000);     //print 10001st prime, array index will be 10000
}
