#include <bits/stdc++.h>

using namespace std;

class Bomb {
public:
	int x, y, explosion, id;
	Bomb(int x, int y, int explosion, int id) : x(x), y(y), explosion(explosion), id(id) {}
	Bomb() : x(-1), y(-1), explosion(-1), id(-1) {}
};

vector<Bomb> bombs;

bool xComparator(const int& x, const int& y) {
	Bomb& a = bombs[x];
	Bomb& b = bombs[y];
	// cerr << "Comparison : ";
	if (a.x == b.x) {
		// cerr << (a.y < b.y) << endl;
		return a.y < b.y;
	} else {
		// cerr << (a.x < b.x) << endl;
		return a.x < b.x;
	}
}

bool yComparator(const int& x, const int& y) {
	Bomb& a = bombs[x];
	Bomb& b = bombs[y];
	if (a.y == b.y) {
		return a.x < b.x;
	} else {
		return a.y < b.y;
	}
}

int fin(int a, vector<int>& group) {
	if (group[a] == a) {
		return a;
	}
	return group[a] = fin(group[a], group);
}

void uni(int a, int b, vector<int>& group) {
	group[fin(a, group)] = fin(b, group);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, k;
    	cin >> n >> k;
    	map<int, vector<int>> x;
		map<int, vector<int>> y;
    	bombs.assign(n, Bomb());
    	vector<int> group;
    	vector<int> explosionTimes(n, INT_MAX);
    	for (int i = 0; i < n; i++) {
    		int a, b, explode;
    		cin >> a >> b >> explode;
    		Bomb newBomb(a, b, explode, i);
    		x[a].push_back(i);
    		y[b].push_back(i);
    		group.push_back(i);
    		bombs[i] = newBomb;
    	}
    	// O(NlogN)
    	for (auto& p : x) {
	    	vector<int>& coords = p.second;
	    	sort(coords.begin(), coords.end(), yComparator);
	    	int master = 0;	
	    	for (int i = 1; i < coords.size(); i++) {
	    		if (bombs[coords[i]].y - bombs[coords[i-1]].y <= k) {
	    			uni(coords[master], coords[i], group);
	    		} else {
	    			master = i;
	    		}
	    	}
    	}

    	for (auto& p : y) {
	    	vector<int>& coords = p.second;
	    	sort(coords.begin(), coords.end(), xComparator);
	    	int master = 0;	
	    	for (int i = 1; i < coords.size(); i++) {
	    		if (bombs[coords[i]].x - bombs[coords[i-1]].x <= k) {
	    			uni(coords[master], coords[i], group);
	    		} else {
	    			master = i;
	    		}
	    	}
    	}

    	for (int i = 0; i < group.size(); i++) {
    		explosionTimes[fin(i, group)] = min(explosionTimes[fin(i, group)], bombs[i].explosion);
    	}
    	sort(explosionTimes.begin(), explosionTimes.end());
    	for (int i = n-1; i >= 0; i--) {
    		if (explosionTimes[i] == INT_MAX) {
    			explosionTimes.pop_back();
    		}
    	}
    	int idx = 0;
    	int i;
    	n = explosionTimes.size();
    	// O(N)
    	for (i = n-1; i >= 0 && i > idx; i--) {
    		// inv: i is the one we are exploding, idx is next to get set off
    		int time = n-1-i;
    		while (explosionTimes[idx] <= time && idx != i) {
    			idx++;
    		}
    		if (idx >= i) {
    			break;
    		}
    	}
    	cout << n-1-i << endl;
    }

	return 0;
}