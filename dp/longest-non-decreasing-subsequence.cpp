#include <bits/stdc++.h>

using namespace std;

int a[1000];
int dp[1000];

int rec(int n)
{
    if (dp[n] != -1)
        return dp[n];
    int k = -1;
    for (int j = n - 1; j >= 1; j--)
    {
        if (a[n] >= a[j])
        {
            // dp[n] = max(dp[n], 1 + rec(j));
            k = max(k, 1 + rec(j));
        }
    }
    dp[n] = k;
    if (dp[n] == -1)
        dp[n] = 1;
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = -1;
    }
    dp[1] = 1;
    cout << rec(n) << "\n";
    for (int i = 1; i <= n; i++)
        cout << "dp[" << i << "] = " << dp[i] << "\n";
}
