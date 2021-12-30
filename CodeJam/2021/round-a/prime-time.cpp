#include <bits/stdc++.h>

using namespace std;

// vector<pair<int, int>> prime_factors(int n)
// {
//     vector<pair<int, int>> factors;
//     int index = 0;
//     if (n % 2 == 0)
//     {
//         n /= 2;
//         factors.push_back(make_pair(2, 1));
//         index++;
//     }
//     while (n % 2 == 0)
//     {
//         n /= 2;
//         factors.at(0).second++;
//     }
//     for (int i = 3; i <= n; i += 2)
//     {
//         if (n % i == 0)
//         {
//             n /= i;
//             factors.push_back(make_pair(i, 1));
//             index++;
//         }
//         while (n % i == 0)
//         {
//             n /= i;
//             factors.at(index).second++;
//         }
//     }
//     return factors;
// }

vector<int> prime_factors(int n)
{
    vector<int> factors;
    int index = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        factors.push_back(2);
    }
    for (int i = 3; i <= n; i += 2)
        while (n % i == 0)
        {
            n /= i;
            factors.push_back(i);
        }

    return factors;
}

int idx_in_vec(vector<int> vec, int to_find)
{
    auto lower = lower_bound(vec.begin(), vec.end(), to_find);
    const bool found = lower != vec.end() && *lower == to_find;
    if (found)
    {
        auto idx = distance(vec.begin(), lower);
        return idx;
    }
    else
        return -1;
}

int rec(vector<int> decka, vector<int> deckb, int sum, vector<int> factors)
{
    for (int i = 0; i < factors.size(); i++)
    {
        int idx = idx_in_vec(decka, factors.at(i));
        if (idx != -1)
        {
            cout << "Index of " << factors.at(i) << " is: " << idx << "\n";
            vector<int> newdecka = decka;
            newdecka.erase(newdecka.begin() + idx);
            vector<int> newdeckb = deckb;
            newdeckb.push_back(factors.at(i));
            int newsum = sum - factors.at(i);
            vector<int> newfactors = prime_factors(newsum);
            rec(newdecka, newdeckb, newsum, newfactors);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int m{};
        cin >> m;
        vector<int> decka;
        vector<int> deckb;
        int p{}, n{};
        int sum{};
        for (int i = 0; i < m; i++)
        {
            cin >> p;
            cin >> n;
            for (int i = 0; i < n; i++)
                decka.push_back(p);
            sum += (n * p);
        }
        vector<int> factors = prime_factors(sum);
        // cout << "[";
        // for (auto a : decka)
        //     cout << a << ",";
        // cout << "]\n";
        rec(decka, deckb, sum, factors);
    }
}
