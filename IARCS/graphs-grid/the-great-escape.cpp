#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_matrix;

bool bfs(int s, int t, vector<int> &pred, vector<int> &dist)
{
    int n = adj_matrix.at(0).size();
    vector<int> mark(n, 0);
    queue<int> gq;

    mark.at(s) = 1;
    dist.at(s) = 0;
    pred.at(s) = -1;
    gq.push(s);
    while (!gq.empty())
    {
        int u = gq.front();
        gq.pop();
        for (int i = 0; i < n; i++)
            if (adj_matrix.at(u).at(i) && !mark.at(i))
            {
                mark.at(i) = 1;
                dist.at(i) = dist.at(u) + 1;
                pred.at(i) = u;
                gq.push(i);

                if (i == t)
                    return true;
            }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, m{}, s{}, t{};
    int temp1{}, temp2{};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        adj_matrix.push_back(vector<int>());
        for (int j = 0; j < n; j++)
            adj_matrix.at(i).push_back(0);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        adj_matrix.at(temp1 - 1).at(temp2 - 1) = 1;
        adj_matrix.at(temp2 - 1).at(temp1 - 1) = 1;
    }
    cin >> s >> t;
    s--; // s is index of starting building
    t--; // t is index of target building
    vector<int> pred(n, 0);
    vector<int> dist(n, 0);
    if (!bfs(s, t, pred, dist))
        cout << 0;
    else
    {
        // vector<int> path;
        // int crawl = t;
        // path.push_back(crawl);
        // while (pred.at(crawl) != -1)
        // {
        //     path.push_back(pred.at(crawl));
        //     crawl = pred.at(crawl);
        // }
        cout << dist.at(t);
    }
}
