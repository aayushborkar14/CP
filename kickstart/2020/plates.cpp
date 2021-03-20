#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n{}, k{}, p{};
        // sum.at(i).at(k) = sum of all plates till
        // kth plate (including kth plate) in the ith stack
        vector<vector<int>> sum;
        // dp.at(i).at(j) = max beauty we can pick from
        // first i stacks using j plates in total
        vector<vector<int>> dp;
        cin >> n >> k >> p;
        int temp{}, sum_temp{};
        sum.push_back(vector<int>());
        dp.push_back(vector<int>());
        for (int i = 1; i <= n; i++)
        {
            sum_temp = 0;
            sum.push_back(vector<int>());
            dp.push_back(vector<int>());
            dp.at(i).push_back(0);
            sum.at(i).push_back(0);
            for (int j = 1; j <= k * i; j++)
            {
                dp.at(i).push_back(-1);
            }
            for (int j = 1; j <= k; j++)
            {
                cin >> temp;
                sum_temp += temp;
                sum.at(i).push_back(sum_temp);
                if (i == 1)
                {
                    dp.at(i).at(j) = sum.at(i).at(j);
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= p; j++)
            {
                int xmin{};

                if (j > k)
                {
                    for (int l = 1; l <= i; l++)
                    {
                        if (((l - 1) * k + 1 <= j) && (j <= l * k))
                        {
                            xmin = j - k * (l - 1);
                            break;
                        }
                    }
                }
                for (int x = xmin; x <= min(j, k); x++)
                {
                    dp.at(i).at(j) = max(dp.at(i).at(j), sum.at(i).at(x) + dp.at(i - 1).at(j - x));
                }
            }
        }
        cout << "Case #" << tc << ": " << dp.at(n).at(p) << "\n";
    }
}
