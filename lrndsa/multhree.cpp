#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, d_0{ }, d_1{ };
    unsigned long long int k{ };
    cin >> t;
    while (t--) {
        cin >> k >> d_0 >> d_1;
        unsigned long long int sum_of_digits = d_0 + d_1;
        int sum_of_two = d_0+d_1;
        int digit{ };
        for (int i=2; i<=k; i++) {
            digit = ((int)(pow(2, i-2)%10)*(sum_of_two))%10;
            sum_of_digits += digit;
            // cout << sum_of_digits << "\n";
        }
        if (sum_of_digits%3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
