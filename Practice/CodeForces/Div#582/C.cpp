#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
    	long long n, m;
    	cin >> n >> m;
    	vector<long long> adds;
    	long long finalDigit = m % 10;
    	long long curr = finalDigit;
    	adds.push_back(curr);
    	while ((curr + finalDigit) % 10 != adds.front()) {
    		curr = (curr + finalDigit) % 10;
    		adds.push_back(curr);
    	}
    	/*for (int i : adds) {
    		cerr << i << " ";
    	}
    	cerr << endl;*/
    	long long sum = accumulate(adds.begin(), adds.end(), 0);
    	long long terms = n / m;
    	long long wholes = terms / adds.size();
    	long long excess = terms - wholes*adds.size();
    	long long ans = wholes * sum;
    	for (int i = 0; i < excess; i++) {
    		ans += adds[i];
    	}
    	cout << ans << endl;
    }

	return 0;
}