#include <bits/stdc++.h>

using namespace std;

long long lower(vector<int>& p, vector<int>& t) {
	int N = p.size();
	vector<int> fromLeft(N);
	vector<int> fromRight(N);
	fromLeft[0] = 0;
	fromRight[N-1] = 0;
	int ret = 0;
	for (int i = 1; i < N; i++) {
		int needed = t[i-1] - p[i-1];
		fromLeft[i] = max(fromLeft[i-1], needed);
	}

	for (int i = N-2; i >= 0; i--) {
		int needed = t[i+1] - p[i+1];
		fromRight[i] = max(fromRight[i+1], needed);
	}
	for (int i = 0; i < N; i++) {
		int delta = max(min(fromLeft[i], fromRight[i]), t[i]-p[i]);
		t[i] -= delta;
		ret = max(ret, delta);
	}
	return ret;
}

long long raise(vector<int>& p, vector<int>& t) {
	int N = p.size();
	vector<int> fromLeft(N);
	vector<int> fromRight(N);
	fromLeft[0] = 0;
	fromRight[N-1] = 0;
	int ret = 0;
	for (int i = 1; i < N; i++) {
		int needed = p[i-1] - t[i-1];
		fromLeft[i] = max(fromLeft[i-1], needed);
	}

	for (int i = N-2; i >= 0; i--) {
		int needed = p[i+1] - t[i+1];
		fromRight[i] = max(fromRight[i+1], needed);
	}
	for (int i = 0; i < N; i++) {
		int delta = max(min(fromLeft[i], fromRight[i]), p[i] - t[i]);
		//cerr << "I: " << i << " DELTA: " << delta << endl;
		//cerr << fromLeft[i] << " " << fromRight[i] << endl;
		t[i] += delta;
		ret = max(ret, delta);
	}
	return ret;
}

void print(vector<int>& t) {
	for (int i : t) {
		cerr << i << " ";
	}
	cerr << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

 	int N;
 	cin >> N;
 	vector<int> p(N);
 	vector<int> t(N);
 	for (int i = 0; i < N; i++) {
 		cin >> p[i];
 	}
 	for (int i = 0; i < N; i++) {
 		cin >> t[i];
 	}
 	long long ans = 0;
 	long long diff = -1;
 	bool toRaise = true;
 	while (diff != 0) {
 		if (toRaise) {
 			diff = raise(p, t);
 		} else {
 			diff = lower(p, t);
 		}
 		toRaise = !toRaise;
 		ans += diff;
 		//cerr << ans << endl;
 		//print(t);
 	}
 	cout << ans << endl;

	return 0;
}