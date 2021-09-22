#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<long long> heroes(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
    	cin >> heroes[i];
    	sum += heroes[i];
    }
    sort(heroes.begin(), heroes.end());
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
    	long long dragdefense, dragattack;
    	cin >> dragdefense >> dragattack;
    	// either hero right below defense or hero right above defense shud slay za dragoon
    	long long ans1 = LLONG_MAX;
    	long long ans2 = LLONG_MAX;
    	auto belowSlayer = lower_bound(heroes.begin(), heroes.end(), dragdefense);
    	if (belowSlayer != heroes.end()) {
    		// hero above
    		// cerr << "above: " << *belowSlayer << endl;

    		long long powerNeeded = max(0LL, dragdefense - *belowSlayer);
    		long long defenseNeeded = max(0LL, dragattack - (sum - *belowSlayer));
    		ans1 = powerNeeded+defenseNeeded;
    	}
    	if (belowSlayer != heroes.begin()) {
    		// hero below
    		belowSlayer--;
    		// cerr << "below: " << *belowSlayer << endl;
    		long long powerNeeded = max(0LL, dragdefense - *belowSlayer);
    		long long defenseNeeded = max(0LL, dragattack - (sum - *belowSlayer));
    		ans2 = powerNeeded+defenseNeeded;
    	}
    	// cerr << ans1 << " " << ans2 << endl;
    	cout << min(ans1, ans2) << endl;
    }
	return 0;
}