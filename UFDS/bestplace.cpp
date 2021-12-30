#include <bits/stdc++.h>

using namespace std;

int median(vector<int> x)
{
    if (x.size() % 2 == 0)
        return (x.at((x.size() / 2) - 1) + x.at(x.size() / 2)) / 2;
    else
        return x.at((x.size() - 1) / 2);
}

int main()
{
    int n{};
    cin >> n;
    vector<int> x, y;
    int xi{}, yi{};
    for (int i = 0; i < n; i++)
    {
        cin >> xi >> yi;
        x.push_back(xi);
        y.push_back(yi);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << median(x) << " " << median(y) << endl;
}
