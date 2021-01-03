#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{ };
    while (true) {
        cin >> n;
        if (n == 0) break;
        int temp{ };
        vector<int> key;
        for (int i=0; i < n; i++) {
            cin >> temp;
            key.push_back(temp);
        }
        string message{ };
        getline(cin, message);
        while ((message.length())%n != 0) message.push_back(' ');
        map<int, string> stringMap;
        
    }
}
