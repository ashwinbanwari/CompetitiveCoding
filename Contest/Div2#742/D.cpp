#include <bits/stdc++.h>

using namespace std;

int numDigits(int i) {
	if (i==0) {
		return 1;
	}
	int curr = 0;
	while (i!=0) {
		i/=10;
		curr++;
	}
	return curr;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int s, n;
    	cin >> s >> n;
    	vector<int> ans(n);
    	for (int i = 0; i < ans.size()-1; i++) {
    		int digits = numDigits(s);
    		long long nextToSteal = pow(10,digits-1);
    		while (s - nextToSteal < n-1-i) {
    			nextToSteal /= 10;
    		}
			ans[i] = nextToSteal;
			s -= nextToSteal;
    	}
    	ans[n-1] = s;
    	for (int i = 0; i < ans.size(); i++) {
    		cout << ans[i] << " ";
    	}
    	cout << endl;
    }

	return 0;
}