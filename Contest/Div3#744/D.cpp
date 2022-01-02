#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int N;
    	cin >> N;
    	set<pair<int, int>> a;
    	for (int i = 0; i < N; i++) {
    		int temp;
    		cin >> temp;
    		a.insert({temp, i+1});
    	}
    	vector<pair<int, int>> ans;
    	while(true) {
    		auto p = *prev(a.end());
    		auto p2 = *(prev(prev(a.end())));
    		if (p2.first == 0) {
    			break;
    		}
			ans.push_back({p.second, p2.second});
			a.erase(p);
			a.erase(p2);
			p.first--;
			a.insert(p);
			p2.first--;
			a.insert(p2);
    	}
    	cout << ans.size() << endl;
    	for (int i = 0; i < ans.size(); i++) {
    		cout << ans[i].first << " "<< ans[i].second << endl;
    	}
    }

	return 0;
}