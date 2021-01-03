#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    int n{ };
    int final_x{ }, final_y{ };
    while (t--) {
        map<int, int> xmap;
        map<int, int> ymap;
        cin >> n;
        int temp1{ }, temp2{ };
        for (int i=0; i < 4*n-1; i++) {
            cin >> temp1 >> temp2;
            xmap[temp1]++;
            ymap[temp2]++;
        }
        for (auto x : xmap) {
            if (x.second%2 != 0) {
                final_x = x.first;
            }
        }
        for (auto y : ymap) {
            if (y.second%2 != 0) {
                final_y = y.first;
            }
        }
        cout << final_x << " " << final_y << "\n";
    }
}
