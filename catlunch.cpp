#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n{}, k{};
    cin >> n >> k;
    vector<int> vec;
    int temp{};
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vec.push_back(temp);
    }
    set<int> my_set(vec.begin(), vec.begin() + k);
    for (auto it = my_set.begin(); it != my_set.end(); ++it)
        cout << *it << "\n";
}
