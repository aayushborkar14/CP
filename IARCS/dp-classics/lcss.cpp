#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string text1, text2;
    cin >> text1 >> text2;
    vector<vector<int>> dp;
    int m = text1.length();
    int n = text2.length();
    for (int i = 0; i < m; i++)
    {
        dp.push_back(vector<int>());
        for (int j = 0; j < n; j++)
            dp.at(i).push_back(-1);
    }
    for (int j = n - 1; j >= 0; j--)
    {
        if (text2.at(j) == text1.at(m - 1))
        {
            for (int k = 0; k <= j; k++)
                dp.at(m - 1).at(k) = 1;
            break;
        }
        dp.at(m - 1).at(j) = 0;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (text1.at(i) == text2.at(n - 1))
        {
            for (int k = 0; k <= i; k++)
                dp.at(k).at(n - 1) = 1;
            break;
        }
        dp.at(i).at(n - 1) = 0;
    }
    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
        {
            if (text1.at(i) == text2.at(j))
                dp.at(i).at(j) = 1 + dp.at(i + 1).at(j + 1);
            else
                dp.at(i).at(j) = max(dp.at(i + 1).at(j), dp.at(i).at(j + 1));
        }
    cout << dp.at(0).at(0);
}
