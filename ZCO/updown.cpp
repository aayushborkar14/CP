#include <bits/stdc++.h>

using namespace std;

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
        int temp{};
        vector<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            s.push_back(temp);
        }
        // dp[i].first = length of largest sub-seq ending with s[i]
        // dp[i].second = index of starting number of the subseq
        vector<pair<int, int>> dp(n, make_pair(0, 0));
        dp.at(0).first = 1;
        dp.at(0).second = 0;
        for (int i = 1; i < n; i++)
        {
            if (((i - dp.at(i - 1).second) % 2 == 1) && (s.at(i) >= s.at(i - 1)))
            {
                dp.at(i).first = dp.at(i - 1).first + 1;
                dp.at(i).second = dp.at(i - 1).second;
            }
            else if (((i - dp.at(i - 1).second) % 2 == 0) && (s.at(i) <= s.at(i - 1)))
            {
                dp.at(i).first = dp.at(i - 1).first + 1;
                dp.at(i).second = dp.at(i - 1).second;
            }
            else if (s.at(i) > s.at(i - 1))
            {
                bool marked = false;
                for (int j = i - 1; j >= 1; j++)
                {
                    if (s.at(j) != s.at(j - 1))
                    {
                        marked = true;
                        dp.at(i).first = i - j + 1;
                        dp.at(i).second = j;
                        if (dp.at(i).first % 2 == 1)
                        {
                            dp.at(i).first--;
                            dp.at(i).second++;
                        }
                        break;
                    }
                }
                if (!marked)
                {
                    dp.at(i).first = i + 1;
                    dp.at(i).second = 0;
                    if (dp.at(i).first % 2 == 1)
                    {
                        dp.at(i).first--;
                        dp.at(i).second++;
                    }
                }
            }
            else if (s.at(i) < s.at(i - 1))
            {
                bool marked = false;
                for (int j = i - 1; j >= 1; j++)
                {
                    if (s.at(j) != s.at(j - 1))
                    {
                        marked = true;
                        dp.at(i).first = i - j + 1;
                        dp.at(i).second = j;
                        if (dp.at(i).first % 2 == 0)
                        {
                            dp.at(i).first--;
                            dp.at(i).second++;
                        }
                        break;
                    }
                }
                if (!marked)
                {
                    dp.at(i).first = i + 1;
                    dp.at(i).second = 0;
                    if (dp.at(i).first % 2 == 0)
                    {
                        dp.at(i).first--;
                        dp.at(i).second++;
                    }
                }
            }
            else
            {
                dp.at(i).first = 1;
                dp.at(i).second = i;
            }
            // cout << "dp[" << i << "]: " << dp.at(i).first << " " << dp.at(i).second << endl;
        }
        int prev_sec{};
        int largest_length{};
        for (int i = n - 1; i >= 0; i--)
        {
            if ((i == n - 1) && (dp.at(i).second == 0))
            {
                largest_length = n + 1;
            }
            else if (dp.at(i).second != prev_sec)
            {
                prev_sec = dp.at(i).second;
                if (dp.at(prev_sec).second == prev_sec)
                {
                    largest_length = max(largest_length, dp.at(i).first);
                }
                else
                {
                    largest_length = max(largest_length, dp.at(prev_sec).first + dp.at(i).first);
                }
            }
        }
        cout << largest_length << "\n";
    }
}
