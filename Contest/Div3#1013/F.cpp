#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <cmath>

using namespace std;

using ll = long long;

ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        vector<vector<ll>> dp(n, vector<ll>(m, 0));
        for (int i = 0; i < m; i++) {
            if (grid[n - 1][i] == 'X') {
                dp[n - 1][i] = 1;
            }
        }

        // calcualte range for above level
        int jrange = floor(sqrt(pow(d, 2) - 1));

        for (int i = n-1; i >= 0; i--) {
            // from below level
            vector<ll> prefBelowLevel(m, 0);
            if (i != n-1) {
                prefBelowLevel[0] = dp[i+1][0];
                for (int j = 1; j < m; j++) {
                    prefBelowLevel[j] = prefBelowLevel[j-1] + dp[i+1][j];
                }
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 'X') {
                        dp[i][j] += prefBelowLevel[min(m-1, j + jrange)] - (j - jrange-1 >= 0 ? prefBelowLevel[j-jrange-1] : 0);
                        dp[i][j] %= mod;
                    }
                }
            }

            // switches among this level
            vector<ll> prefThisLevel(m, 0);
            prefThisLevel[0] = dp[i][0];
            for (int j = 1; j < m; j++) {
                prefThisLevel[j] = prefThisLevel[j-1] + dp[i][j];
            }
            vector<ll> newdp = dp[i];
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    newdp[j] += prefThisLevel[min(m-1, j + d)] - dp[i][j] - (j - d-1 >= 0 ? prefThisLevel[j-d-1] : 0);
                    newdp[j] %= mod;
                }
            }
            dp[i] = newdp;
        }

        long long result = 0;
        for (int i = 0; i < m; i++) {
            result += dp[0][i];
            result %= mod;
        }

        cout << result << endl;
    }
    
	return 0;
}
