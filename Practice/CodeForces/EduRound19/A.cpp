#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    multiset<int> ans;
    for (int i = 0; i < k-1; i++) {
    	for (int i = 2; i <= n; i++) {
    		if (n % i == 0) {
    			ans.insert(i);
    			n /= i;
    			break;
    		}
    	}
    }
    if (n != 1) {
    	ans.insert(n);
    }
    if (ans.size() != k) {
    	 cout << -1 << endl;
    } else {
    	for (int i : ans) {
    		cout << i << " ";
    	}
    }


	return 0;
}