#include<iostream>
#include<cmath>

using namespace std;

bool checkPythagorean(int a, int b, int c) {
    if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {     //return true if a^2+b^2 = c^2
        return true;
    } else {
        return false;
    }
}

int main() {
    int a{}, b{}, c{};
    int sum{1000};
    bool notFound = true;
    for (int i=1; i<sum/3 && notFound; i++) {       //a<b<c given, so a<sum/3
        for (int j=1; j<sum/2 && notFound; j++) {   //again, a<b<c, so b<sum/2
            int k = sum - i - j;                    //a+b+c=1000  -->  c=1000-a-b
            if(checkPythagorean(i, j, k)) {         //if pythagorean
                a = i;
                b = j;
                c = k;
                notFound = false;
            }
        }
    }
    cout << "Product of pythagorean triplet with sum 1000 is " << a*b*c;
}
