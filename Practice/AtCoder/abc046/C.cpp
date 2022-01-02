#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    long long x = 1, y = 1	;
    while (N--) {
    	int T, A;
    	cin >> T >> A;
    	long long multiplier = max((x+T-1)/T, (y+A-1)/A);
    	x = T*multiplier;
    	y = A*multiplier;
    }
    cout << x + y  << endl;

	return 0;
}