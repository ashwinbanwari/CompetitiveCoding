#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int height = 1;
		int last = 0;
		bool dead = false;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (last == 0 && x ==0 && i != 0) {
				dead = true;
			}
			if (x == 1) {
				height += last*4 + 1;
			}
			last = x;
		}
		if (dead) {
			cout << -1 << endl;
		} else {
			cout << height << endl;
		}
	}

	return 0;
}