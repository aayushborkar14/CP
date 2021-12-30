#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{};
    vector<int> d(31, -1);
    vector<int> a(31, -1);
    d.at(0) = 1;
    d.at(1) = 0;
    a.at(0) = 0;
    a.at(1) = 1;
    for (int i = 2; i <= 30; i++)
    {
        a.at(i) = d.at(i - 1) + a.at(i - 2);
        d.at(i) = d.at(i - 2) + (2 * a.at(i - 1));
    }
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        cout << d.at(n) << "\n";
    }
}
