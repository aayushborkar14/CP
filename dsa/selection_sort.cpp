#include <iostream>
#include <vector>

using namespace std;

void vec_swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(vector<int> &vec, int n) {
    int min_index{ };
    for (int i=0; i<n-1; i++) {
        min_index = i;
        for (int j=i+1; j<n; j++) {
            if (vec.at(j) < vec.at(min_index)) {
                min_index = j;
            }
        }
        vec_swap(&vec.at(min_index), &vec.at(i));
    }
}

void print_vec(const vector<int> &vec) {
    int n = vec.size();
    for (int i=0; i<n; i++) {
        cout << vec.at(i) << " ";
    }
}

int main() {
    vector<int> vec;
    cout << "Enter the length of the array: ";
    int n{ };
    cin >> n;
    cout << "Enter the elements of array: ";
    int input{ };
    for (int i=0; i<n; i++) {
        cin >> input;
        vec.push_back(input);
    }
    cout << vec.size() << "\n";
    selection_sort(vec, n);
    cout << "Sorted array: ";
    print_vec(vec);
}
