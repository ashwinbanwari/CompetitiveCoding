#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
	cin >> s;

	int diffs = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i-1]) {
			diffs++;
		}
	}

	cout << diffs << endl;
    
	return 0;
}
