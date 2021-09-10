#include <bits/stdc++.h>

using namespace std;

constexpr int END = pow(10,6);

long long nC2(int i) {
	return 0;
} 

long long sumUp(vector<unordered_map<int, int>>& v) {
	long long res = 0;
	for (int i = 0; i < v.size(); i++) {
		int seenBelow = 0;
		for (auto& p : v[i]) {
			long long sumHere = seenBelow * p.second;
			seenBelow += p.second;
			res += sumHere;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, m, k;
    	cin >> n >> m >> k;
    	vector<int> verts(n);
    	vector<int> horiz(m);
    	vector<pair<int, int>> people(k);
    	for (int i = 0; i < n; i++) {
    		cin >> verts[i];
    	}
    	for (int i = 0; i < m; i++) {
    		cin >> horiz[i];
    	}
    	for (int i = 0; i < k; i++) {
    		cin >> people[i].first >> people[i].second;
    	}

    	sort(verts.begin(), verts.end());
    	sort(horiz.begin(), horiz.end());
    	sort(people.begin(), people.end());


    	vector<unordered_map<int, int>> vertSegments(n-1);
    	int curr = 0;
    	for (int i = 1; i < n; i++) {
    		while (curr < people.size() && people[curr].first < verts[i]) {
	    		if (people[curr].first > verts[i-1]) {
	    			vertSegments[i-1][people[curr].second]++;
	    		}
	    		curr++;
	    	}
    	}

    	vector<unordered_map<int, int>> horizSegments(m-1);
    	sort(people.begin(), people.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {
    		return a.second < b.second;
    	});
    	curr = 0;
    	for (int i = 1; i < m; i++) {
    		while (curr < people.size() && people[curr].second < horiz[i]) {
	    		if (people[curr].second > horiz[i-1]) {
	    			horizSegments[i-1][people[curr].first]++;
	    		}
	    		curr++;
	    	}
    	}

    	cout << sumUp(vertSegments) + sumUp(horizSegments) << endl;
    }

	return 0;
}