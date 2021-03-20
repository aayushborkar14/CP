#include <bits/stdc++.h>

using namespace std;

// 2^15 = 32768 where number of weapons = 15
bool visited[32768];
int numWeapons{};
vector<string> damageChart;
vector<int> bossHealth;

class node
{
public:
    int weapons;
    int shots;

    node(int weapons1, int shots1)
    {
        weapons = weapons1;
        shots = shots1;
    }
};

int leastShots()
{
    priority_queue<node> pq;
    pq.push(node(0, 0));

    while (!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        if (visited[top.weapons])
            continue;
        visited[top.weapons] = true;
        // universal set of weapons = (1 << numWeapons) - 1
        if (top.weapons == (1 << numWeapons) - 1)
            return top.shots;
        for (int i = 0; i < damageChart.size(); i++)
        {
            // if (top.weapons&(1<<i))
            if ((top.weapons >> i) & 1)
                continue;
            int best = bossHealth[i];
            for (int j = 0; j < damageChart.size(); j++)
            {
                if (i == j)
                    continue;
                if (((top.weapons >> j) & 1) && damageChart.at(j).at(i) != '0')
                {
                    int shotsNeeded = bossHealth[i] / (damageChart.at(j).at(i) - '0');
                    if (bossHealth[i] % (damageChart.at(j).at(i) - '0') != 0)
                        shotsNeeded++;
                    best = min(best, shotsNeeded);
                }
            }
            pq.push(node(top.weapons | (1 << i), top.shots + best));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> numWeapons;
    string temp{};
    for (int i = 0; i < numWeapons; i++)
    {
        cin >> temp;
        damageChart.push_back(temp);
    }
    int temp2{};
    for (int i = 0; i < numWeapons; i++)
    {
        cin >> temp2;
        bossHealth.push_back(temp2);
    }
    cout << leastShots();
}
