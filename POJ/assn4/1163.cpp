#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{};
    cin >> n;
    int temp{};
    vector<vector<int>> triangle;
    vector<vector<int>> d;
    for (int i = 0; i < n; i++)
    {
        triangle.push_back(vector<int>());
        d.push_back(vector<int>());
        for (int j = 0; j <= i; j++)
        {
            cin >> temp;
            triangle.at(i).push_back(temp);
            d.at(i).push_back(-1);
        }
    }
    for (int j = 0; j <= n - 1; j++)
        d.at(n - 1).at(j) = triangle.at(n - 1).at(j);
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            d.at(i).at(j) = max(d.at(i + 1).at(j), d.at(i + 1).at(j + 1)) + triangle.at(i).at(j);
    cout << d.at(0).at(0);
}
