#include <bits/stdc++.h>

using namespace std;


bool isValid(string s) {
	// cerr << s << endl;
	return (s[0] >= 'a' && s[0] <= 'h' && s[1] >= 1+'0' && s[1] <= 8+'0');
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    int ans = 0;
    for (int i = -1; i < 2; i++) {
    	for (int j = -1; j < 2; j++) {
    		if (i == 0 && j == 0) {
    			continue;
    		}
    		string temp = s;
    		temp[0] += i;
    		temp[1] += j;
    		if (isValid(temp)) {
    			ans++;
    		}
    	}
    }
    cout << ans << endl;

	return 0;
}