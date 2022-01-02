#include <bits/stdc++.h>

using namespace std;

template <typename T>
class segment {
public:
	vector<T> arr;
	int n;

	segment(vector<T>& in) : n(in.size()) {
		arr.resize(4*n);
		build(in, 1, 0, n-1);
	}

	segment(int n, T init = T{}) {
		// DOESN'T WORK
		//vector<T> in(n);
		//segment(in);

		// WORKS
		segment(vector<T>(n, init));
	}

	void build(vector<T> a, int v, int tl, int tr) {
		if (tl == tr) {
			// size 1 segment
			arr[v] = a[tl];
		} else {
			int tm = (tl+tr) / 2;
			build(a, v*2, tl, tm);
			build(a, v*2+1, tm+1, tr);
			arr[v] = arr[v*2] + arr[v*2+1];
		}
	}

	// inclusive
	T sum(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return T{};
		}
		if (l == tl && r == tr) {
			return arr[v];
		}
		int tm = (tl + tr) / 2;
		return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
	}

	void inc(int v, int tl, int tr, int pos, T val) {
		if (tl == tr) {
			arr[tl] += val;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			inc(v*2, tl, tm, pos, val);
		} else {
			inc(v*2+1, tm+1, tr, pos, val);
		}
		arr[v] = arr[v*2] + arr[v*2 + 1];
	}

	void set(int v, int tl, int tr, int pos, T val) {
		if (tl == tr) {
			arr[tl] = val;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			set(v*2, tl, tm, pos, val);
		} else {
			set(v*2+1, tm+1, tr, pos, val);
		}
		arr[v] = arr[v*2] + arr[v*2 + 1];
	}

	T sum(int l, int r) {
		return sum(1, 0, n-1, l, r);
	}

	void inc(int pos, int v) {
		inc(1, 0, n-1, pos, v);
	}

	void set(int pos, int v) {
		set(1, 0, n-1, pos, v);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> fights(m);
    for (int i = 0; i < m; i++) {
    	cin >> fights[i][0] >> fights[i][1] >> fights[i][2];
    }

	return 0;
}