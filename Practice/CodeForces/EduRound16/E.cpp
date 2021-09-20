#include <bits/stdc++.h>

using namespace std;

struct cringe {
	bool operator()(const pair<long long, long long>& a, const pair<long long, long long>& b) const {
		if (a.second == b.second) {
			return a.first < b.first;
		} else {
			return a.second < b.second;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    unordered_set<long long> seen;
    set<pair<long long, long long>, cringe> next;
    next.insert({0, 0});
    while (!next.empty()) {
    	auto p = *next.begin();
    	if (p.first == n) {
    		cout << p.second << endl;
    		return 0;
    	}
    	// cerr << p.first << " " << p.second << endl;
    	next.erase(next.begin());
    	seen.insert(p.first);
  		if (p.first+1 <= 2 * n && !seen.count(p.first+1) ) {
  			next.insert({p.first+1, p.second+x});
  		}
  		if (p.first-1 >= 0 && !seen.count(p.first-1)) {
  			next.insert({p.first-1, p.second+x});
  		}
  		if (p.first * 2 <= 2 * n && !seen.count(p.first * 2)) {
  			next.insert({p.first * 2, p.second+y});
  		}
    	
    }
    cout << -1 << endl;

	return 0;
}