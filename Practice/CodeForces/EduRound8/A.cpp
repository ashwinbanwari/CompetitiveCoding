#include <bits/stdc++.h>

using namespace std;


int powOfTwo(int a) {
	int res = 1;
	while (res * 2 <= a) {
		res *= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, b, p, m=0;
    cin >> n >> b >> p;
    int playersLeft = n;
    while (playersLeft != 1) {
    	int nextBattleSize = powOfTwo(playersLeft);
    	// cerr << playersLeft << "-=" << nextBattleSize/2 << endl;
    	m += nextBattleSize/2;
    	playersLeft -= nextBattleSize/2;
    }

    cout << (2*b+1) * m << " " << p*n << endl;

	return 0;
}