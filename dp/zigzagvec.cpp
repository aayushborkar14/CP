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
        vector<vector<int>> dp(1001, vector<int> (2, 0));
        vector<int> a(1001, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a.at(i);
            dp.at(i).at(0) = 1;
        }
        dp.at(1).at(1) = 0;
        if (a.at(1) != a.at(2)) {
            dp.at(2).at(0) = 2;
            dp.at(2).at(1) = get_sign(a.at(2) - a.at(1));
        } else {
            dp.at(2).at(0) = 1;
            dp.at(2).at(1) = 0;
        }
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (get_sign(a.at(i) - a.at(j)) != dp.at(j).at(1) && a.at(i) != a.at(j))
                {
                    dp.at(i).at(0) = max(dp.at(i).at(0), 1 + dp.at(j).at(0));
                    dp.at(i).at(1) = get_sign(a.at(i) - a.at(j));
                }
            }
        }
        cout << dp.at(n).at(0) << "\n";
    }
}
