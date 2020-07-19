#include<iostream> //you probably know why
#include<vector>

using namespace std;

int main() {
    vector <int> multiples; //declare vector of integer type named vec to store the multiples of 3 and 5
    int sum {}; //declare integer to store sum
    for (int i=0; i<1000; i++) { //for loop to count numbers from 1 to 1000
        if (i%3==0 || i%5==0) {  //if statement to check divisiblity by 3 or 5
            multiples.push_back(i);    //add number to vec if multiple of 3 or 5
        }
    } 
    for (int i=0; i<multiples.size(); i++) {
        sum+=multiples.at(i);          //add all elements of vec to sum
    }   
    cout << "The sum is: " << sum;    //print sum
} 
