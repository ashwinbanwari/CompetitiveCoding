#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
    cin >> t;
	while (t--) {
		int n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int maxtables = n / 4;
        int sz = sqrt(maxtables) + 1;

        vector<vector<int>> grid(sz, vector<int>(sz, 0));
        pair<int, int> curr0 = {0, 0};
        pair<int, int> curr1 = {0, 0};
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                while (grid[curr0.first][curr0.second] != 0) {
                    if (curr0.second == 0) {
                        curr0.second = curr0.first + 1;
                        curr0.first = 0;
                    } else {
                        curr0.second--;
                        curr0.first++;
                    }
                }
                grid[curr0.first][curr0.second] = 1;
                // add to list
            } else {
                while (grid[curr1.first][curr1.second] ) {
                    if (curr1.second == 0 && curr1.first + curr1.second == sum1) {
                        curr1.second = curr1.first + 1;
                        curr1.first = 0;
                        sum1 = curr1.second;
                    } else {

                    }
                }
            }
        }

    }
        

	return 0;
}
