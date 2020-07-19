#include <iostream>

using namespace std;

int reverse_num(int n) {
    int reversed_num{ };
    while (n > 0) {
        reversed_num = reversed_num*10 + n%10;
        n /= 10;
    }
    return reversed_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    int n1{ }, n2{ };
    while (t--) {
        cin >> n1 >> n2;
        int temp = reverse_num(n1) + reverse_num(n2);
        cout << reverse_num(temp) << "\n";
    }
}
