// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int solve(vector<int>& in, int lo, int hi);

int main() {
    int N;
    cin >> N;
    vector<int> in(N);
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    cout << min(solve(in, 1, N) + in[0], solve(in, 0, N-1) + in[N-1]) << endl;
    

}
int solve(vector<int>& in, int lo, int hi) { 
    int N = hi - lo;
    if (N < 2) {
        return 0;
    }
    vector<int> dp(N);
    dp[0] = in[lo];
    dp[1] = in[lo+1];
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + in[lo+i];
    }
    return min(dp[N-1], dp[N-2]);
}
