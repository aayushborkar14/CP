#include <bits/stdc++.h>

using namespace std;

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

bool is_greater(string a, string b)
{
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
}

int main()
{
    string a = "883377032";
    string b = "5279";
    cout << is_greater(a,b) << "\n" << is_greater("74432", "74431") << "\n" << is_greater("7653", "8672") << is_greater(b,a);
}
