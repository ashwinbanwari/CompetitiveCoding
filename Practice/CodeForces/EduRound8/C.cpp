#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string res(n, 'a');
    for (int i = 0; i < n; i++) {
    	if (k == 0) {
    		res[i] = s[i];
    	}
    	if (s[i]-'a' > 'z'-s[i]) {
    		// diff from a longer
    		int diff = s[i]-'a';
    		if (k-diff < 0) {
    			char target = s[i]-k;
    			res[i] = target;
    			k=0;
    		} else {
    			res[i] = 'a';
    			k -= diff;
    		}
    	} else {
    		int diff = 'z'-s[i];
    		if (k-diff < 0) {
    			res[i] = s[i]+k;
    			k=0;
    		} else {
    			res[i] = 'z';
    			k-= diff;
    		}
    	}
    }
    if (k==0) {
    	cout << res << endl;
    } else {
    	cout << -1 << endl;
    }

	return 0;
}