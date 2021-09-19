#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    for (int a = 1; a <= T; a++) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<int> dists(N);
        int currDist=pow(10,6);
        for (int i = 0; i < N; i++) {
            if (S[i] == '1') {
                currDist = 0;
            }
            dists[i] = currDist;
            currDist++;
        }
        currDist = pow(10,6);
        for (int i = N-1; i >= 0; i--) {
            if (S[i] == '1') {
                currDist = 0;
            }
            dists[i] = min(dists[i], currDist);
            currDist++;
        }
        cout << "Case #" << a << ": " << accumulate(dists.begin(), dists.end(), 0LL) << endl;
    }
    
    return 0;
}