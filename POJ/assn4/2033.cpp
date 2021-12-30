#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        string a;
        cin >> a;
        if (a.length() == 1)
            if (stoi(a) == 0)
                break;

        int n = a.length();
        vector<int> dp(n + 1, -1);
        dp.at(n) = 0;
        dp.at(n - 1) = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (((a.at(i) - '0') * 10) + (a.at(i + 1) - '0') <= 26)
            {
                if (i != n - 2)
                {
                    if (((a.at(i + 1) - '0') * 10) + (a.at(i + 2) - '0') <= 26)
                        dp.at(i) = (2 * dp.at(i + 1)) - 1;
                    else
                        dp.at(i) = 2 * dp.at(i + 1);
                }
                else
                    dp.at(i) = 2 * dp.at(i + 1);
            }
            else
                dp.at(i) = dp.at(i + 1);
        }
        cout << dp.at(0) << "\n";
    }
}
