#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	long long n;
    	cin >> n;
    	unordered_set<long long> s;
    	for (long long i = 1; i*i <= n; i++) {
    		s.insert(i*i);
    	}
    	for (long long i = 1; i*i <= n && i*i*i <= n; i++) {
    		s.insert(i*i*i);
    	}
    	cout << s.size() << endl;
    }

	return 0;
}