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
    int baseCases = m % 6;
    int len = ((m - baseCases) / 6);
    vector<long long[4]> dp(len + 1);
    for (int i = 0; i < 4; i++) {
    	dp[0][i] = 0;
    }
    // (cost, numTres, numDos, numUno)
    
    for (int i = baseCases; i < len; i++) {
    	long long numTres = dp[i][1];
    	long long numDos = dp[i][2];
    	long long numUno = dp[i][3];
    	long long cost1 = 0;
    	if (numTres < (int)tres.size() - 1) {
    		cerr << "pls no" << endl;
    		// 2 3-cost
    		cost1 = dp[i][0] + tres[numTres] + tres[numTres+1];
    	}
    	cerr << "HI" << endl;
    	long long cost2 = 0;
    	if (numTres < (int)tres.size() && numUno < (int)uno.size() - 2) {
    		// 1 3-cost 3 1-cost
    		cost2 = dp[i][0] + tres[numTres] + uno[numUno] + uno[numUno+1] + uno[numUno+2];
    	}

    	long long cost3 = 0;
    	if (numTres < (int)tres.size() && numUno < (int)uno.size() && numDos < (int)dos.size()) {
    		// 1 3-cost 1 2-cost 1 1-cost
    		cost3 = dp[i][0] + tres[numTres] + uno[numUno] + dos[numDos];
    	}
    	long long cost4 = 0;
    	if (numDos < (int)dos.size() - 2) {
    		// 3 2-cost
    		cost4 = dp[i][0] + dos[numDos] + dos[numDos+1] + dos[numDos+2];
    	}

    	long long cost5 = 0;
    	if (numDos < (int)dos.size() - 1 && numUno < (int)uno.size() - 1) {
    		// 2 2-cost 2 1-cost
    		cost5 = dp[i][0] + dos[numDos] + dos[numDos+1] + uno[numUno] + uno[numUno+1];
    	}

    	long long cost6 = 0;
    	if (numDos < (int)dos.size() && numUno < (int)uno.size()-3) {
    		// 1 2-cost 4 1-cost
    		cost6 = dp[i][0] + dos[numDos] + uno[numUno] + uno[numUno+1] + uno[numUno+2] + uno[numUno+3];
    	}

    	long long cost7 = 0;
    	if (numUno < (int)uno.size()-5) {
    		// 6 1-cost
    		cost7 = dp[i][0] + uno[numUno] + uno[numUno+1] + uno[numUno+2] + uno[numUno+3] + uno[numUno+4] + uno[numUno+5];
    	}
    	long long maxCost = max(cost1, max(cost2, max(cost3, max(cost4, max(cost5, max(cost6, cost7))))));
    	cerr << maxCost << endl;
    	dp[i+1][0] = maxCost;
    	if (maxCost == cost1) {
    		dp[i+1][1] = numTres + 2;
    		dp[i+1][2] = numDos;
    		dp[i+1][3] = numUno;
    	} else if (maxCost == cost2) {
    		dp[i+1][1] = numTres + 1;
    		dp[i+1][2] = numDos;
    		dp[i+1][3] = numUno + 3;
    	} else if (maxCost == cost3) {
    		dp[i+1][1] = numTres + 1;
    		dp[i+1][2] = numDos + 1;
    		dp[i+3][3] = numUno + 1;
    	} else if (maxCost == cost4) {
    		dp[i+1][1] = numTres;
    		dp[i+1][2] = numDos + 3;
    		dp[i+3][3] = numUno; 
    	} else if (maxCost == cost5) {
    		dp[i+1][1] = numTres;
    		dp[i+1][2] = numDos + 2;
    		dp[i+3][3] = numUno + 2;
    	} else if (maxCost == cost6) {
    		dp[i+1][1] = numTres;
    		dp[i+1][2] = numDos + 1;
    		dp[i+3][3] = numUno + 4;
    	} else if (maxCost == cost7) {
    		dp[i+1][1] = numTres;
    		dp[i+1][2] = numDos;
    		dp[i+3][3] = numUno + 6;
    	}
    }
    cout << dp.back()[0];

	return 0;
}