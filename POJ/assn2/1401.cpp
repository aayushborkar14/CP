#include <iostream>
#include <cmath>

using namespace std;

//de polignac's formula
int z(int n) {
    int num{ };
    for (int i=1; true; i++) {
        int temp = floor(n/pow(5, i));
        if (temp < 1) break;
        num += temp;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    long long int n{ };
    while (t--) {
        cin >> n;
        cout << z(n) << "\n";
    }
}
