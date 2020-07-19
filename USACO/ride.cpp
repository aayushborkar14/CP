/*
ID: aayushb14
TASK: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getNum(char c) {
    int ic = c - '@';
    return ic;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet{};
    string group{};
    fin >> comet >> group;
    int sum_group{1};
    int sum_comet{1};
    for (int i=0; i < group.length(); i++) {
        sum_group *= getNum(group[i]);
    }
    for (int i=0; i < comet.length(); i++) {
        sum_comet *= getNum(comet[i]);
    }
    if (sum_comet%47 == sum_group%47) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}