#include <bits/stdc++.h>

using namespace std;

int k;

bool ok(int val, vector<int> ints) {
	int res = ints.size();
	if (*max_element(ints.begin(), ints.end()) > val) {
		return false;
	}
	for (int i = 1; i < ints.size(); i++) {
		if (ints[i] + ints[i-1] <= val) {
			res--;
			ints[i] += ints[i-1];
		}
	}
	return res <= k;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k;
    string s;
    cin.ignore();
    getline(cin, s);
    vector<int> ints;
    int currLen = 0;
    for (int i = 0; i < s.size(); i++) {
    	if (s[i] == ' ' || s[i] == '-') {
    		ints.push_back(currLen+1);
    		currLen = 0;
    	} else {
    		currLen++;
    	}
    }
    ints.push_back(currLen);
    int i = -1;
    int l = 0;
    int r = s.size();
    for (int k = r; k != 0; k /= 2) {
    	while (!ok(i+k, ints)) {
    		i+= k;
    	}
    }
    cout << i+1 << endl;

	return 0;
}