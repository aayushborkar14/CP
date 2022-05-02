#include <bits/stdc++.h>

using namespace std;

vector<long long int> sum;

struct UFDS
{
    vector<int> link, siz;
    UFDS(int n) : link(n), siz(n, 0) { iota(link.begin(), link.end(), 0); }
    int findRoot(int x)
    {
        if (x == link.at(x))
            return x;
        return findRoot(link.at(x));
    }
    bool same(int x, int y) { return findRoot(x) == findRoot(y); }
    bool unite(int x, int y)
    {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y)
            return false;
        if (siz.at(x) < siz.at(y))
            swap(x, y);
        siz.at(x) += siz.at(y);
        sum.at(x) += sum.at(y);
        link.at(y) = x;
        return true;
    }
    int size(int x) { return siz.at(findRoot(x)); }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n{};
    cin >> n;
    vector<int> a(n);
    vector<int> p(n);
    vector<long long int> ans(n);
    sum = vector<long long int>(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p.at(i);
        p.at(i)--;
        // sum.at(i) = 0;
    }
    UFDS ds(n);
    long long int cur{};
    for (int i = n - 1; i >= 0; i--)
    {
        ans.at(i) = cur;
        sum.at(p.at(i)) = a.at(p.at(i));
        ds.siz.at(p.at(i)) = 1;
        if (p.at(i) > 0)
            if (ds.siz.at(p.at(i) - 1) > 0)
                ds.unite(p.at(i) - 1, p.at(i));
        if (p.at(i) < n - 1)
            if (ds.siz.at(p.at(i) + 1) > 0)
                ds.unite(p.at(i), p.at(i) + 1);
        cur = max((long long)cur, (long long)sum.at(ds.findRoot(p.at(i))));
    }
    for (int i = 0; i < n; i++)
        cout << ans.at(i) << "\n";
}
