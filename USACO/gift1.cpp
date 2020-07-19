/*
ID: aayushb14
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np{ };
    fin >> np;
    int np_copy = np;
    map<string, int> myMap;
    vector<string> names;
    string temp{ };
    while (np--) {
        fin >> temp;
        myMap.insert(pair<string, int>(temp, 0));
        names.push_back(temp);
    }
    string temp1{ };
    int temp2{ };
    int temp3{ };
    for (int i=0; i < np_copy; i++) {
        fin >> temp1 >> temp2 >> temp3;
        string temp4{ };
        if (temp3 != 0) {
            int moneyToGiveEach = temp2/temp3;
            myMap[temp1] += ((temp2%temp3) - temp2);
            while (temp3--) {
                fin >> temp4;
                myMap[temp4] += moneyToGiveEach;
            }
        }
    }
    map<string, int>::iterator myItr;
    for (auto name : names) {
        myItr = myMap.find(name);
        fout << myItr->first << " " << myItr->second << "\n";
    }
    return 0;
}