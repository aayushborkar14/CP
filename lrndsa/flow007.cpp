#include <iostream>
using namespace std;

int reverse_num(int num) {
    int rev_num{ };
    
    while(num > 0) {
        rev_num = rev_num*10 + num%10;
        num /= 10;
    }
    
    return rev_num;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t{ }, num{ };
	cin >> t;
	while (t--) {
	    cin >> num;
	    cout << reverse_num(num) << "\n";
	}
	return 0;
}
