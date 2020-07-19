#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, n{ };
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> max_speeds;
        int temp;
        for (int i=0; i<n; i++) {
            cin >> temp;
            max_speeds.push_back(temp);
        }
        int num_of_max = 1;
        for (int i=1; i<n; i++) {
            bool is_max = true;
            for (int j=0; j<i; j++) {
                if (max_speeds.at(i) > max_speeds.at(j)) {
                    is_max = false;
                    break;
                }
            }
            if (is_max) {
                num_of_max++;
            }
        }
        cout << num_of_max << "\n";
    }
}
