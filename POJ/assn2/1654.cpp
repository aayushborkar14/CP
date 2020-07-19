#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    while (t--) {
        long long int current_x = 0;
        long long int current_y = 0;
        long long int prev_x = 0;
        long long int prev_y = 0;
        string my_str;
        long long int term1{ }, term2{ };
        cin.ignore();
        getline(cin, my_str);
        long double area{ };
        for (int i=0; i < my_str.length(); i++) {
            char temp = my_str.at(i);
            if (temp == '5') break;
            prev_x = current_x;
            prev_y = current_y;
            if (temp == '8') {
                current_y++;
            } else if (temp == '2') {
                current_y--;
            } else if (temp == '6') {
                current_x++;
            } else if (temp == '4') {
                current_x--;
            } else if (temp == '9') {
                current_x++;
                current_y++;
            } else if (temp == '7') {
                current_x--;
                current_y++;
            } else if (temp == '3') {
                current_x++;
                current_y--;
            } else if (temp == '1') {
                current_x--;
                current_y--;
            }
            area += current_x*prev_y - prev_x*current_y;
        }
        if (area < 0) area = -area;
        cout << 0.5*area << "\n";
    }
}
