#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ }, t{ };
    cin >> t;
    int scenario_num{ };
    while (t--) {
        scenario_num++;
        cin >> n;
        cout << "Scenario #" << scenario_num << ":\n";
        for (int i=-n; i<=n; i++) {
            cout << "slice #" << i+n+1 << ":\n";
            for (int j=-n; j<=n; j++) {
                for (int k=-n; k<=n; k++) {
                    int d = abs(i) + abs(j) + abs(k);
                    if (d<=n) cout << d;
                    else cout << ".";
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
}
