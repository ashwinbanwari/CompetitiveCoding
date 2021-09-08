#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    int numRows = 2*n;
    for (int i = 0; i < numRows; i++) {
    	if (m - numRows > i) {
    		cout << i+numRows+1 << " ";
    	} if (m > i) {
    		cout << i+1 << " ";
    	}
    }
    cout << endl;

	return 0;
}