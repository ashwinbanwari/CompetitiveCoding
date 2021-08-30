#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    if (N <= K) {
        cout << N * X;
    } else {
        cout << K * X + (N-K) * Y;
    } 

    return 0;
}