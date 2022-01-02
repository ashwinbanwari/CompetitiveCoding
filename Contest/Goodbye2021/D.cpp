#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, x;
    	cin >> n;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	cin >> x;
        for (int& i : v) {
            i -= x;
        }
        long long ans = 1;
        vector<int> prev;
        prev.push_back(v[0]);
    	for (int i = 1; i < n; i++) {
            bool good = true;
            int sum = v[i];
            for (int i = 1; i <= 2 && i <= prev.size(); i++) {
                sum += *(prev.end() - i);
                if (sum < 0) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans++;
                prev.push_back(v[i]);
            } else {
                prev.clear();
            }
        }
        cout << ans << endl;
    }

	return 0;
}