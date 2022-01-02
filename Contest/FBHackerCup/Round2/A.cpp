#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
    	int N, M;
    	cin >> N >> M; // N rounds, M models
    	vector<int> S(M);
    	for (int i = 0; i < M; i++) {
    		cin >> S[i];
    	}

    	vector<vector<int>> P(N, vector<int>(M));
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			cin >> P[i][j];
    		}
    	}
    	vector<int> ans(M);
    	vector<bool> finished(M);
    	// check if any not with ans 0 can switch places
    	// check if any with 0 can switch places
    	// add ans for all others
    	for (int i = 0; i < N; i++) {
    		// put into unordered set
    		unordered_multiset<int> possibleStyles;
    		finished.assign(M, false);
    		for (int j = 0; j < M; j++) {
    			possibleStyles.insert(P[i][j]);
    		}
    		for (int j = 0; j < M; j++) {
    			if (possibleStyles.find(S[j])!=possibleStyles.end() && ans[j] != 0) {
    				finished[j] = true;
    				possibleStyles.erase(possibleStyles.find(S[j]));
    			}
    		}
    		for (int j = 0; j < M; j++) {
    			if (possibleStyles.find(S[j])!=possibleStyles.end() && ans[j] == 0) {
    				finished[j] = true;
    				possibleStyles.erase(possibleStyles.find(S[j]));
    			}
    		}
    		for (int j = 0; j < M; j++) {
    			if (!finished[j]) {
    				auto it = possibleStyles.begin();
    				S[j] = *it;
    				ans[j]++;
    				possibleStyles.erase(it);
    			}
    		}
    	}
    	long long res = 0;
    	for (int i = 0; i < M; i++) {
    		res += max(0, ans[i]-1);
    	}
    	cout << "Case #" << i << ": " << res << endl;
    }

	return 0;
}