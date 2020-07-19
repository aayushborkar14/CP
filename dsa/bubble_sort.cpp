#include <iostream>
#include <vector>

using namespace std;

void vec_swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(vector<int> &vec, int n) {
    bool swapped{ };
    for (int i=0; i<n-1; i++) {
        swapped = false;
        for (int j=0; j<n-i-1; j++) {
            if (vec.at(j) > vec.at(j+1)) {
                vec_swap(&vec.at(j), &vec.at(j+1));
                swapped = true;
            }
        }
        if (!swapped) {
            break;
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
    bubble_sort(vec, n);
    cout << "Sorted array: ";
    print_vec(vec);
}
