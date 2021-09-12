#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    long long res = (n/k + 1) * k;
    cout << res << endl;

	return 0;
}