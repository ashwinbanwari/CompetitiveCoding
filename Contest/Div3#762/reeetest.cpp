#include <bits/stdc++.h>

using namespace std;

class Bomb {
public:
	int x, y, explosion;
	Bomb(int x, int y, int explosion) : x(x), y(y), explosion(explosion) {}
	Bomb() : x(-1), y(-1), explosion(-1) {}
};


bool xComparator(const Bomb& a, const Bomb& b) {
	cerr << "Comparison : ";
	if (a.x == b.x) {
		cerr << (a.y < b.y) << endl;
		return a.y < b.y;
	} else {
		cerr << (a.x < b.x) << endl;
		return a.x < b.x;
	}
}

int main() {
    vector<Bomb> bombs(10);
    Bomb newBomb(1, 2, 3);
    bombs[0] = newBomb;
    cerr << "hmm" << endl;
    cerr << bombs[1].x << endl;
	return 0;
}