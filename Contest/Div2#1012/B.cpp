#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        vector<int> maxInRow(n, 0);
        vector<int> maxForCol(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    maxInRow[i] = j;
                } else {
                    break;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == '1') {
                    maxForCol[i] = j;
                } else {
                    break;
                }
            }
        }

        bool good = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    if (!(maxForCol[j] >= i || maxInRow[i] >= j)) {
                        good = false;
                    }
                }
            }
        }


        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO"  << endl;
        }

	}

	return 0;
}
