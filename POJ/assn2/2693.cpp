#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<float, float>> vec;
    float x{}, y{};
    while(!cin.eof()) {
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }
    for (auto pair_temp : vec) {
        cout << pair_temp.first << " " << pair_temp.second << "\n";
    }
}
