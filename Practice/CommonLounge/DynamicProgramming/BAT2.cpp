// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void solve(vector<int>& rooms) {
    int N = rooms.size();
    vector<pair<int, unordered_set<int>>> dp(N);
    dp[0] = make_pair(1, unordered_set<int>{0});
    int maxCount = 1;
    int maxIdx = 0;
    for (int i = 1; i < N; i++) {
        int maxId = -1;
        int maxVal = 0;
        for (int j = 0; j < i; j++) {
            if (rooms[j] < rooms[i] && dp[j].first > maxVal) {
                maxId = j;
                maxVal = dp[j].first;
            }
        }
        if (maxId == -1) {
            dp[i] = make_pair(1, unordered_set<int>{i});
        } else {
            dp[i] = make_pair(1 + dp[maxId].first, unordered_set<int>(dp[maxId].second.begin(), dp[maxId].second.end()));
            dp[i].second.insert(i);
            if (dp[i].first > maxCount) {
                maxCount = dp[i].first;
                maxIdx = i;
            }
        }
    }
    
    vector<int> dp2(N);
    dp2[N-1] = (dp[maxIdx].second.find(N-1) == dp[maxIdx].second.end()) ? 1 : 0;
    int maxCount2 = dp2[N-1];
    for (int i = N-2; i >= 0; i--) {
        int maxVal = -1;
        for (int j = i+1; j < N; j++) {
            if (rooms[j] < rooms[i] && dp2[j] > maxVal && dp[maxIdx].second.find(j) == dp[maxIdx].second.end()) {
                maxVal = dp2[j];
            }
        }
        if (maxVal == -1) {
            dp2[i] = (dp[maxIdx].second.find(i) == dp[maxIdx].second.end()) ? 1 : 0;
        } else {
            dp2[i] = maxVal;
            if (dp[maxIdx].second.find(i) == dp[maxIdx].second.end()) {
                dp2[i]++;
            }
            maxCount2 = max(maxCount2, dp2[i]);
        }
    }
    cout << maxCount + maxCount2 << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> in(n);
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        solve(in);
    }
}