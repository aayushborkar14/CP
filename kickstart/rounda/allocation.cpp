#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, n{ }, b{ };
    cin >> t;
    int x{ };
    while (t--) {
        x++;
        vector<int> a;
        cin >> n >> b;
        int temp{ };
        for (int i=0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        int sum{ }, y{ };
        for (int i=0; i < n; i++) {
            sum += a.at(i);
            y++;
            if (sum > b) {
                sum -= a.at(i);
                y--;
                break;
            }
        }
        cout << "Case #" << x << ": " << y << "\n";
    }
}
