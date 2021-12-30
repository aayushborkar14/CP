#include <bits/stdc++.h>

using namespace std;

vector<int> prepare_vec1(int a1, int a2, int a3, int m)
{
    vector<int> vec1;
    if (m == a1)
    {
        vec1.push_back(a2);
        vec1.push_back(a1);
        vec1.push_back(a3);
    }
    else if (m == a2)
    {
        vec1.push_back(a1);
        vec1.push_back(a2);
        vec1.push_back(a3);
    }
    else if (m == a3)
    {
        vec1.push_back(a1);
        vec1.push_back(a3);
        vec1.push_back(a2);
    }
    return vec1;
}

vector<int> prepare_vec2(int a1, int a2, int a3, int m)
{
    vector<int> vec2;
    if (m == a1)
    {
        vec2.push_back(a3);
        vec2.push_back(a1);
        vec2.push_back(a2);
    }
    else if (m == a2)
    {
        vec2.push_back(a3);
        vec2.push_back(a2);
        vec2.push_back(a1);
    }
    else if (m == a3)
    {
        vec2.push_back(a2);
        vec2.push_back(a3);
        vec2.push_back(a1);
    }
    return vec2;
}

// vec1.size() >= vec1.size() && vec2.size() == 3
vector<vector<int>> correspond_same(vector<int> vec1, vector<int> vec2)
{
    vector<vector<int>> vec;
    vec.push_back(vector<int>());
    vec.push_back(vector<int>());
    vec.at(0).push_back(0); // vec1 idx1
    vec.at(0).push_back(0); // vec1 idx2
    vec.at(1).push_back(0); // vec2 idx1
    vec.at(1).push_back(0); // vec2 idx2
    bool idx2 = false;
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec2.size(); j++)
        {
            if (vec1.at(i) == vec2.at(j))
            {
                if (idx2)
                {
                    vec.at(0).at(1) = i;
                    vec.at(1).at(1) = j;
                }
                else
                {
                    idx2 = true;
                    vec.at(0).at(0) = i;
                    vec.at(1).at(0) = j;
                }
            }
        }
    }
    return vec;
}

// vec1.size() >= vec1.size() && vec2.size() == 3
vector<int> mergevec(vector<int> vec1, vector<int> vec2, vector<vector<int>> samevec)
{
    vector<int> vec;
    if (samevec.at(1).at(0) == 0 && samevec.at(1).at(1) == 1)
    {

        if (samevec.at(0).at(1) == (vec1.size() - 1))
        {
            vec = vec1;
            vec.push_back(vec2.at(2));
        }
        else
        {
            vec.push_back(-1);
        }
    }
    else if (samevec.at(1).at(0) == 1 && samevec.at(1).at(1) == 2)
    {
        if (samevec.at(0).at(0) == 0)
        {
            vec.push_back(vec2.at(0));
            for (auto num : vec1)
                vec.push_back(num);
        }
        else
        {
            vec.push_back(-1);
        }
    }
    else if (samevec.at(1).at(0) == 0 && samevec.at(1).at(1) == 2)
    {
        if ((samevec.at(0).at(1) - samevec.at(0).at(0)) == 1)
        {
            for (int i = 0; i <= samevec.at(0).at(0); i++)
                vec.push_back(vec1.at(i));
            vec.push_back(vec2.at(1));
            for (int i = samevec.at(0).at(1); i < vec1.size(); i++)
                vec.push_back(vec1.at(i));
        }
        else
        {
            vec.push_back(-1);
        }
    }
    return vec;
}

int main()
{
    int t{}, n{}, q{};
    cin >> t >> n >> q;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << 1 << " " << 2 << " " << 3 << endl;
        int m1{};
        cin >> m1;
        vector<int> vec = prepare_vec1(1, 2, 3, m1);
        int choice1{}, choice2{};
        if (m1 == 1)
        {
            choice1 = 2;
            choice2 = 3;
        }
        else if (m1 == 2)
        {
            choice1 = 1;
            choice2 = 3;
        }
        else if (m1 == 3)
        {
            choice1 = 1;
            choice2 = 2;
        }
        int current_num = 4;
        int mtemp{};
        for (int i = 4; i <= n; i++)
        {
            bool flag = false;
            cout << i << " " << m1 << " " << choice1 << endl;
            cin >> mtemp;
            vector<int> vec1 = prepare_vec1(i, m1, choice1, mtemp);
            vector<int> vec2 = prepare_vec2(i, m1, choice1, mtemp);
            vector<vector<int>> same1 = correspond_same(vec, vec1);
            vector<vector<int>> same2 = correspond_same(vec, vec2);
            int defaultvec{};
            if (same1.at(1).at(0) < same1.at(1).at(1))
            {
                vector<int> vtem = mergevec(vec, vec1, same1);
                if (vtem.at(0) == -1)
                    flag = false;
                else
                {
                    vec = vtem;
                    flag = true;
                    if (mtemp == i)
                    {
                        choice2 = choice1;
                        choice1 = m1;
                    }
                    else if (mtemp == m1)
                    {
                        choice2 = choice1;
                        choice1 = i;
                    }
                    else if (mtemp == choice1)
                    {
                        choice1 = i;
                        choice2 = m1;
                    }
                }
            }
            else if (same2.at(1).at(0) < same2.at(1).at(1))
            {
                vector<int> vtem = mergevec(vec, vec2, same2);
                if (vtem.at(0) == -1)
                    flag = false;
                else
                {
                    vec = vtem;
                    flag = true;
                    if (mtemp == i)
                    {
                        choice2 = choice1;
                        choice1 = m1;
                    }
                    else if (mtemp == m1)
                    {
                        choice2 = choice1;
                        choice1 = i;
                    }
                    else if (mtemp == choice1)
                    {
                        choice1 = i;
                        choice2 = m1;
                    }
                }
            }
            if (!flag)
            {
                bool flag = false;
                cout << i << " " << m1 << " " << choice2 << endl;
                cin >> mtemp;
                vector<int> vec1 = prepare_vec1(i, m1, choice2, mtemp);
                vector<int> vec2 = prepare_vec2(i, m1, choice2, mtemp);
                vector<vector<int>> same1 = correspond_same(vec, vec1);
                vector<vector<int>> same2 = correspond_same(vec, vec2);
                int defaultvec{};
                if (same1.at(1).at(0) < same1.at(1).at(1))
                {
                    vector<int> vtem = mergevec(vec, vec1, same1);
                    if (vtem.at(0) == -1)
                        flag = false;
                    else
                    {
                        vec = vtem;
                        flag = true;
                        if (mtemp == i)
                        {
                            choice1 = m1;
                            choice2 = choice2;
                        }
                        else if (mtemp == m1)
                        {
                            choice1 = i;
                            choice2 = choice2;
                        }
                        else if (mtemp == choice2)
                        {
                            choice1 = i;
                            choice2 = m1;
                        }
                    }
                }
                else if (same2.at(1).at(0) < same2.at(1).at(1))
                {
                    vector<int> vtem = mergevec(vec, vec2, same2);
                    if (vtem.at(0) == -1)
                        flag = false;
                    else
                    {
                        vec = vtem;
                        flag = true;
                        if (mtemp == i)
                        {
                            choice1 = m1;
                            choice2 = choice2;
                        }
                        else if (mtemp == m1)
                        {
                            choice1 = i;
                            choice2 = choice2;
                        }
                        else if (mtemp == choice2)
                        {
                            choice1 = i;
                            choice2 = m1;
                        }
                    }
                }
            }
            m1 = mtemp;
        }
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec.at(i);
            if (i == (vec.size() - 1))
                cout << endl;
            else
                cout << " ";
        }
    }

    // testing code
    // int size1{}, size2{};
    // cin >> size1 >> size2;
    // vector<int> vec1, vec2;
    // int temp{};
    // for (int i = 0; i < size1; i++)
    // {
    //     cin >> temp;
    //     vec1.push_back(temp);
    // }
    // for (int i = 0; i < size2; i++)
    // {
    //     cin >> temp;
    //     vec2.push_back(temp);
    // }
    // cout << correspond_same(vec1, vec2);
}
