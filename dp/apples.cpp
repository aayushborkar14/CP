#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, m{};
    cin >> n >> m;
    int ans{};
    int a[100][100];
    int dp[100][100];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            dp[i][j] = -1;
        }
    }
    dp[1][1] = a[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                dp[i][j] = dp[i][j];
            else if (i == 1)
                dp[i][j] = a[i][j] + dp[i][j - 1];
            else if (j == 1)
                dp[i][j] = a[i][j] + dp[i - 1][j];
            else
                dp[i][j] = a[i][j] + max(dp[i][j - 1], dp[i - 1][j]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
