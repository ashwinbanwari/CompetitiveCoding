#include <bits/stdc++.h>

using namespace std;

bool good(int N, unordered_set<int> badDigits) {
    while (N != 0) {
        if (badDigits.count(N%10)) {
            return false;
        }
        N /= 10;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    unordered_set<int> badDigits;
    while (K--) {
        int bad;
        cin >> bad;
        badDigits.insert(bad);
    }
    int i = N;
    while (!good(i, badDigits)) {
        i++;
    }
    cout << i << endl;
    return 0;
}