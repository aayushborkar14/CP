#include <iostream>

using namespace std;

int sum_of_digit(int n) {
    int sum{ };
    while (n != 0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ };
    cin >> n;
    int num_of_ways{1};
    for (int i=n/2+1; i >= 1; i--) {
        int sum{ };
        for (int j=i; sum < n; j--) {
            sum += j;
        }
        if (sum == n) {
            num_of_ways++;
        }
    }
    cout << num_of_ways;
}
