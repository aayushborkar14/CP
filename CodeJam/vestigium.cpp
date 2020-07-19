#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, n{ }, k{ };
    int r{ }, c{ };
    cin >> t;
    int case_count = 0;
    while(t--) {
        case_count++;
        r = 0;
        c = 0;
        k = 0;
        cin >> n;
        vector<vector<int>> m;
        int temp{ };
        for (int i=0; i<n; i++) {
            m.push_back(vector<int>());
            for (int j=0; j<n; j++) {
                cin >> temp;
                m.at(i).push_back(temp);
            }
        }
        for (int i=0, j=0; i<n && j<n; i++, j++) {
            k += m.at(i).at(j);
        }
        bool flag = false;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (m.at(i).at(j) == m.at(i).at(k)) {
                        r++;
                        flag = true;
                        break;
                    }
                }
                if(flag) {
                        flag = false;
                        break;
                }
            }
        }
        flag = false;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (m.at(j).at(i) == m.at(k).at(i)) {
                        c++;
                        flag = true;
                        break;
                    }
                }
                if(flag) {
                        flag = false;
                        break;
                    }
            }
        }
        cout << "Case #" << case_count << ": " << k << " " << r << " " << c << "\n";
    }
}