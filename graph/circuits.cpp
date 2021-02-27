#include <bits/stdc++.h>

using namespace std;

int dp[50];
vector<int> connects[50];
vector<int> costs[50];
int k{};

int dfs(int n)
{
    if (dp[n] != -1) return dp[n];
    for (int i = 0; i < connects[n].size(); i++) {
        dp[n] = max(dp[n], costs[n].at(i) + dfs(connects[n].at(i)));
    }
    if (connects[n].size() == 0) dp[n] = 0;
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    string temp{};
    string temp2{};
    cin.ignore();
    for (int i = 0; i < k; i++)
    {
        getline(cin, temp);
        for (int j = 0; j < temp.length(); j++)
        {
            if (temp.at(j) == ' ')
            {
                connects[i].push_back(stoi(temp2));
                temp2 = "";
            }
            else
            {
                temp2 += temp.at(j);
                if (j == temp.length() - 1)
                {
                    connects[i].push_back(stoi(temp2));
                    temp2 = "";
                }
            }
        }
    }
    temp = "";
    temp2 = "";
    for (int i = 0; i < k; i++)
    {
        getline(cin, temp);
        for (int j = 0; j < temp.length(); j++)
        {
            if (temp.at(j) == ' ')
            {
                costs[i].push_back(stoi(temp2));
                temp2 = "";
            }
            else
            {
                temp2 += temp.at(j);
                if (j == temp.length() - 1)
                {
                    costs[i].push_back(stoi(temp2));
                    temp2 = "";
                }
            }
        }
    }
    // dp
    for (int i = 0; i < k; i++)
    {
        dp[i] = -1;
    }
    int ans{};

    for (int i = 0; i < k; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans;
}
