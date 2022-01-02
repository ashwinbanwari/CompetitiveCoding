#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	n--;
    	if (n%2 == 0) {
    		int a = n/2 + 1;
    		int b = n/2 - 1;
    		if (a % 2 == 0) {
    			a++;
    			b--;
    		}
    		cout << a << " " << b << " " << 1 << endl;
    	} else {
    		cout << n/2 << " " << (n/2+1) << " " << 1 << endl;
    	}
    }

	return 0;
}