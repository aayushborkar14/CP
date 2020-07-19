#include <iostream>
#include <cmath>

using namespace std;

int z(int n) {
    int num{ };
    int temp = 1;
    int counter = 1;
    while (temp != 0) {
        temp = n/pow(5, counter);
        num += temp;
        counter++;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    while (t--) {
        int n{ };
        cin >> n;
        cout << z(n) << "\n";
    }
}
