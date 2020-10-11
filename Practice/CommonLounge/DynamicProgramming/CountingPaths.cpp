// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<long>> dp(N);
    for (int i = 0; i < M; i++) {
        dp[0].push_back(1);
    }
    for (int i = 1; i < N; i++) {
        dp[i].push_back(1);
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i].push_back(dp[i][j-1] + dp[i-1][j]);
        }
    }
    cout << dp[N-1][M-1] << endl;
}