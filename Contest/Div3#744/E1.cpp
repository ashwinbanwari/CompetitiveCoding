#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int N;
    	cin >> N;
    	vector<int> v(N);
    	for (int i = 0; i < N; i++) {
    		cin >> v[i];
    	}

    	deque<int> ans;
    	ans.push_front(v[0]);
    	for (int i = 1; i < N; i++) {
    		if (v[i] < ans[0]) {
    			ans.push_front(v[i]);
    		} else {
    			ans.push_back(v[i]);
    		}
    	}
    	for (int i = 0; i < N; i++) {
    		cout << ans[i] << " ";
    	}
    	cout << endl;
    }

	return 0;
}