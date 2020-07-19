#include <iostream>
#include <vector>

using namespace std;

void vec_swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void insertion_sort(vector<int> &vec, int n) {
    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (vec.at(i) < vec.at(j)) {
                vec_swap(&vec.at(i), &vec.at(j));
                i--;
            }
        }
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
    insertion_sort(vec, n);
    cout << "Sorted array: ";
    print_vec(vec);
}
