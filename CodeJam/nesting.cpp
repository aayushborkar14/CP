#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    int case_count{ };
    while (t--) {
        case_count++;
        string s;
        cin >> s;
        string s_result = "";
        int current_index = 0;
        int str_len = s.length();
        for (int i=0; i<str_len; i++) {
            if (str_len == 1) {
                if (s.at(i) == '0') {
                    s_result.push_back('0');
                } else {
                    s_result.push_back('(');
                    s_result.push_back('1');
                    s_result.push_back(')');
                }
                break;     
            }
            if (i == 0) {
                if (s.at(i) == '0') {
                    s_result.push_back('0');
                } else {
                    s_result.push_back('(');
                    s_result.push_back('1');
                }                
            } else if (i != str_len-1) {
                if (s.at(i-1)=='0' && s.at(i)=='0') {
                    s_result.push_back('0');
                } else if (s.at(i-1)=='0' && s.at(i)=='1') {
                    s_result.push_back('(');
                    s_result.push_back('1');
                } else if (s.at(i-1)=='1' && s.at(i)=='0') {
                    s_result.push_back(')');
                    s_result.push_back('0');
                } else if (s.at(i-1)=='1' && s.at(i)=='1') {
                    s_result.push_back('1');
                }
            } else {
                if (s.at(i-1)=='1' && s.at(i) == '1') {
                    s_result.push_back('1');
                    s_result.push_back(')');
                } else if (s.at(i-1)=='0' && s.at(i) == '1') {
                    s_result.push_back('(');
                    s_result.push_back('1');
                    s_result.push_back(')');
                } else if (s.at(i-1)=='1' && s.at(i)=='0') {
                    s_result.push_back(')');
                    s_result.push_back('0');
                } else if (s.at(i-1)=='0' && s.at(i)=='0') {
                    s_result.push_back('0');
                }
            }
        }
        cout << "Case #" << case_count << ": " << s_result << "\n";
    }
}