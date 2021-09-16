#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int ones = 0;
    for (int i = 0; i < n; i++) {
    	int curr;
    	cin >> curr;
    	ones += curr;
    }
    cout << ((n == 1 && ones == 1) || (n != 1 && ones == n-1) ? "YES" : "NO") << endl;

	return 0;
}