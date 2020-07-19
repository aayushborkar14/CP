#include <iostream>
#include <cmath>

using namespace std;

int highestPowerOf2(int n) {
    int highestPower = 0;
    int currentDivisor = 1;
    while (true) {
        currentDivisor *= 2;
        highestPower++;
        if (n%currentDivisor != 0) break;
    }
    return highestPower - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ };
    cin >> n;
    while (n--) {
        int x{ };
        cin >> x;
        int lowest = x;
        int highest = x;
        int floorDifference = pow(2, highestPowerOf2(x) - 1);
        while (true) {
            lowest -= floorDifference;
            highest += floorDifference;
            floorDifference /= 2;
            if (floorDifference == 0) break;
        }
        cout << lowest << " " << highest << "\n";
    }
}
