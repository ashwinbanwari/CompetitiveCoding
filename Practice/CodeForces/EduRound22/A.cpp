#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int timeNeeded = 0;
    for (int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	timeNeeded += a;
    }
    int bestAnswer = INT_MAX;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
    	int l, r;
    	cin >> l >> r;
    	if (l >= timeNeeded) {
    		bestAnswer = min(bestAnswer, l);
    	} else if (r >= timeNeeded) {
    		bestAnswer = timeNeeded;
    	}
    }
    if (bestAnswer == INT_MAX) {
    	cout << -1 << endl;
    } else {
    	cout << bestAnswer << endl;
    }

	return 0;
}