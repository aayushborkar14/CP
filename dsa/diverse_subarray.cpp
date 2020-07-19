#include <iostream>
#include <vector>

using namespace std;

int calculate(const vector<int> &a, int n, int s, int l, int r, int max_type) {
    vector<int> num_of_rep(max_type, 0);
    int max_num{ };
    for (int i=l; i <= r; i++) {
        num_of_rep.at(a.at(i)-1)++;
    }
    for (int i=0; i < max_type; i++) {
        if (num_of_rep.at(i) > s) {
            num_of_rep.at(i) = 0;
        }
    }
    for (int i=0; i < max_type; i++) {
        max_num += num_of_rep.at(i);
    }
    return max_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, n{ }, s{ }, y{ };
    int l2{ }, r2{ };
    int x{ };
    cin >> t;
    while (t--) {
        x++;
        int max_type{ };
        vector<int> a;
        cin >> n >> s;
        int temp{ };
        for (int i=0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        for (int i=0; i < n; i++) {
            if (a.at(i) > max_type) {
                max_type = a.at(i);
            }
        }
        for (int l=0; l < n; l++) {
            for (int r=n-1; r > l; r--) {
                int temp1 = calculate(a, n, s, l, r, max_type);
                if (temp1 > y) {
                    y = temp1;
                    l2 = l;
                    r2 = r;
                } 
            }
        }
        cout << "Case #" << x << ": " << y << "\n";
        // cout << l2 << " " << r2;
    }
}
