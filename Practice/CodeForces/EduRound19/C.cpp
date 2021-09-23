#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    string t;
    string v;
    int idx = 0;
    multiset<char> letters(s.begin(), s.end());
    while (!letters.empty()) {
    	/*
    	cerr << idx << " " << letters.size() << endl;
    	cerr << t << " | " << v << endl;
    	for (char i : letters) {
    		cerr << i << endl;
    	}*/
    	if (!t.empty() && t.back() <= *letters.begin()) {
    		v.push_back(t.back());
    		t.pop_back();
    	} else {
    		t.push_back(s[idx]);
    		idx++;
    		// remove_one_of
    		letters.erase(letters.find(s[idx-1]));
    	}
    }
    reverse(t.begin(), t.end());
    cout << v << t << endl;
	return 0;
}