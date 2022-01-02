#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K;
    cin >> N >> K;
    cout << K * (int)pow(K-1, N-1) << endl;

	return 0;
}