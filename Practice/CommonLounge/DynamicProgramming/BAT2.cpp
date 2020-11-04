// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>

using namespace std;

long long n;

long long ans (long long ind, long long x, long long y, vector<vector<vector<long long>>>& dp, vector<long long>& a){
    if(ind == n + 1) return 0;
    if(dp[ind][x][y] != -1) return dp[ind][x][y];
    long long ret = ans(ind+1,x,y, dp, a);
    if(x == 0) ret = max(ret,1 + ans(ind+1,ind,y, dp, a));
    if(y == 0) ret = max(ret,1 + ans(ind+1,x,ind, dp, a));
    if(a[ind] > a[x]) ret = max(ret,1 + ans(ind+1,ind,y, dp, a));
    if(a[ind] < a[y]) ret = max(ret,1 + ans(ind+1,x,ind, dp, a));
    return dp[ind][x][y] = ret;
}

void solve(vector<long long>& rooms) {
    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(n+1, vector<long long>(n+1, -1)));
    cout << ans(1, 0, 0, dp, rooms) << endl;
}


int main() {
    long long t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> in(n+1);
        for (long long i = 1; i <= n; i++) {
            cin >> in[i];
        }
        solve(in);
    }
}