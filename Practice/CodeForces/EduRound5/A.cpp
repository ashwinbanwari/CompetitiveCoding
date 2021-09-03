#include <bits/stdc++.h>

using namespace std;

void removeLeadingZeros(string& s) {
	int i = 0;
	while (i != s.size() && s[i] == '0') {
		i++;
	}
	s = s.substr(i);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b;
    cin >> a >> b;
    removeLeadingZeros(a);
    removeLeadingZeros(b);
    if (a.size() != b.size()) {
    	if (a.size() < b.size()) {
    		cout << "<" << endl;
    	} else {
    		cout << ">" << endl;
    	}
    	return 0;
    }
    int n = a.size();
    for (int i = 0; i < n; i++) {
    	if (a[i] == b[i]) {
    		continue;
    	}
    	if (a[i] < b[i]) {
    		cout << "<" << endl;
    	} else {
    		cout << ">" << endl;
    	}
    	return 0;
    }
    cout << "=" << endl;
	return 0;
}