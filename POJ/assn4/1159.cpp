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
    for (int i = 0; i <= n; i++)
    {
        d.push_back(vector<int>());
        for (int j = 0; j <= n; j++)
        {
            d.at(i).push_back(-1);
        }
        d.at(i).at(i) = 0;
        if (i != 0)
            d.at(i).at(i - 1) = 0;
    }
    for (int t = 2; t <= n; t++)
    {
        for (int i = 1, j = t; j <= n; i++, j++)
        {
            if (x.at(i - 1) == x.at(j - 1))
                d.at(i).at(j) = d.at(i + 1).at(j - 1);
            else
                d.at(i).at(j) = 1 + min(d.at(i + 1).at(j), d.at(i).at(j - 1));
        }
    }
    cout << d.at(1).at(n);
}
