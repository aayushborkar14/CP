#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n{ }, h{ };
	cin >> n >> h;
	vector<int> a;
	int sum{ };
	int temp{ };
	while (n--) {
		cin >> temp;
		a.push_back(temp);
	}
	for (auto height : a) {
		if (height > h) {
			sum += 2;
		} else {
			sum += 1;
		}
	}
	cout << sum;
	return 0;
}
