#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int h1, h2;
    int speed, slip;
    cin >> h1 >> h2 >> speed >> slip;
    if (speed - slip <= 0 && 8*speed+h1 < h2) {
    	cout << -1 << endl;
    	return 0;
    } else if (8*speed+h1 >= h2) {
    	cout << 0 << endl;
    	return 0;
    }
    cout << (h2-h1-8*speed + 12*(speed - slip) - 1) / (12*(speed - slip));

	return 0;
}