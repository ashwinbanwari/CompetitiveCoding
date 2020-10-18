// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    vector<int> dp(N);
    dp[0] = 1;
    int best = 0;
    for (int i = 1; i < N; i++) {
        bool positive = vec[i] > 0;
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (positive) {
                if (vec[j] < 0 && abs(vec[j])< vec[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                } 
            } else {
                if (vec[j] > 0 && vec[j] < abs(vec[i])) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        // cout << dp[i] << endl;
        best = max(best, dp[i]);
    }
    cout << best << endl;
}