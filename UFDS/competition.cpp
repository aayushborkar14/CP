#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, ai{}, bi{};
    cin >> n >> ai >> bi;
    vector<int> a, b;
    int temp{};
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    // r.at(i).first = ai-bi r.at(i).second = index in a/b
    vector<pair<int, int>> r;
    for (int i = 0; i < n; i++)
        r.push_back(make_pair(a.at(i) - b.at(i), i));
    struct
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.first > b.first;
        }
    } customGreat;
    sort(r.begin(), r.end(), customGreat);
    int sum{};
    for (int i = 0; i < ai; i++)
        sum += a.at(r.at(i).second);
    for (int i = 0; i < bi; i++)
        sum += b.at(r.at(n - i - 1).second);
    cout << sum << endl;
}
