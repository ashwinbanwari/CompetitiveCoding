#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int W, H, N;
	cin >> W >> H >> N;
	vector<vector<int>> input;
	while (N--) {
		int x, y, a;
		cin >> x >> y >> a;
		input.push_back({x, y, a});
	}

	int x0 = 0;
	int xend = W;
	int y0 = 0;
	int yend = H;

	for (vector<int>& v : input) {
		switch(v[2]) {
			case 1:
				x0 = max(x0, v[0]);
				break;
			case 2: 
				xend = min(xend, v[0]);
				break;
			case 3:
				y0 = max(y0, v[1]);
				break;
			case 4:
				yend = min(yend, v[1]);
				break;
		}
	}

	int xLen = max(xend - x0, 0);
	int yLen = max(yend - y0, 0);

	cout << xLen * yLen << endl;

    
	return 0;
}
