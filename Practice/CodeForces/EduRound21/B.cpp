#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    double numWeeks = n-k+1;
    vector<int> sleps(n);
    for (int i = 0; i < n; i++) {
    	cin >> sleps[i];
    }
    vector<long long> pref(n+1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
    	pref[i] = pref[i-1] + sleps[i-1];
    }
    double ans = 0;
    for (int i = 0; i < n+1-k; i++) {
    	ans += (pref[i+k] - pref[i]) / numWeeks;
    }
    cout << fixed << setprecision(6) << ans << endl;
	return 0;
}