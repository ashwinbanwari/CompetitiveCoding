#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> cities(n);
    vector<int> towers(m);
    for (int i = 0; i < n; i++) {
    	cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> towers[i];
    }

    vector<int> distances(n);
    for (int i = 0; i < n; i++) {
    	int less, more;
    	auto lessThan = lower_bound(towers.begin(), towers.end(), cities[i]); // or equal to
    	auto moreThan = upper_bound(towers.begin(), towers.end(), cities[i]);
    	if (*lessThan == cities[i]) {
    		distances[i] = 0;
    		continue;
    	}
    	if (lessThan == towers.begin()) {
    		less = INT_MAX;
    	} else {
    		less = abs(*(--lessThan) - cities[i]);
    	}
    	if (moreThan == towers.end()) {
    		more = INT_MAX;
    	} else {
    		more = abs(*moreThan-cities[i]);
    	}
    	distances[i] = min(more, less);
    }
    cout << *max_element(distances.begin(), distances.end()) << endl;
}