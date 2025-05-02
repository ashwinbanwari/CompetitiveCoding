#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <climits>

using namespace std;
using ll = long long;


int volume(const string& word) {
	int cnt = 0;
	for (const char& c : word) {
		if (isupper(c)) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	getline(cin, s);
	getline(cin, s);

	int wordstart = 0;
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			string word = s.substr(wordstart, i - wordstart);
			res = max(res, volume(word));
			wordstart = i + 1;
		}
	}
	string word = s.substr(wordstart, s.size() - wordstart);
	res = max(res, volume(word));

	cout << res << endl;


    
	return 0;
}
