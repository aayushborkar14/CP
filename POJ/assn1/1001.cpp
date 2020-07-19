#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

typedef numeric_limits<int> inl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout << setprecision(inl::digits10);
    cout << pow(95123, 12);
}
