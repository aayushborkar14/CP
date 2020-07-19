#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

double khToMs(int kh) {
    return (5/18)*kh;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ };
    int v{ }, t{ };
    while (true) {
        cin >> n;
        if (n == 0) break;
        double tMin = DBL_MAX;
        while (n--) {
            cin >> v >> t;
            if (t < 0) continue;
            double tTemp = t + (4.5/v)*3600;
            if (tTemp < tMin) {
                tMin = tTemp;
            }
        }
        cout << ceil(tMin) << "\n";
    }
}
