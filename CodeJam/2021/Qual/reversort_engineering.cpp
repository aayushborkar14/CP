#include <bits/stdc++.h>

using namespace std;

int est(float num)
{
    int estnum;
    if (num > floor(num) + 0.5)
        estnum = floor(num) + 1;
    else
        estnum = floor(num);
    return estnum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;
    int n{}, c{};
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> c;
        int cmax = ((n - 1) * (n + 2)) / 2;
        int cmin = n - 1;
        if (c > cmax || c < cmin)
            cout << "Case #" << tc << ": IMPOSSIBLE\n";
        else
        {
            vector<int> l;
            l.push_back(0);
            for (int i = 1; i <= n; i++)
            {
                l.push_back(i);
            }
            int cn{};
            int ci{};
            for (int i = n - 1; i >= 1; i--)
            {
                if (i == 1)
                {
                    ci = c - cn;
                    int j = ci + i - 1;
                    reverse(l.begin() + i, l.begin() + j + 1);
                }
                else
                {
                    if (est((c - cn) / i) > n - i + 1)
                        ci = n - i + 1;
                    else
                        ci = est((c - cn) / i);
                    cn += ci;
                    int j = ci + i - 1;
                    reverse(l.begin() + i, l.begin() + j + 1);
                }
            }
            cout << "Case #" << tc << ":";
            for (int i = 1; i <= n; i++)
                cout << " " << l.at(i);
            cout << "\n";
        }
    }
}
