#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    int a = abs(x2-x1);
    int b = abs(y2-y1);

    if (a%x != 0 || b%y != 0) {
    	cout << "NO" << endl;
    	return 0;
    }
    if (a/x % 2 != b/y % 2) {
    	cout << "NO" << endl;
    } else {
    	cout << "YES" << endl;
    }

	return 0;
}