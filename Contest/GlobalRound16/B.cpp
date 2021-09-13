#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
	    cin >> s;
	    int numSegments = 0;
	    bool inSegment = false;
	    for (int i = 0; i < s.size(); i++) {
	    	if (s[i] == '0' && !inSegment) {
	    		inSegment = true;
	    	} else if (s[i] == '1' && inSegment) {
	    		inSegment = false;
	    		numSegments++;
	    	}
	    }
	    if (inSegment) {
	    	numSegments++;
	    }

	    cout << min(2, numSegments) << endl;
	}
    

	return 0;
}