#include <iostream>
#include <vector>

using namespace std;

//function to generate subsets from 1 to n (give k=1 to begin)
void generateSubsets(int k, int n, vector<vector<int>> subsets) {
    if (k == n+1) {
        return;
    }
    subsets.push_back(vector<int>());
    subsets.at(k-1).push_back(k);
    generateSubsets(k+1, n, subsets);
    subsets.push_back(vector<int>());
    generateSubsets(k+1, n, subsets);
}

void printVector(const vector<vector<int>> vec) {
    for (auto int_vec : vec) {
        cout << "{";
        for (auto elements : int_vec) {
            cout << elements << " ";
        }
        cout << "}\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> subsets;
    generateSubsets(1, 3, subsets);
    printVector(subsets);
}
