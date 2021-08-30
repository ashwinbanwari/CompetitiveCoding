#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, A;
    cin >> N >> A;
    vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(N+1, vector<long long>(A*N + 1)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        int el;
        cin >> el;
        for (int j = N; j >= 0; j--) {
            for (int k = 0; k < A*N+1; k++) {
                dp[i][j][k] = dp[i-1][j][k];
                if (k - el >= 0 && j > 0) {
                    dp[i][j][k] += dp[i-1][j-1][k-el];
                }
                // cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }

    long long res = 0;
    for (int i = 1; i <= N; i++) {
        res += dp[N][i][i*A];
    }
    cout << res << endl;

    return 0;
}