#include <bits/stdc++.h>

using namespace std;

vector<int> group;

int fin(int a) {
	if (group[a] == a) return a;
	return group[a] = fin(group[a]);
}

void uni(int a, int b) {
	group[fin(group[a])] = fin(group[b]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    group.resize(n+1);
    for (int i = 1; i <= n; i++) {
    	group[i] = i;
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	uni(v[a-1],v[b-1]);
    }

    // group idx to the set of the things in that group, and the current idx we are at
    unordered_map<int, pair<int, vector<int>>> groupTo;
    for (int i = 0; i < n; i++) {
    	int group = fin(v[i]);
    	groupTo[group].second.push_back(v[i]);
    }
    for (auto& p : groupTo) {
    	auto& p2 = p.second;
    	p2.first = 0;
    	sort(p2.second.begin(), p2.second.end(), greater<int>());
    	/*cerr << p.first << endl;
    	for (int i : p2.second) {
    		cerr << i << " ";
    	}
    	cerr << endl;*/
    }
    for (int i = 0; i < n; i++) {
    	// cerr << fin(v[i]) << endl;
    	int group = fin(v[i]);
    	auto& p = groupTo[group];
    	cout << p.second[p.first] << " ";
    	p.first++;
    }

	return 0;
}