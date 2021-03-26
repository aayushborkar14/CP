#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool sortcol (const vector<int>& v1, const vector<int>& v2 ) { 
    return v1.at(0) < v2.at(0); 
}

int main() {
    vector<vector<int>> m = {{2, 5, 4}, {1, 3, 8}, {3, 7, 3}};
    sort(m.begin(), m.end(), sortcol);
    for (int i=0; i<3; i++) {
        cout << "\n";
        for (int j=0; j<3; j++) {
            cout << m.at(i).at(j) << " ";
        }
    }
}