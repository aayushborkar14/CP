#include <bits/stdc++.h>

using namespace std;

int num_of_bad{};
int bad[100];

bool is_allowed(int a, int b, int c, int d)
{
    for (int i = 0; i < num_of_bad*4; i += 4)
    {
        if (bad[i] == a && bad[i + 1] == b)
            if (bad[i + 2] == c && bad[i + 3] == d)
                return false;

            else if (bad[i] == c && bad[i + 1] == d)
                if (bad[i + 2] == a && bad[i + 3] == b)
                    return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int dp[100][100];
    int x{}, y{};
    cin >> x >> y;
    bool check1{}, check2{};
    cin >> num_of_bad;
    int a{};
    for (int i = 0; i < num_of_bad * 4; i++)
    {
        cin >> a;
        bad[i] = a;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (j == 0)
                check1 = false;
            else
                check1 = is_allowed(i, j - 1, i, j);
            if (i == 0)
                check2 = false;
            else
                check2 = is_allowed(i - 1, j, i, j);
            if (i == 0)
            {
                if (!check1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j - 1];
            }
            else if (j == 0)
            {
                if (!check2)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j];
            }
            else
            {
                if (!check2 && !check1)
                    dp[i][j] = 0;
                else if (!check1)
                    dp[i][j] = dp[i - 1][j];
                else if (!check2)
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << "\n";
        }
    }
    cout << dp[x][y];
}
