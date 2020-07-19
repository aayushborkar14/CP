#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{}, n{};
    cin >> t;
    while (t--) {
        int laddus{};
        int months{};
        string nationality;
        cin >> n;
        cin >> nationality;
        string text;
        while (n--) {
            cin >> text;
            if (text == "CONTEST_WON") {
                int rank{};
                cin >> rank;
                if (rank <= 20) {
                    laddus += 300 + 20 - rank;
                } else {
                    laddus += 300;
                }
            } else if (text == "TOP_CONTRIBUTOR") {
                laddus += 300;
            } else if (text == "BUG_FOUND") {
                int severity;
                cin >> severity;
                laddus += severity;
            } else if (text == "CONTEST_HOSTED") {
                laddus += 50;
            }
        }
        if (nationality == "INDIAN") {
            months = laddus/200;
        } else {
            months = laddus/400;
        }
        cout << months << "\n";
    }
}
