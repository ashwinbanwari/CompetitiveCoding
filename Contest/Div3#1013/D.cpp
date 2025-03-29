#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        // cout << n << " " << m << " " << k << endl;
        int maxBenchInRow = (k + n - 1) / n;

        int emptySeats = m - maxBenchInRow;
        // cout << "benches" << maxBenchInRow << endl;
        int longestSegment = (maxBenchInRow + emptySeats) / (emptySeats + 1);
        cout << longestSegment << endl;
    }
    
	return 0;
}
