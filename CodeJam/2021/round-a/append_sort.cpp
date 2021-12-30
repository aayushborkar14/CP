#include <bits/stdc++.h>

using namespace std;

string strslice(string str, int a, int b)
{
    string temp = "";
    for (int i = a; i < b; i++)
    {
        temp += str.at(i);
    }
    return temp;
}

bool only_nine(string a)
{
    bool is_nine = true;
    for (auto c : a)
    {
        if ((c - '0') != 9)
        {
            is_nine = false;
            break;
        }
    }
    return is_nine;
}

bool is_greater(string a, string b)
{
    if (a == b)
        return false;
    int lena = a.length();
    int lenb = b.length();
    if (lena > lenb)
        return true;
    else if (lena < lenb)
        return false;
    else if (lena == lenb)
    {
        for (int i = 0; i < lena; i++)
        {
            if (a.at(i) > b.at(i))
                return true;
            else if (a.at(i) < b.at(i))
                return false;
        }
    }
    return true;
}

string incre_str(string str)
{
    string newstr = str;
    for (int i = (str.length() - 1); i >= 0; i--)
    {
        char temp = str.at(i);
        if (temp != '9')
        {
            newstr.at(i) = static_cast<char>(str.at(i) + 1);
            break;
        }
        else
            newstr.at(i) = '0';
    }
    return newstr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n{};
        vector<long long int> x;
        vector<string> xs;
        cin >> n;
        string temp{};
        long long int ans{};
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            xs.push_back(temp);
        }
        for (int i = 1; i < n; i++)
        {
            if (is_greater(xs.at(i - 1), xs.at(i)))
            {
                int leni = xs.at(i).length();
                int leni1 = xs.at(i - 1).length();
                int len_diff = leni1 - leni;
                if (len_diff > 0)
                {
                    string xi1n = strslice(xs.at(i - 1), 0, leni);
                    if (is_greater(xs.at(i), xi1n))
                    {
                        for (int j = 0; j < len_diff; j++)
                        {
                            xs.at(i).append("0");
                            ans++;
                        }
                    }
                    else if (is_greater(xi1n, xs.at(i)))
                    {
                        for (int j = 0; j < (1 + len_diff); j++)
                        {
                            xs.at(i).append("0");
                            ans++;
                        }
                    }
                    else if (xs.at(i) == xi1n)
                    {
                        string xi1n_dash = strslice(xs.at(i - 1), leni, leni1);
                        if (only_nine(xi1n_dash))
                        {
                            for (int j = 0; j < (1 + len_diff); j++)
                            {
                                xs.at(i).append("0");
                                ans++;
                            }
                        }
                        else
                        {
                            xs.at(i) = incre_str(xs.at(i - 1));
                            ans += len_diff;
                        }
                    }
                }
                else if (len_diff == 0)
                {
                    xs.at(i).append("0");
                    ans++;
                }
            }
            else if (xs.at(i) == xs.at(i - 1))
            {
                xs.at(i).append("0");
                ans++;
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
}
