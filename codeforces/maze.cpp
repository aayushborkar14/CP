#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> grid;
int n{}, m{}, k{}, s{};
int num_visited{};

void reset_visited()
{
    for (int i = 0; i < visited.size(); i++)
        for (int j = 0; j < visited.at(0).size(); j++)
            visited.at(i).at(j) = false;
    num_visited = 0;
}

void dfs(int i, int j)
{
    if (num_visited >= s - k)
        return;
    visited.at(i).at(j) = true;
    num_visited++;
    bool a{}, b{}, c{}, d{};
    a = true;
    b = true;
    c = true;
    d = true;
    if (i == 0)
        d = false;
    if (i == n - 1)
        c = false;
    if (j == 0)
        a = false;
    if (j == m - 1)
        b = false;
    if (a && grid.at(i).at(j - 1) == 0 && !visited.at(i).at(j - 1))
        dfs(i, j - 1);
    if (b && grid.at(i).at(j + 1) == 0 && !visited.at(i).at(j + 1))
        dfs(i, j + 1);
    if (c && grid.at(i + 1).at(j) == 0 && !visited.at(i + 1).at(j))
        dfs(i + 1, j);
    if (d && grid.at(i - 1).at(j) == 0 && !visited.at(i - 1).at(j))
        dfs(i - 1, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    string temp{};
    for (int i = 0; i < n; i++)
    {
        grid.push_back(vector<int>());
        visited.push_back(vector<bool>());
        cin >> temp;
        for (char c : temp)
        {
            if (c == '#')
                grid.at(i).push_back(1);
            else
            {
                grid.at(i).push_back(0);
                s++;
            }
            visited.at(i).push_back(false);
        }
    }
    int ifirst = 0;
    int jfirst = 0;
    bool tobreak{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid.at(i).at(j) == 0)
            {
                ifirst = i;
                jfirst = j;
                tobreak = true;
                break;
            }
        }
        if (tobreak)
            break;
    }
    dfs(ifirst, jfirst);
    int num_marked = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (grid.at(i).at(j) == 0 && !visited.at(i).at(j))
            {
                grid.at(i).at(j) = 2;
                num_marked++;
            }
            if (num_marked >= k)
                break;
        }
        if (num_marked >= k)
            break;
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.at(0).size(); j++)
        {
            if (grid.at(i).at(j) == 0)
                cout << '.';
            else if (grid.at(i).at(j) == 1)
                cout << '#';
            else if (grid.at(i).at(j) == 2)
                cout << 'X';
        }
        cout << "\n";
    }
}
