#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x, y, a;
		cin >> x >> y >> a;
		int remainder = a % (x + y);
		if (remainder < x) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	return 0;
}
