#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    int score = 0;
    int papers = 0;
    for (int i = 0; i < s.size(); i++) {
    	if (s[i] == 'g') {
    		if (papers) {
    			papers--;
    			score++;
    		} else {
    			papers++;
    		}
    	} else {
    		if (papers) {
    			papers--;
    		} else {
    			papers++;
    			score--;
    		}
    	}
    }

    cout << score << endl;

	return 0;
}