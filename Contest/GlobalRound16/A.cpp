#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, s;
    	cin >> n >> s;
    	int a = (n/2) + 1;
    	cout << s / a << endl;
    }

	return 0;
}