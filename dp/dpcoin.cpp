#include <bits/stdc++.h>

using namespace std;

int n{}, s{};
int v[1000];
int dp[1000];

int rec(int s)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == s)
            return 1;
    }
    if (dp[s] != -1)
        return dp[s];
    dp[s] = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= s)
        {
            dp[s] = min(dp[s], 1 + rec(s - v[i]));
        }
    }
    return dp[s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i <= s; i++)
        dp[i] = -1;
    cout << rec(s) << "\n";
}
