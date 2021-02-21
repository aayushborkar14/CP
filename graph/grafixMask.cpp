#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int r;
    int c;

    node(int a, int b)
    {
        r = a;
        c = b;
    }
};

bool filledNode[400][600] = {false};

int doFill(int r, int c)
{
    stack<node> s;
    s.push(node(r, c));
    int result{};
    while (!s.empty())
    {
        node top = s.top();
        s.pop();
        if (top.r < 0 || top.r >= 400)
            continue;
        if (top.c < 0 || top.c >= 600)
            continue;
        if (filledNode[top.r][top.c])
            continue;
        filledNode[top.r][top.c] = true;
        result++;

        s.push(node(top.r + 1, top.c));
        s.push(node(top.r - 1, top.c));
        s.push(node(top.r, top.c - 1));
        s.push(node(top.r, top.c + 1));
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rectangles[50][4];
    int num_of_rec{};
    cin >> num_of_rec;
    for (int i = 0; i < num_of_rec; i++)
    {
        cin >> rectangles[i][0] >> rectangles[i][1] >> rectangles[i][2] >> rectangles[i][3];
        for (int r = rectangles[i][0]; r <= rectangles[i][2]; r++)
        {
            for (int c = rectangles[i][1]; c <= rectangles[i][3]; c++)
            {
                filledNode[r][c] = true;
            }
        }
    }
    
    vector<int> answers;
    for (int r = 0; r < 400; r++)
    {
        for (int c = 0; c < 600; c++)
        {
            if (!filledNode[r][c])
                answers.push_back(doFill(r, c));
        }
    }
    sort(answers.begin(), answers.end());
    for (auto answer : answers)
        cout << answer << "\n";
}
