#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{};
    cin >> n;
    string x;
    cin >> x;
    vector<vector<int>> d;
    string xr(n, 'x');
    for (int i = 0; i < n; i++)
    {
        xr.at(i) = x.at(n - i - 1);
    }
    for (int i = 0; i <= n; i++)
    {
        d.push_back(vector<int>());
        for (int j = 0; j <= n; j++)
        {
            d.at(i).push_back(-1);
        }
        d.at(i).at(0) = 0;
        d.at(0).at(i) = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x.at(i - 1) == xr.at(j - 1))
                d.at(i).at(j) = 1 + d.at(i - 1).at(j - 1);
            else
                d.at(i).at(j) = max(d.at(i).at(j - 1), d.at(i - 1).at(j));
        }
    }
    cout << (n - d.at(n).at(n));
}
