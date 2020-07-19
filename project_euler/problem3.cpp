#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main () {
    vector <int> factors;   //vector to store all the factors of 600851475143
    int largest {};      //integer to store largest factor
    long long int num = 600851475143;     //long long int is large enough
    while (num%2 == 0) {        //check if 2 is a factor,
                                //while loop beacuse a number can have 2 as a factor multiple times
        num /= 2;               //if 2 is factor, divide by 2
        factors.push_back(2);   //and add 2 to factors vector
    }
    for (int i=3; i<sqrt(num); i+=2) {  //all other prime number are odd, so increment i by 2
        while (num%i == 0) {           //check factor
            num /= i;                  //if i is factor, divide by i
            factors.push_back(i);      //add i to factors vector
        }   
    }
    factors.push_back(num);        //the last remaining number has no more factors, so it itself is a factor
    for (int i=0; i<factors.size(); i++) {
        if (factors.at(i)>largest) {     //check largest factor
            largest = factors.at(i);
        }
    }    
    cout << "The largest prime factor of 600851475143 is: " << largest;       //output largest factor
}
