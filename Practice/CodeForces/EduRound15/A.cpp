#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n);
    dp[0] = 1;
    int prev;
    cin >> prev;
    for (int i = 1; i < n; i++) {
    	int curr;
    	cin >> curr;
    	if (curr > prev) {
    		dp[i] = dp[i-1]+1;
    	} else {
    		dp[i] = 1;
    	}
    	prev = curr;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

	return 0;
}