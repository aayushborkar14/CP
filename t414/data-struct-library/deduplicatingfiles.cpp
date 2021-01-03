#include <bits/stdc++.h>

using namespace std;

int hashf(string s)
{
    int x = (1 << 8) - 1;
    for (auto const &c : s)
    {
        x ^= ((int)c) % 128;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t;
    while (cin >> t && t)
    {
        map<int, set<string>> m;
        getline(cin, s);
        int hashCollision = 0;
        int unique = 0;
        while (t--)
        {
            getline(cin, s);
            int h = hashf(s);
            if (m[h].find(s) == m[h].end())
            {
                unique += 1;
                hashCollision += m[h].size();
                m[h].insert(s);
            }
        }
        cout << unique << ' ' << hashCollision << endl;
    }
}
