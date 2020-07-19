#include <iostream>
#include <vector>

using namespace std;

int num_of_cases(const vector<int> &x, int starting_index) {
    int back_count = starting_index-1;
    int current_index = starting_index;
    int front_count = starting_index+1;
    int num_of_infected = 1;
    while (back_count >= 0) {
        if (x.at(current_index) - x.at(back_count) <= 2) {
            num_of_infected++;
            current_index = x.at(back_count);
            back_count--;
        } else {
            break;
        }
    }
    current_index = starting_index;
    while (front_count < x.size()) {
        if (x.at(front_count) - x.at(current_index) <= 2) {
            num_of_infected++;
            current_index = front_count;
            front_count++;
        } else {
            break;
        }
    }
    return num_of_infected;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ }, n{ };
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> x;
        int temp{ };
        for (int i=0; i < n; i++) {
            cin >> temp;
            x.push_back(temp);
        }
        cout << num_of_cases(x, 3);
    }
}
