#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ };
    int num1{ }, num2{ };
    while (true) {
        cin >> n;
        if (n == 0) break;
        
        cout << n << " = " << num1 << " + " << num2 << "\n";
    }
}
