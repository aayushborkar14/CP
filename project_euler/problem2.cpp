#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector <int> fibonacci;  //declare vector to store fibonacci numbers
    int sum {};
    fibonacci.push_back(1);  //initialize fibonacci with 1 and 2
    fibonacci.push_back(2);
    int count1{}, count2{1};  //declare count integers cuz I was having problems with for loop
    while (fibonacci.at(count2)<4000000) {  //run code while fibonacci at count2 is less tham 4 million
        fibonacci.push_back(fibonacci.at(count1)+fibonacci.at(count2));  //add last 2 fibonacci numbers and add to vector
        count1++;   
        count2++;
    }
    fibonacci.at(fibonacci.size()-1)=0;  //hard to explain why
    for (int i=0; i<fibonacci.size(); i++) {
        if (fibonacci.at(i)%2==0) {  //check even number
            sum+=fibonacci.at(i);    //add fibonacci to sum
        }
    }
    cout << "The sum is: " << sum;   //print sum
}