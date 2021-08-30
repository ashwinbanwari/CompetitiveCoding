#include <bits/stdc++.h>

using namespace std;

unsigned mod = pow(10,9)+ 7;

unsigned long long nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long long result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
        result %= mod;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int H, W, A, B;
    cin >> H >> W >> A >> B;
    H -= 1;
    W -= 1;
    unsigned long long ans = nChoosek(H-A+W, W) % mod;
    for (int i = B; i < W; i++) {
        ans += nChoosek(H-A+i, i) * nChoosek(W-i+A-1, A-1);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}