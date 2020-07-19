#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int t{ };
    cin >> t;
    float R{ };
    int n{ };
    int r{ };
    int s{};
    while (t--) {
        s++;
        cin >> R >> n;
        double pi = 2*acos(0.0);
        float sin_n = sin(M_PI/n);
        float ans = (sin_n*R)/(sin_n+1);
        cout << "Scenario #" << s << ":\n";
        printf("%.3f\n\n", ans);
    }
}
