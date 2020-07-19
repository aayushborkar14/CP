#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    long long int n{ };
    while (t--) {
        cin >> n;
        long long int sum{ };
        long long int temp1{ }, temp2{ };
        cin >> temp1 >> temp2;
        sum += abs(temp2 - temp1) - 1;
        temp1 = temp2;
        for (int i=0; i < n-2; i++) {
            cin >> temp2;
            sum += abs(temp2 - temp1) - 1;
            temp1 = temp2;
        }
        cout << sum << "\n";
    }
}
