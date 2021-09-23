#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    vector<int> kids(n);
    for (int i = 1; i <= n; i++) {
    	kids[i-1] = i;
    }
    for (int i = 0; i < k; i++) {
    	cin >> v[i];
    }

    int leaderIdx = 0;
    for (int i = 0; i < k; i++) {
    	int toDelete = (leaderIdx + v[i]) % kids.size();
    	cout << kids[toDelete] << " ";
    	kids.erase(kids.begin() + toDelete);
    	leaderIdx = toDelete % kids.size();
    }

    cout << endl;

	return 0;
}