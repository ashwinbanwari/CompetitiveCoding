#include <bits/stdc++.h>

using namespace std;


void print(vector<string> v) {
	if (v.empty()) {
		cout << "-" << endl;
		return;
	}
	cout << "\"";
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it;
		if (it != v.end() - 1) {
			cout << ",";
		}
	}
	cout << "\"" << endl;
}

bool isNum(string& s) {
	if (s.size() == 0) {
		return false;
	}
	if ((s[0] == '0' && s.size() != 1) || s[0] < '0' || s[0] > '9') {
		return false;
	}
	for (int i = 1; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    vector<string> nums;
    vector<string> strings;
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
    	if (s[i] == ',' || s[i] == ';') {
    		// new word
    		string curr = s.substr(start, i-start);
    		cerr << curr << endl;
    		if (isNum(curr)) {
    			nums.push_back(curr);
    		} else {
    			strings.push_back(curr);
    		}
    		start = i+1;
    	}
    }
    string last = s.substr(start, string::npos);
	if (isNum(last)) {
		nums.push_back(last);
	} else {
		strings.push_back(last);
	}

	print(nums);
	print(strings);

	return 0;
}