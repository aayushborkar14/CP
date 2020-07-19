#include <iostream>
#include <string>
#include <array>

using namespace std;

bool isLapindrome(string str) {
    array<int, 26> count_left = {0};
    array<int, 26> count_right = {0};
    int str_len = str.length();
    if (str_len % 2 == 0) {
        string str_left = str.substr(0, str_len/2);
        string str_right = str.substr(str_len/2, str_len/2);
        for (int i=0; i < str_len/2; i++) {
            count_left.at(str_left[i] - 'a')++;
            count_right.at(str_right[i] - 'a')++;
        }
    } else {
        string str_left = str.substr(0, (str_len-1)/2);
        string str_right = str.substr((str_len+1)/2, (str_len-1)/2);
        for (int i=0; i < (str_len-1)/2; i++) {
            count_left.at(str_left[i] - 'a')++;
            count_right.at(str_right[i] - 'a')++;
        }
    }
    for (int i=0; i < 26; i++) {
        if (count_left.at(i) != count_right.at(i)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        if (isLapindrome(str)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
