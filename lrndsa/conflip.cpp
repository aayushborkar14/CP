#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, g{ };
    int i{ }, n{ }, q{ };
    cin >> t;
    while (t--) {
        cin >> g;
        while (g--) {
            cin >> i >> n >> q;
            int num{ };
            if (i == q) {
                if (n % 2 == 0) {
                    num = n/2;
                } else {
                    num = (n-1)/2;
                }
            } else {
                if (n % 2 == 0) {
                    num = n/2;
                } else {
                    num = (n+1)/2;
                }
            }
            cout << num << "\n";
        }
    }
}
