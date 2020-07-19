#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ };
    cin >> n;
    string message{ };
    while (n--) {
        cin >> message;
        int l = message.length();
        double sr = sqrt(l);
        int m{ };
        if ((sr - floor(sr)) == 0) {
            m = l;            
        } else {
            m = pow((floor(sqrt(l)) + 1), 2);
        }
        int k = sqrt(m);
        vector<vector<char>> vec(k, vector<char>(k, '*'));
        int currentIndex1{ };
        int currentIndex2{ };
        for (int i=0; i<l; i++) {
            vec.at(currentIndex1).at(currentIndex2) = message[i];
            currentIndex2++;
            if (currentIndex2 >= k) {
                currentIndex1++;
                currentIndex2 = 0;
            }
        }
        string coded{};
        for (int j=0; j < k; j++) {
            for (int i=k-1; i >= 0 ; i--) {
                coded.push_back(vec.at(i).at(j));
            }
        }
        coded.erase(remove(coded.begin(), coded.end(), '*'), coded.end());
        cout << coded << "\n";
    }
}
