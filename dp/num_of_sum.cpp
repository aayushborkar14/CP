#include <bits/stdc++.h>

using namespace std;
int n{};
int dp[1000];

int rec(int n)
{
    if (n < 0)
        return 0;
    // if (n == 0 || n == 1 || n == 2) return 1;
    // if (n == 3) return 2;
    if (dp[n - 1] == -1)
        dp[n - 1] = rec(n - 1);
    if (dp[n - 3] == -1)
        dp[n - 3] = rec(n - 3);
    if (dp[n - 4] == -1)
        dp[n - 4] = rec(n - 4);
    dp[n] = dp[n - 1] + dp[n - 3] + dp[n - 4];
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 1000; i++)
        dp[i] = -1;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    cin >> n;
    cout << rec(n);
}
