#include<iostream>
#include<vector>

using namespace std;

bool checkPalindrome(int a) {
    int p {a};
    int sum {};
    while (a!=0) {
        int b {a%10};
        a=a/10;
        sum=sum*10+b;
    }
    if (sum==p) {
        return true;
    } else {
        return false;
    }
}

int main() {
    vector <int> palindromes;
    int largest {};
    for (int i=100; i<1000; i++) {
        for (int j=100; j<1000; j++) {
            int product = i*j;
            if (checkPalindrome(product)) {
                palindromes.push_back(product);
            }
        }
    }
    for (int i=0; i<palindromes.size(); i++) {
        if (palindromes.at(i) > largest) {
            largest = palindromes.at(i);
        }
    }
    cout << "The largest 3 digit palindrome is: " << largest;
}
