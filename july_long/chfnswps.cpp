#include <iostream>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

void printMaps(map<int, int> aMap, map<int, int> bMap) {
    cout << "aMap:\n";
    for (auto itr = aMap.begin(); itr != aMap.end(); itr++) {
        cout << itr->first << " " << itr->second << "\n";
    }
    cout << "\nbMap:\n";
    for (auto itr = bMap.begin(); itr != bMap.end(); itr++) {
        cout << itr->first << " " << itr->second << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    int n{ };
    cin >> t;
    while (t--) {
        cin >> n;
        int min_cost{ };
        int aTemp{ }, bTemp{ };
        map<int, int> aMap;
        map<int, int> bMap;
        map<int, int>::iterator aItr;
        map<int, int>::iterator bItr;
        for (int i=0; i < n; i++) {
            cin >> aTemp;
            aItr = aMap.find(aTemp);
            if (aItr != aMap.end()) {
                aItr->second++;
            } else {
                aMap.insert(pair<int, int>(aTemp, 1));
            }
        }
        for (int i=0; i < n; i++) {
            cin >> bTemp;
            bItr = bMap.find(bTemp);
            if (bItr != bMap.end()) {
                bItr->second++;
            } else {
                bMap.insert(pair<int, int>(bTemp, 1));
            }
        }
        if (aMap.size() >= bMap.size()) {
            for (aItr = aMap.begin(); aItr != aMap.end();) {
                if (bMap.count(aItr->first)) {
                    if (bMap.at(aItr->first) == aItr->second) {
                        bMap.erase(aItr->first);
                        aMap.erase(aItr++);
                    } else if (bMap.at(aItr->first) > aItr->second) {
                        bItr = bMap.find(aItr->first);
                        bItr->second -= aItr->second;
                        aMap.erase(aItr++);
                    } else {
                        aItr->second -= bMap.at(aItr->first);
                        bMap.erase(aItr->first);
                        aItr++;
                    }
                } else {
                    aItr++;
                }
            }
        } else {
            for (bItr = bMap.begin(); bItr != bMap.end();) {
                if (aMap.count(bItr->first)) {
                    if (aMap.at(bItr->first) == bItr->second) {
                        aMap.erase(bItr->first);
                        bMap.erase(bItr++);
                    } else if (aMap.at(bItr->first) > bItr->second) {
                        aItr = aMap.find(bItr->first);
                        aItr->second -= bItr->second;
                        bMap.erase(bItr++);
                    } else {
                        bItr->second -= aMap.at(bItr->first);
                        aMap.erase(bItr->first);
                        bItr++;
                    }
                }
            }
        }
        // cout << "aMap:\n";
        vector<int> aVec;
        vector<int> bVec;
        for (auto itr = aMap.begin(); itr != aMap.end(); itr++) {
            // cout << itr->first << " " << itr->second << "\n";
            for (int i=0; i < itr->second; i++) {
                aVec.push_back(itr->first);
            }
        }
        // cout << "\nbMap:\n";
        for (auto itr = bMap.begin(); itr != bMap.end(); itr++) {
            // cout << itr->first << " " << itr->second << "\n";
            for (int i=0; i < itr->second; i++) {
                bVec.push_back(itr->first);
            }
        }
        bool aTurn = false;
        if (aMap.begin()->first <= bMap.begin()->first) {
            aTurn = true;
        }
        while (aMap.size() > 1 || bMap.size() > 1) {
            if (aTurn) {
                int min = aMap.begin()->first;
                aMap.begin()->second--;
                bMap.rbegin()->second--;
                aItr = aMap.find(bMap.rbegin()->first);
                if (aItr != aMap.end()) {
                    aItr->second++;
                } else {
                    aMap.insert(pair<int, int>(bMap.rbegin()->first, 1));
                }
                bItr = bMap.find(min);
                if (bItr != bMap.end()) {
                    bItr->second++;
                } else {
                    bMap.insert(pair<int, int>(min, 1));
                }
                if (aMap.at(bMap.rbegin()->first) == bMap.rbegin()->second) {
                    aMap.erase(bMap.rbegin()->first);
                    bMap.erase(bMap.rbegin()->first);
                }
                aTurn = false;
                min_cost += min;
            } else {
                int min = bMap.begin()->first;
                bMap.begin()->second--;
                aMap.rbegin()->second--;
                bItr = bMap.find(aMap.rbegin()->first);
                if (bItr != bMap.end()) {
                    bItr->second++;
                } else {
                    bMap.insert(pair<int, int>(aMap.rbegin()->first, 1));
                }
                aItr = aMap.find(min);
                if (aItr != aMap.end()) {
                    aItr->second++;
                } else {
                    aMap.insert(pair<int, int>(min, 1));
                }
                if (bMap.at(aMap.rbegin()->first) == aMap.rbegin()->second) {
                    bMap.erase(aMap.rbegin()->first);
                    aMap.erase(aMap.rbegin()->first);
                }
                aTurn = true;
                min_cost += min;
            }
        }
        // printMaps(aMap, bMap);
        cout << min_cost << "\n";
    }
}
