#include <bits/stdc++.h>

using namespace std;

int numDigits(int i) {
	if (i==0) {
		return 1;
	}
	int curr = 0;
	while (i!=0) {
		i/=10;
		curr++;
	}
	return curr;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	int digits = numDigits(n);
    }

	return 0;
}