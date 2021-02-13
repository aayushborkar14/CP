#include <bits/stdc++.h>

using namespace std;

int maxDonations(int donations[40])
{
    int n{}, ans{};
    n = sizeof(donations) / sizeof(*donations);
    int dp[50][2];
    int a[50];
    for (int i = 1; i <= n; i++)
    {
        a[i] = donations[i - 1];
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
    return ans;
}

int main()
{
    int a[40] = {94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
                 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
                 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72};
    cout << maxDonations(a);
}
