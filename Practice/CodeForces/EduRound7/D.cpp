#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {
    	cout << i << " ";
    }
    for (int i = 1; i <= n; i++) {
    	cout << i << " ";
    }
    cout << endl;

	return 0;
}