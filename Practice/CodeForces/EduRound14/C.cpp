#include <bits/stdc++.h>

using namespace std;

string trim(string s) {
	int startIdx = 0;
    int endIdx = s.size()-1;
    for (;startIdx < s.size(); startIdx++) {
    	if (s[startIdx] != '0') break;
    }
    for (;endIdx >= 0; endIdx--) {
    	if (s[endIdx] != '0') break;
    }
    string trimmed = s.substr(startIdx, endIdx-startIdx+1);
    return trimmed;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    int startIdx, endIdx;
    int decimalPoint = s.find('.');
    if (decimalPoint == -1) {
    	decimalPoint = s.size();
    	s.push_back('.');
    }
    string trimmed = trim(s);
    decimalPoint = trimmed.find('.');
    int E;
    if (decimalPoint == 0) {
    	E = -1 * trimmed.find_first_of("123456789");
    } else {
    	E = decimalPoint - 1;
    }
    trimmed.erase(decimalPoint, 1);
    trimmed = trim(trimmed);
    if (trimmed.size() != 1) {
    	trimmed.insert(1, 1, '.');
    }
    if (E==0) {
    	cout << trimmed << endl;
    } else {
    	cout << trimmed << "E" << to_string(E) << endl;
    }

	return 0;
}