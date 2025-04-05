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

    int n;
	string s;
	cin >> n >> s;

	int mult = 1;
	int counter = 0;
	int answer = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '0') {
			answer += mult * counter;
			counter = 0;
			mult *= 10;
		} else {
			counter++;
		}
	}
	
	answer += mult * counter;
	cout << answer << endl;
    
	return 0;
}
