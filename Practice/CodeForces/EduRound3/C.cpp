#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> servers(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	cin >> servers[i];
    	tot += servers[i];
    }
    int need = tot/n;
    int extra = tot % n;
    int res = 0;
    sort(servers.begin(), servers.end(), greater<int>());
    for (int i = 0; i < servers.size(); i++) {
    	if (servers[i] <= need) {
    		break;
    	}
    	if (extra) {
    		res += (servers[i] - need - 1);
    		extra--;
    	} else {
    		res += servers[i] - need;
    	}
    }
    cout << res << endl;
	return 0;
}