#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ };
    cin >> n;
    int counter = n-1;
    vector<int> vec;
    vector<bool> vec_count(n, false);
    int temp{ };
    while (counter--) {
        cin >> temp;
        vec.push_back(temp);
        vec_count.at(temp-1) = true;
    }
    for (int i=0; i<n; i++) {
        if (vec_count.at(i) == false) {
            cout << i+1;
        }
    }
}
