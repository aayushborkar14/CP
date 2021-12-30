#include <bits/stdc++.h>

using namespace std;

int cost(int x, int y, string s)
{
    int cost{};
    for (int i = 1; i < s.length(); i++)
    {
        if (s.at(i - 1) == 'C' && s.at(i) == 'J')
            cost += x;
        else if (s.at(i - 1) == 'J' && s.at(i) == 'C')
            cost += y;
    }
    return cost;
}

// python-style slicing
string sslice(int i, int j, string s)
{
    string sliced{};
    for (int k = i; k < j; k++)
    {
        sliced += s.at(k);
    }
    return sliced;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;
    int x{}, y{};
    string s{};
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> x >> y;
        cin >> s;
        int qb = 0;
        bool goin = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '?')
            {
                if (!goin)
                    qb = i;
                goin = true;
            }
            else if (s.at(i) != '?' && goin)
            {
                goin = false;
                if (qb == 0)
                {
                    if (s.at(i) == 'C')
                        for (int j = qb; j < i; j++)
                            s.at(j) = 'C';
                    else if (s.at(i) == 'J')
                        for (int j = qb; j < i; j++)
                            s.at(j) = 'J';
                }
                else
                {
                    if (s.at(qb - 1) == 'C' && s.at(i) == 'C')
                        for (int j = qb; j < i; j++)
                            s.at(j) = 'C';
                    else if (s.at(qb - 1) == 'J' && s.at(i) == 'J')
                        for (int j = qb; j < i; j++)
                            s.at(j) = 'J';
                    else if (s.at(qb - 1) == 'C' && s.at(i) == 'J')
                        for (int j = qb; j < i; j++)
                            s.at(j) = 'C';
                    else if (s.at(qb - 1) == 'J' && s.at(i) == 'C')
                        for (int j = qb; j < i; j++)
                            s.at(j) = 'J';
                }
            }
            else if (s.at(i) == '?' && i == s.length() - 1)
            {
                if (s.at(qb - 1) == 'C')
                    for (int j = qb; j <= i; j++)
                        s.at(j) = 'C';
                else if (s.at(qb - 1) == 'J')
                    for (int j = qb; j <= i; j++)
                        s.at(j) = 'J';
                else if (s.at(qb - 1) == 'C')
                    for (int j = qb; j <= i; j++)
                        s.at(j) = 'C';
                else if (s.at(qb - 1) == 'J')
                    for (int j = qb; j <= i; j++)
                        s.at(j) = 'J';
            }
        }
        cout << "Case #" << tc << ": " << cost(x, y, s) << "\n";
    }
}
