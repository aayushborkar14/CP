#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;
    int n{};
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        vector<int> l;
        l.push_back(0);
        int temp{};
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            l.push_back(temp);
        }
        int cost{};
        for (int i = 1; i < n; i++)
        {
            int j = i;
            for (int k = i; k <= n; k++)
            {
                if (l.at(j) > l.at(k))
                {
                    j = k;
                }
            }
            reverse(l.begin() + i, l.begin() + j + 1);
            cost += j - i + 1;
        }
        cout << "Case #" << tc << ": " << cost << "\n";
    }
}
