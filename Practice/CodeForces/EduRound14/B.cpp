#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	unordered_map<char, char> m;
	m['A']='A';
	m['b']='d';
	m['d']='b';
	m['H']='H';
	m['I']='I';
	m['M']='M';
	m['O']='O';
	m['o']='o';
	m['T']='T';
	m['U']='U';
	m['V']='V';
	m['v']='v';
	m['W']='W';
	m['w']='w';
	m['X']='X';
	m['x']='x';
	m['Y']='Y';
	m['p']='q';
	m['q']='p';
    string s;
    cin >> s;
    for (int i = 0; i < s.size()/2 + 1; i++) {
    	if (s[i] != m[s[s.size()-i-1]]) {
    		cout << "NIE" << endl;
    		return 0;
    	}
    }
	cout << "TAK" << endl;
	return 0;
}