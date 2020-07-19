#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void merge_sort(vector<int> &vec, int n) {
    if (n==1) {
        return;
    } 
    int index_count{ };
    if (n%2 == 0) {
        vector<int> vec1(vec.begin(), vec.begin() + n/2);
        vector<int> vec2(vec.begin() + n/2, vec.end());
        merge_sort(vec1, n/2);
        merge_sort(vec2, n/2);
        for (int i=0, j=0;;) {
            if (i >= (n/2)) {
                for (;j<(n/2); j++) {
                    vec.at(index_count) = vec2.at(j);
                    index_count++;
                }
                break;
            }
            if (j >= (n/2)) {
                for (;i<(n/2); i++) {
                    vec.at(index_count) = vec1.at(i);
                    index_count++;
                }
                break;
            }
            if (vec1.at(i) < vec2.at(j)) {
                vec.at(index_count) = vec1.at(i);
                i++;
            } else {
                vec.at(index_count) = vec2.at(j);
                j++;
            }
            index_count++;
        }
    } else {
        vector<int> vec1(vec.begin(), vec.begin() + ((n+1)/2));
        vector<int> vec2(vec.begin() + ((n+1)/2), vec.end());
        merge_sort(vec1, ((n+1)/2));
        merge_sort(vec2, ((n-1)/2));
        for (int i=0, j=0;;) {
            if (i >= ((n+1)/2)) {
                for (;j<((n-1)/2); j++) {
                    vec.at(index_count) = vec2.at(j);
                    index_count++;
                }
                break;
            }
            if (j >= ((n-1)/2)) {
                for (;i<((n+1)/2); i++) {
                    vec.at(index_count) = vec1.at(i);
                    index_count++;
                }
                break;
            }
            if (vec1.at(i) < vec2.at(j)) {
                vec.at(index_count) = vec1.at(i);
                i++;
            } else {
                vec.at(index_count) = vec2.at(j);
                j++;
            }
            index_count++;
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
    int n{ };
    cout << "Enter the length of the array: ";
    cin >> n;
    int input{ };
    vector<int> vec;
    cout << "Enter the elements of the array: ";
    for (int i=0; i<n; i++) {
        cin >> input;
        vec.push_back(input);
    }
    merge_sort(vec, n);
    cout << "The sorted array is: ";
    print_vec(vec);
}