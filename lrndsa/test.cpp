#include <iostream>

using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int temp{ };
	while (true) {
	    cin >> temp;
	    if (temp != 42) {
	        cout << temp << "\n";
	    } else {
	        break;
	    }
	}
	return 0;
}
