#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int n;
    	cin >> n;
    	vector<char> bigram;
    	string s;
    	cin >> s;
    	bigram.push_back(s[0]);
    	bigram.push_back(s[1]);
    	for (int i = 1; i < n-2; i++) {
    		string s;
    		cin >> s;
    		if (s[0] != bigram.back()) {
    			bigram.push_back(s[0]);
    		}
    		bigram.push_back(s[1]);
    	}
    	if (bigram.size() != n) {
    		bigram.push_back('a');
    	}
    	for (char c : bigram) {
    		cout << c;
    	}
    	cout << endl;
    }

	return 0;
}