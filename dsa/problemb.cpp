#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t{ };
    int n{ };
    cin >> t;
    while (t--) {
        vector<int> a;
        cin >> n;
        int input{ };
        for (int i=0; i<n; i++) {
            cin >> input;
            a.push_back(input);
        }
    }
}