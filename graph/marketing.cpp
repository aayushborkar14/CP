#include <bits/stdc++.h>

using namespace std;

// comments are for debug info since global var cannot be debugged in vscode

class node
{
public:
    vector<int> adj;
    bool visited = false;
    bool adult;
};

int k{};
vector<node> compete(k);
int ans{};

void displayNodeInfo(int n) {
    cout << "Node " << n << ":\n";
    cout << "visited = " << compete.at(n).visited << "\n";
    cout << "adult = " << compete.at(n).adult << "\n";
}

void doVisit(int n)
{
    if (!compete.at(n).visited)
    {
        compete.at(n).visited = true;
        compete.at(n).adult = true;
        if (ans == 0)
            ans = 2;
        else
            ans *= 2;
    }
    for (auto idx : compete.at(n).adj)
    {
        if (compete.at(idx).visited)
        {
            if (compete.at(n).visited)
            {
                if (compete.at(n).adult == compete.at(idx).adult)
                {
                    ans = 0;
                    break;
                }
            }
        }
        else
        {
            compete.at(idx).adult = !compete.at(n).adult;
            compete.at(idx).visited = true;
        }
    }
    // displayNodeInfo(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    compete.resize(k);
    string temp{};
    cin.ignore();
    for (int i = 0; i < k; i++)
    {
        getline(cin, temp);
        string temp2{};
        for (int j = 0; j < temp.length(); j++)
        {
            if (temp.at(j) == ' ')
            {
                int tempidx = stoi(temp2);
                compete.at(i).adj.push_back(tempidx);
                if (!count(compete.at(tempidx).adj.begin(), compete.at(tempidx).adj.end(), i))
                {
                    compete.at(tempidx).adj.push_back(i);
                }
                temp2 = "";
            }
            else
            {
                temp2 += temp.at(j);
                if (j == temp.length() - 1)
                {
                    int tempidx = stoi(temp2);
                    compete.at(i).adj.push_back(tempidx);
                    if (!count(compete.at(tempidx).adj.begin(), compete.at(tempidx).adj.end(), i))
                    {
                        compete.at(tempidx).adj.push_back(i);
                    }
                    temp2 = "";
                }
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        // cout << "For " << i << "\n";
        doVisit(i);
        if (ans == 0)
        {
            ans = -1;
            break;
        }
        // cout << "\n\n";
    }
    // for (int i = 0; i < k; i++)
    // {
    //     for (auto num : compete.at(i).adj)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans;
}
