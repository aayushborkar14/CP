#include <iostream>
#include <cmath>

using namespace std;

int intlen(int i) {
    if (i == 0) return 1;
    else if (i < 0) return 2 + log10(-i);
    else if (i > 0) return 1 + log10(i);
}

int karatsuba(int x, int y) {
    int product{ };
    int n{ };
    if (intlen(x) < intlen(y)) {
        n = intlen(x);
    } else {
        n = intlen(y);
    }
    int a{ }, b{ }, c{ }, d{ };
    if (n == 1) {
        return x*y;
    }
    if (n%2 == 0) {
        int xnby2 = pow(10, n/2); 
        a = x/xnby2;
        b = x%(xnby2);
        c = y/xnby2;
        d = y%(xnby2);
        int ac = karatsuba(a, c);
        int bd = karatsuba(b, d);
        int abcd = karatsuba((a+b), (c+d));
        int adbc = abcd - ac - bd;
        product = (pow(10, n)*ac) + (pow(10, (n/2))*adbc) + bd;
        return product;
    } else {
        int xnby2 = pow(10, ((n-1)/2));
        a = x/xnby2;
        b = x%(xnby2);
        c = y/xnby2;
        d = y%(xnby2);
        int ac = karatsuba(a, c);
        int bd = karatsuba(b, d);
        int abcd = karatsuba((a+b), (c+d));
        int adbc = abcd - ac - bd;
        product = (pow(10, (n-1))*ac) + (pow(10, ((n-1)/2))*adbc) + bd;
        return product;
    }
}

int main() {
    int x{ }, y{ };
    cout << "Enter a number: ";
    cin >> x;
    cout << "Enter another number: ";
    cin >> y;
    cout << "Their product is " << karatsuba(x, y);
}
