#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    long long res = (s[0] % 4 == 0) ? 1 : 0;
    for (int i = 1; i < s.size(); i++) {
    	if (stoi(s.substr(i-1,2)) % 4 == 0) {
    		res += i;
    	}
    	if (s[i] % 4 == 0) {
    		res++;
    	}
    }
    cout << res << endl;

	return 0;
}