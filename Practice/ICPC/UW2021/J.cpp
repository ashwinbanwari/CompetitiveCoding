#include <bits/stdc++.h>

using namespace std;

long long mod = pow(10,9)+7;

int type(char c) {
	static unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};
	return vowels.count(c);
}
/*
void printMat(auto& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cerr << mat[i][j][0] << "/" << mat[i][j][1] << " ";
        }
        cerr << endl;
    }
}
*/
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    k--;
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k, vector<long long>(2)));
    dp[0][0][type(s[0])] = 1;
    for (int i = 1; i < n; i++) {
        // single element
        dp[i][0][type(s[i])]++;
        dp[i][0][type(s[i])] %= mod;
        for (int j = 0; j < k; j++) {
            // down arrow
            dp[i][j][0] += dp[i-1][j][0];
            dp[i][j][0] %= mod;
            dp[i][j][1] += dp[i-1][j][1];
            dp[i][j][1] % mod;
            int typ = type(s[i]);
            if (j != 0) {
                // diag arrow
                dp[i][j][typ] += dp[i-1][j-1][typ];
                dp[i][j][typ] %= mod;
            }
            // change type
            dp[i][0][typ] += dp[i-1][j][1-typ];
            dp[i][0][typ] %= mod;
        }
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += dp[n-1][i][0] + dp[n-1][i][1];
        ans %= mod;
    }
    cout << ans << endl;

    


	return 0;
}