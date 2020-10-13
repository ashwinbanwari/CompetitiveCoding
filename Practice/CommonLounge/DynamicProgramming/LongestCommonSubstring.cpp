// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int dp[a.size()][b.size()];
    int maxi = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[0]) {
            dp[i][0] = 1;
            maxi = 1;
        } else {
            dp[i][0] = 0;
        }
    }
    for (int i = 1; i < b.size(); i++) {
        if (b[i] == a[0]) {
            dp[0][i] = 1;
            maxi = 1;
        } else {
            dp[0][i] = 0;
        }
    }
    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    cout << maxi << endl;
}