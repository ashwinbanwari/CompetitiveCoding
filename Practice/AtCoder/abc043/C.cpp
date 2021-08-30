#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int mean = lround((static_cast<double>(accumulate(v.begin(), v.end(), 0)) / N));
    int res = 0;
    for (int& i : v) {
        res += pow((mean - i), 2);
    }
    cout << res << endl;




    return 0;
}