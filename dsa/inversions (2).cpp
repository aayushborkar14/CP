#include <iostream>
#include <vector>

using namespace std;

int num_of_inversion(vector<int> &vec, int n) {
    
}

int main() {
    int n{ };
    cout << "Enter the length of the array: ";
    cin >> n;
    vector<int> vec;
    int temp{ };
    for (int i=0; i<n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    cout << "The number of inversions in the array are " << num_of_inversion(vec, n);
}