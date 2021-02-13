#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t{};
    cin >> t;
    while (t--)
    {
        int n{}, ans{};
        cin >> n;
        int dp[1000][2];
        int a[1000];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i][0] = a[i];
            dp[i][1] = 0;
        }
        dp[1][1] = 1;
        dp[2][1] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                if (i == n && j == 1)
                    continue;
                if (i == n && dp[j][1] == 1)
                {
                    dp[i][0] = max(dp[i][0], a[i] + dp[j][0] - dp[1][0]);
                    continue;
                }
                if (a[i] + dp[j][0] > dp[i][0])
                {
                    dp[i][0] = a[i] + dp[j][0];
                    dp[i][1] = dp[j][1];
                }
            }
            ans = max(ans, dp[i][0]);
        }
        cout << ans << "\n";
    }
}
