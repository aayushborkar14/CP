#include <bits/stdc++.h>

using namespace std;
int n{};
int dp[100];

int rec(int n)
{
    if (n <= 0)
        return 0;
    if (n % 2 == 1)
    {
        dp[n] = 0;
        return 0;
    }
    if (n >= 1000)
    {
        return 4 * rec(n - 2) - rec(n - 4);
    }
    if (dp[n - 2] == -1)
        dp[n - 2] = rec(n - 2);
    dp[n] = 4 * dp[n - 2] - dp[n - 4];
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 1000; i++)
        dp[i] = -1;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        cout << rec(n) << "\n";
    }
}
