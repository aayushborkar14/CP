#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;
    for (int j=1; j <= t; j++) {
        int n{},b{};
        int ans{}, bnow{};
        cin >> n >> b;
        vector<int> a;
        int temp{};
        for (int i=0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        for (auto k : a) {
            if (bnow + k <= b) {
                bnow += k;
                ans++;
            }
        }
        cout << "Case #" << j << ": " << ans << "\n";
    }
}
