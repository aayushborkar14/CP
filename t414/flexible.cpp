#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w{ };
    cin >> w;
    int p{ };
    cin >> p;
    int temp{};
    vector<int> l;
    l.push_back(0);
    for (int i=0; i<p; i++) {
        cin >> temp;
        l.push_back(temp);
    }
    l.push_back(w);
    vector<int> possibleVals;
    int temp1{ };
    for (int i=0; i<p+2; i++) {
        for (int j=i+1; j<p+2; j++) {
            temp1 = abs(l.at(i)-l.at(j));
            if (count(possibleVals.begin(), possibleVals.end(), temp1)) continue;
            possibleVals.push_back(temp1);
        }
    }
    sort(possibleVals.begin(), possibleVals.end());
    for (int i=0; i<possibleVals.size(); i++) {
        cout << possibleVals.at(i);
        if (i == possibleVals.size()) break;
        cout << " ";
    }
}
