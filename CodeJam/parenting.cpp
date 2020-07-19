#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool isJFree(int a, int b, vector<vector<int>> j_arr, int n) {
    bool yesno = false;
    int current_i{ };
    int current_j{ };
    for (int i=0; i<n; i++) {
        if (j_arr.at(i).at(1) > a) {
            yesno = false;
            break;
        } else {
            yesno = true;
        }
        
        if (j_arr.at(i).at(0) < b) {
            yesno = false;
            break;
        } else {
            yesno = true;
        }
    }
    return yesno;
}

bool isCFree(int a, int b, vector<vector<int>> c_arr, int n) {
    bool yesno = true;
    int current_i{ };
    int current_j{ };
    for (int i=0; i<n; i++) {
        if (c_arr.at(i).at(1) > a) {
            yesno = false;
            break;
        } else {
            yesno = true;
        }
        
        if (c_arr.at(i).at(0) < b) {
            yesno = false;
            break;
        } else {
            yesno = true;
        }
    }
    return yesno;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, n{ };
    cin >> t;
    int case_count{ };
    char current_char = 'C';
    while(t--) {
        int j_index{ };
        int c_index{ };
        vector<vector<int>> j_arr;
        vector<vector<int>> c_arr;
        string y = "";
        case_count++;
        cin >> n;
        vector<int> s;
        vector<int> e;
        int temp1, temp2;
        for (int i=0; i<n; i++) {
            cin >> temp1;
            s.push_back(temp1);
            cin >> temp2;
            e.push_back(temp2);
        }
        for (int i=0; i<n; i++) {
            if (isJFree(s.at(i), e.at(i), j_arr, j_index)) {
                j_arr.push_back(vector<int>());
                j_arr.at(j_index).push_back(s.at(i));
                j_arr.at(j_index).push_back(e.at(i));
                j_index++;
                y.push_back('J');
            } else if (isCFree(s.at(i), e.at(i), c_arr, c_index)) {
                c_arr.push_back(vector<int>());
                c_arr.at(c_index).push_back(s.at(i));
                c_arr.at(c_index).push_back(e.at(i));
                c_index++;
                y.push_back('C');
            } else {
                y = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << case_count << ": " << y << "\n";
    }
}