// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>

using namespace std;

long n;

long ans (long ind, long x, long y, vector<vector<vector<long>>>& dp, vector<long>& a){
    if(ind == n + 1) return 0;
    if(dp[ind][x][y] != -1) return dp[ind][x][y];
    long ret = ans(ind+1,x,y, dp, a);
    if(x == 0) ret = max(ret,1 + ans(ind+1,ind,y, dp, a));     // chose the 1st element  belonging to the increasing seq.
    if(y == 0) ret = max(ret,1 + ans(ind+1,x,ind, dp, a));     // chose the 1st element  belonging to the decreasing seq.
    if(a[ind] > a[x]) ret = max(ret,1 + ans(ind+1,ind,y, dp, a));
    if(a[ind] < a[y]) ret = max(ret,1 + ans(ind+1,x,ind, dp, a));
    return dp[ind][x][y] = ret;
}
void solve(vector<long>& rooms) {
    vector<vector<vector<long>>> dp(rooms.size()+1, vector<vector<long>>(rooms.size()+1, vector<long>(rooms.size()+1, -1)));
    cout << ans(1, 0, 0, dp, rooms) << endl;
}


int main() {
    long t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long> in(n);
        for (long i = 0; i < n; i++) {
            cin >> in[i];
        }
        solve(in);
    }
}