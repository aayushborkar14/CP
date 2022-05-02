#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    while (t--)
    {
        int n{}, m{};
        cin >> n >> m;
        int temp1{}, temp2{};
        vector<vector<int>> adj(n + 1, vector<int>()); // adjacency list
        for (int i = 0; i < m; i++)
        {
            cin >> temp1 >> temp2;
            adj.at(temp1).push_back(temp2);
        }
        // BFS
        vector<int> d(n + 1, -1); // -1 is unvisited
        d.at(1) = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int u : adj.at(v))
            {
                if (d.at(u) == -1)
                {
                    d.at(u) = d.at(v) + 1;
                    q.push(u);
                }
            }
        }
        vector<vector<int>> g(n + 1, vector<int>()); // new adjacency list
        for (int v = 1; v < m + 1; v++)
        {
            for (int u : adj.at(v))
            {
                if (d.at(v) > d.at(u))
                    g.at(v).push_back(u);
            }
        }
    }
}
