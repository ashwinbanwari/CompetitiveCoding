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
    	long long res = 0;
    	multiset<int> s;
    	s.insert(v[0]);
    	for (int i = 1; i < N; i++) {
    		auto it1 = lower_bound(s.begin(), s.end(), v[i]);
    		auto it2 = upper_bound(s.begin(), s.end(), v[i]);
    		int ifFront = distance(s.begin(), it1);
    		int ifBack = distance(it2, s.end());
    		res += min(ifFront, ifBack);
    		s.insert(v[i]);
    		// cerr << res << endl;
    	}
    	cout << res << endl;
    }

	return 0;
}