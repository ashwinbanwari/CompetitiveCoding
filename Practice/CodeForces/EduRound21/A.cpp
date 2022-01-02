#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int eps = 0.00000001;
    int n;
    cin >> n;
    if (n < 10) {
    	cout << 1 << endl;
    	return 0;
    }
    int base = (int)(log10(n));
    int digit1 = n / pow(10, base);
    cout << (digit1+1) * int(pow(10, base)+0.5) - n << endl;

	return 0;
}