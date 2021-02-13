#include <bits/stdc++.h>

using namespace std;

long long int dp2[1000001];
long long int t[1000001];
long long int d[1000001];
long long int a[1000001];
long long int rec3(int n);
long long int reca(int n);
long long int recd(int n);

long long int mod = pow(10, 9) + 7;
long long int rec2(int n)
{
    if (dp2[n] == -1)
    {
        dp2[n] = (rec2(n - 2)%mod + rec2(n - 3)%mod)%mod;
    }
    return dp2[n];
}

long long int rec3(int n)
{
    if (t[n] == -1)
    {
        t[n] = (rec3(n - 1)%mod + (2 * recd(n - 2))%mod + rec3(n - 3)%mod)%mod;
    }
    return t[n];
}

long long int reca(int n)
{
    if (a[n] == -1)
    {
        a[n] = (rec3(n - 3)%mod + reca(n - 3)%mod)%mod;
    }
    return a[n];
}

long long int recd(int n)
{
    if (d[n] == -1)
    {
        d[n] = (recd(n - 3)%mod + reca(n - 1)%mod)%mod;
    }
    return d[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nt{};
    cin >> nt;
    int n{}, k{};
    for (int i = 0; i < 1000001; i++)
    {
        dp2[i] = -1;
        a[i] = -1;
        d[i] = -1;
        t[i] = -1;
    }
    dp2[0] = 1;
    dp2[1] = 0;
    dp2[2] = 1;
    dp2[3] = 1;
    dp2[4] = 1;
    a[0] = 1;
    a[1] = 0;
    a[2] = 0;
    a[3] = 1;
    a[4] = 1;
    d[0] = 1;
    d[1] = 0;
    d[2] = 0;
    d[3] = 0;
    d[4] = 1;
    t[0] = 1;
    t[1] = 1;
    t[2] = 1;
    t[3] = 2;
    t[4] = 3;
    while (nt--)
    {
        cin >> k >> n;
        if (k == 1)
        {
            if (n % 3 == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (k == 2)
        {
            cout << rec2(n) << "\n";
        }
        else if (k == 3)
        {
            cout << rec3(n) << "\n";
        }
    }
}
