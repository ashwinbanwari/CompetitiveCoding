#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> tres;
    vector<int> dos;
    vector<int> uno;
    for (int i = 0; i < n; i++) {
    	int weight, cost;
    	cin >> weight >> cost;
    	switch(weight) {
    		case 3:
    			tres.push_back(cost);
    			break;
    		case 2:
    			dos.push_back(cost);
    			break;
    		case 1:
    			uno.push_back(cost);
    			break;
    	}
    }
    sort(tres.begin(), tres.end(), greater<int>());
    sort(dos.begin(), dos.end(), greater<int>());
    sort(uno.begin(), uno.end(), greater<int>());
    int len = 2 * dos.size() + uno.size();
    vector<long long[3]> dp(len+1);
    for (int i = 0; i < 3; i++) {
    	dp[0][i] = 0;
    }
    for (int i = 1; i <= len; i++) {
    	long long cost1 = dp[i-1][0];
    	if (dp[i-1][2] < uno.size()) {
    		cost1 = dp[i-1][0] + uno[dp[i-1][2]];
    	}
    	long long cost2 = 0;
    	if (i != 1 && dp[i-2][1] < dos.size()) {
    		cost2 = dp[i-2][0] + dos[dp[i-2][1]];
    	}
    	if (cost1 > cost2) {
    		dp[i][0] = cost1;
    		dp[i][1] = dp[i-1][1];
    		dp[i][2] = dp[i-1][2]+1;
    	} else {
    		dp[i][0] = cost2;
    		dp[i][1] = dp[i-2][1] + 1;
    		dp[i][2] = dp[i-2][2];
    	}
    }
    int bestIdx = min(len, m);
    long long best = dp[bestIdx][0];
    long long currTreses = 0;
    for (int i = 0; i < tres.size(); i++) {
    	currTreses += tres[i];
    	int used = 3 * (i+1);
    	if (m-used >= 0) {
    		if (m-used <= len) {
    			best = max(best, dp[m-used][0] + currTreses);
    		} else {
    			best = max(best, dp.back()[0] + currTreses);
    		}
    		
    	}
    }
    cout << best << endl;
	return 0;
}