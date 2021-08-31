#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    vector<int> v(26);

    for (char c : s) {
    	v[c-'a']++;
    }
    vector<int> theOdds;
    for (int i = 0; i < v.size(); i++) {
    	if (v[i]%2) {
    		theOdds.push_back(i);
    	}
    }
    for (int i = 0; i < theOdds.size() / 2; i++) {
    	v[theOdds[theOdds.size()-i-1]]--;
    	v[theOdds[i]]++;
    }
    

    string res;
    for (int i = 0; i < v.size(); i++) {
    	res.append(v[i]/2, i+'a');
    }
    if (theOdds.size() % 2) {
		res.append(1, theOdds[theOdds.size() / 2] + 'a');
    }
    for (int i = v.size() - 1; i >= 0; i--) {
    	res.append(v[i]/2, i+'a');
    }

    cout << res << endl;

	return 0;
}