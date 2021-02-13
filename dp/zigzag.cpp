#include <bits/stdc++.h>

using namespace std;

int get_sign(int n)
{
    int to_return{};
    if (n < 0)
        to_return = -1;
    else if (n > 0)
        to_return = 1;
    else if (n == 0)
        to_return = 0;
    return to_return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;
    while (t--)
    {
        int n{};
        cin >> n;
        vector<vector<int>> dp(1001);
        vector<int> a(1001);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i][0] = 1;
        }
        dp[1][1] = 0;
        if (a[1] != a[2]) {
            dp[2][0] = 2;
            dp[2][1] = get_sign(a[2] - a[1]);
        } else {
            dp[2][0] = 1;
            dp[2][1] = 0;
        }
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (get_sign(a[i] - a[j]) != dp[j][1] && a[i] != a[j])
                {
                    dp[i][0] = max(dp[i][0], 1 + dp[j][0]);
                    dp[i][1] = get_sign(a[i] - a[j]);
                }
            }
        }
        cout << dp[n][0] << "\n";
    }
}
