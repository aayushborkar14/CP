#include <bits/stdc++.h>

using namespace std;
int n{};
int dp[1000];

int res(int n)
{
    if (n <= 0)
        return 0;
    if (n % 2 == 1)
    {
        dp[n] = 0;
        return 0;
    }
    if (dp[n - 2] == -1)
        dp[n - 2] = res(n - 2);
    dp[n] = dp[n - 2] + pow(2, ((n / 2) + 1));
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 1000; i++)
        dp[i] = 0;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        cout << res(n) << "\n";
    }
}
