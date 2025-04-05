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

bool works(string& s) {
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'X') {
			count++;
		} else {
			count = 0;
		}
		if (count == 5) {
			return true;
		}
	}
	return false;
}

bool solve(string& s) {
	for (int i = 0;i < s.size(); i++) {
		if (s[i] == '.') {
			string cp = s;
			cp[i] = 'X';
			if (works(cp)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    vector<string> grid(10);
	for (int i = 0; i < 10; i++) {
		cin >> grid[i];
	}

	// rows
	bool good = false;
	for (int i = 0; i < grid.size(); i++) {
		if (solve(grid[i])) {
			good = true;
		}
	}

	// cols
	for (int i = 0; i < 10; i++) {
		string tmp;
		for (int j = 0; j < 10; j++) {
			tmp += grid[j][i];
		}
		if (solve(tmp)) {
			good = true;
		}
	}

	// main diags
	for (int i = 0; i < 10; i++) {
		string tmp;
		for (int j = 0; j < 10 - i; j++) {
			tmp += grid[j][i + j];
		}
		if (solve(tmp)) {
			good = true;
		}
	}

	for (int i = 0; i < 10; i++) {
		string tmp;
		for (int j = 0; j < 10 - i; j++) {
			tmp += grid[i + j][j];
		}
		if (solve(tmp)) {
			good = true;
		}
	}

	// secondary diags
	for (int i = 0; i < 10; i++) {
		string tmp;
		for (int j = 0; j <= i; j++) {
			tmp += grid[j][i - j];
		}
		if (solve(tmp)) {
			good = true;
		}
	}

	for (int row = 0; row < 10; row++) {
		string tmp;
		for (int i = 0; i < 10 - row; i++) {
			tmp += grid[row + i][9 - i];
		}
		if (solve(tmp)) {
			good = true;
		}
	}

	cout << (good ? "YES" : "NO") << endl;
	
    
	return 0;
}
