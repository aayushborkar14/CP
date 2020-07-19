#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int merge(string &a, string &l, string &r) {
    int nL = l.length();
    int nR = r.length();
    int i = 0;
    int j = 0;
    int k = 0;
    int numInv = 0;
    while (i < nL && j < nR) {
        if (l.at(i) <= r.at(j)) {
            a.at(k) = l.at(i);
            i++;
        } else {
            a.at(k) = r.at(j);
            j++;
            numInv += nL-i;
        }
        k++;
    }
    while (i < nL) {
        a.at(k) = l.at(i);
        i++;
        k++;
    }
    while (j < nR) {
        a.at(k) = r.at(j);
        j++;
        k++;
    }
    return numInv;
}

int mergeSort(string &a) {
    int n = a.length();
    int numInv = 0;
    if (n <= 1) {
        return 0;
    }
    int mid = 0;
    if (n%2 == 0) {
        mid = n/2;
    } else {
        mid = (n+1)/2;
    }
    string l = a.substr(0, n/2);
    string r = a.substr(n/2);
    numInv += mergeSort(l);
    numInv += mergeSort(r);
    numInv += merge(a, l, r);

    return numInv;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<string> str_vec;
    string temp = "";
    multimap<int, int> inversions;
    for (int i=0; i < m; i++) {
        cin >> temp;
        str_vec.push_back(temp);
        inversions.insert(pair<int, int> (mergeSort(temp), i));
    }
    multimap<int, int>::iterator itr;
    for (itr = inversions.begin(); itr != inversions.end(); itr++) {
        cout << str_vec.at(itr->second) << "\n";
    }
}
