// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string a;
    cin >> N >> a;
    string reversed = a;
    reverse(reversed.begin(), reversed.end());
    int dp[2][N+1];
    for (int i = 0; i < 2; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= N; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // cout << "a: " << a[i-1] << "b: " << reversed[j-1] << endl;
            if (a[i-1] == reversed[j-1]) { 
                dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
            } else {
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2] [j-1]);
            }
        }
    }
    cout << N-dp[N%2][N] << endl;
}