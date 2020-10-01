// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int N, int K, int B, int T, vector<pair<int, int>>& chicks);

int main() {
    int t;
    cin >> t;
    int caseNum = 1;
    while (t--) {
        int N, K, B, T;
        cin >> N >> K >> B >> T;
        // pair of position and speed of chick
        vector<pair<int, int>> chicks(N);
        for (int i = 0; i < N; i++) {
            cin >> chicks[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> chicks[i].second;
        }
        cout << "Case #" << caseNum << ": ";
        solve(N, K, B, T, chicks);
        caseNum++;
    }
    return 0;
}

void solve(int N, int K, int B, int T, vector<pair<int, int>>& chicks) {
    int safeChicks = 0;
    int cost = 0;
    for (int i = N-1; i >= 0 && safeChicks < K; i--) {
        if (chicks[i].second * T >= B - chicks[i].first) {
            cost += N-1 - i - safeChicks;
            safeChicks++;
        } 
    }
    if (safeChicks == K) {
        cout << cost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
