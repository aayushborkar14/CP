#include <iostream>

using namespace std;

float calculateCards(float sum) {
    float n = 2;
    float new_sum{ };    
    for(n=2; new_sum < sum; n++) {
        new_sum += 1/n;
    }
    return n-2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    float sum{ };
    cin >> sum;
    while (sum != 0.00) {
        cout << calculateCards(sum) << " card(s)\n";
        cin >> sum;
    }
}