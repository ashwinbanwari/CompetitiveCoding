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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b;
	cin >> a >> b;

	string lettersToAdd;
	
	unordered_map<char, int> aLetters;
	unordered_map<char, int> bLetters;

	for (int i = 0; i < a.size(); i++) {
		aLetters[a[i]]++;
	}
	for (int i = 0; i < b.size(); i++) {
		bLetters[b[i]]++;
	}

	while (lettersToAdd.size() < aLetters['?']) {
		for (const pair<const char, int>& p : bLetters) {
			aLetters[p.first] -= p.second;
			if (aLetters[p.first] < 0) {
				lettersToAdd += string(-aLetters[p.first], p.first);
				aLetters[p.first] = 0;
			}
		}
	}

	int lettersIdx = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '?') {
			a[i] = lettersToAdd[lettersIdx];
			lettersIdx++;
		}
	}

	cout << a << endl;
    
	return 0;
}
