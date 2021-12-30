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
        vector<pair<int, int>> L, U;
        int temp1{}, temp2{};
        for (int i = 0; i < n; i++)
        {
            cin >> temp1 >> temp2;
            L.push_back(make_pair(temp1, i));
            U.push_back(make_pair(temp2, i));
        }
        sort(L.begin(), L.end());
        sort(U.begin(), U.end());
        vector<int> sol(n, 0);
        for (int i = 0; i < n; i++)
        {
            sol.at(L.at(i).second) += n - 1 - i;
            sol.at(U.at(i).second) += i;
        }
        for (int i = 0; i < n; i++)
            cout << sol.at(i) << " ";
        cout << "\n";
    }
}
