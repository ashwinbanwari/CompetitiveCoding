// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    k--;
    vector<int> in(N);
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    vector<int> dp(N);
    dp[k+1] = in[k+1];
    for (int i = k+2; i < N; i++) {
        dp[i] = max(dp[i-1], dp[i-2]) + in[i];
    }
    if (k == N-1) {
        dp[N-2] = in[N-2] + dp[N-1];
    } else {
        dp[N-2] = max(in[N-2] + dp[N-1], dp[N-2]);
    }
    for (int i = N-3; i >= 0; i--) {
        if (i >= k) {
            dp[i] = max(dp[i], max(in[i] + dp[i+1], in[i] + dp[i+2]));
        } else {
            dp[i] = max(in[i] + dp[i+1], in[i] + dp[i+2]);
        }
        
    }
    cout << dp[0] << endl;
}