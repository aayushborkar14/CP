#include <bits/stdc++.h>

using namespace std;

// doesn't work :(
// one of the sample tc works with online gdb but not my local compiler

class node
{
public:
    int ax, ay;
    int bx, by;
    int steps;
    node(int ax1, int ay1, int bx1, int by1, int steps1)
    {
        ax = ax1;
        ay = ay1;
        bx = bx1;
        by = by1;
        steps = steps1;
    }
};

int minTurns(vector<string> board)
{
    int width = board.at(0).length();
    int height = board.size();
    bool visited[20][20][20][20];
    for (int ax = 0; ax < width; ax++)
    {
        for (int ay = 0; ay < height; ay++)
        {
            for (int bx = 0; bx < width; bx++)
            {
                for (int by = 0; by < height; by++)
                {
                    visited[ax][ay][bx][by] = false;
                }
            }
        }
    }

    queue<node> q;
    int ax1{}, ay1{}, bx1{}, by1{};
    bool foundA = false;
    bool foundB = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.at(i).length(); j++)
        {
            if (board.at(i).at(j) == 'A')
            {
                ax1 = i;
                ay1 = j;
                foundA = true;
            }
            else if (board.at(i).at(j) == 'B')
            {
                bx1 = i;
                by1 = j;
                foundB = true;
            }
            else if (foundA && foundB)
                break;
        }
        if (foundA && foundB)
            break;
    }

    node start = node(ax1, ay1, bx1, by1, 0);
    q.push(start);
    visited[start.ax][start.ay][start.bx][start.by] = true;

    while (!q.empty())
    {
        node top = q.front();
        q.pop();

        if (top.ax < 0 || top.ay < 0 || top.bx < 0 || top.by < 0)
            continue;
        if (top.ax >= width || top.ay >= height || top.bx >= width || top.by >= height)
            continue;
        if (board[top.ax][top.ay] == 'X' || board[top.bx][top.by] == 'X')
            continue;
        if (top.ax == top.bx && top.ay == top.by)
            continue;
        if (top.ax == start.bx && top.ay == start.by && top.bx == start.ax && top.by == start.ay)
            return top.steps;

        for (int delax = -1; delax <= 1; delax++)
        {
            for (int delay = -1; delay <= 1; delay++)
            {
                for (int delbx = -1; delbx <= 1; delbx++)
                {
                    for (int delby = -1; delby <= 1; delby++)
                    {
                        if (top.ax + delax == top.bx && top.ay + delay == top.by && top.bx + delbx == top.ax && top.by + delby == top.ay)
                            continue;
                        if (top.ax + delax < 0 && top.ay + delay < 0 && top.bx + delbx < 0 && top.by + delby < 0)
                            continue;
                        if (!visited[top.ax + delax][top.ay + delay][top.bx + delbx][top.by + delby])
                        {
                            visited[top.ax + delax][top.ay + delay][top.bx + delbx][top.by + delby] = true;
                            q.push(node(top.ax + delax, top.ay + delay, top.bx + delbx, top.by + delby, top.steps + 1));
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k{};
    cin >> k;
    vector<string> board(k);
    cin.ignore();
    for (int i = 0; i < k; i++)
    {
        getline(cin, board.at(i));
    }
    int width = board.at(0).length();
    cout << minTurns(board);
}
