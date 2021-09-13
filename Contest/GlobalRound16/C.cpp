#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	string a,b;
    	cin >> a >> b;
    	int answer = 0;
    	bool seenOnes = false;
    	for (int i = 0; i < n; i++) {
    		int sum = (a[i]-'0')+(b[i]-'0');
    		// cerr << sum << endl;
    		if (sum == 1) {
    			answer+=2;
    			seenOnes = false;
    		} else if (seenOnes && sum == 0) {
    			answer += 2;
    			seenOnes = false;
    		} else if (sum == 0 && ((i!= n-1 && a[i+1]-'0' + b[i+1]-'0' <= 1) || i == n-1)) {
    			answer += 1;
    		} else if (sum == 0) {
    			answer += 2;
    			i++;
    		} else {
    			seenOnes = true;
    		}
    	}
    	cout << answer << endl;
    }

	return 0;
}