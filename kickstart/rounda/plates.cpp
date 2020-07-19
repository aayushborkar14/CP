#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, n{ }, k{ }, p{ };
    cin >> t;
    while (t--) {
        vector<vector<int>> plates;
        int temp{ };
        for (int i=0; i<n; i++) {
            plates.push_back(vector<int>());
            for (int j=0; j<k; j++) {
                cin >> temp;
                plates.at(i).push_back(temp);
            }
        }
        
    }
}
