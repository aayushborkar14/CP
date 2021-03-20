#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int x;
    int y;
    int lives;
    node(int a, int b, int c)
    {
        x = a;
        y = b;
        lives = c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ofstream fout("escape.out");
    char board[501][501];
    for (int i = 0; i < 501; i++)
    {
        for (int j = 0; j < 501; j++)
        {
            board[i][j] = 'N';
        }
    }
    string deadly{};
    string harmful{};
    int d{}, h{};
    cin >> d;
    int x1{}, y1{}, x2{}, y2{};
    for (int i = 0; i < d; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int startx = min(x1, x2);
        int endx = max(x1, x2);
        int starty = min(y1, y2);
        int endy = max(y1, y2);
        for (int x = startx; x <= endx; x++)
        {
            for (int y = starty; y <= endy; y++)
            {
                board[x][y] = 'D';
            }
        }
    }
    cin >> h;
    for (int i = 0; i < d; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int startx = min(x1, x2);
        int endx = max(x1, x2);
        int starty = min(y1, y2);
        int endy = max(y1, y2);
        for (int x = startx; x <= endx; x++)
        {
            for (int y = starty; y <= endy; y++)
            {
                if (board[x][y] == 'D')
                    continue;
                board[x][y] = 'H';
            }
        }
    }
    int minLives{};
    bool visited[501][501];
    queue<node> q;
    node start = node(0, 0, 0);
    q.push(start);
    visited[start.x][start.y] = true;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        if (top.x < 0 || top.y < 0)
            continue;
        if (top.x > 500 || top.y > 500)
            continue;
        if (top.x == 500 && top.y == 500)
        {
            minLives = top.lives;
            break;
        }
        for (int del = -1; del <= 1; del += 2)
        {
            if (!visited[top.x + del][top.y])
            {
                visited[top.x + del][top.y] = true;
                if (board[top.x + del][top.y] == 'D')
                {
                    continue;
                }
                else if (board[top.x + del][top.y] == 'H')
                {
                    q.push(node(top.x + del, top.y, top.lives + 1));
                }
                else if (board[top.x + del][top.y] == 'N')
                {
                    q.push(node(top.x + del, top.y, top.lives));
                }
            }
            // for y coord
            for (del = -1; del <= 1; del += 2)
            {
                if (!visited[top.x][top.y + del])
                {
                    visited[top.x][top.y + del] = true;
                    if (board[top.x][top.y + del] == 'D')
                    {
                        continue;
                    }
                    else if (board[top.x][top.y + del] == 'H')
                    {
                        q.push(node(top.x, top.y + del, top.lives + 1));
                    }
                    else if (board[top.x][top.y + del] == 'N')
                    {
                        q.push(node(top.x, top.y + del, top.lives));
                    }
                }
            }
        }
    }
    if (q.empty())
        minLives = -1;
    cout << minLives;
    // for (int i = 0; i < 501; i++)
    // {
    //     for (int j = 500; j >= 0; j--)
    //     {
    //         fout << board[i][j] << " ";
    //     }
    //     fout << "\n";
    // }
}
