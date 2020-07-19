#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ };
    cin >> n;
    vector<int> vec;
    int temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());
    long long int max{ };
    int temp1;
    for (int i=0; i<n; i++) {
        temp1 = vec.at(i)*(n-i);
        if (temp1 > max) {
            max = temp1;
        }
    }
    cout << max;
}
