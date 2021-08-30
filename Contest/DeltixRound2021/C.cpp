#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n = 5;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> level(n+1); // at 0th index, [level[0], level[1]]]
    vector<long long> pastSegs(n);
    vector<bool> evils(n+1);
    pastSegs[0] = 0;
    level[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            level[i] = max(0ll, level[i-1] - v[i-1]);
            if (level[i-1] - v[i-1] < 0) {
                evils[i] = true;
            }
        } else {
            level[i] = level[i-1] + v[i-1];
        }
    }
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            pastSegs[i] = pastSegs[i-1];
        } else {
            bool noEvil = 1;
            long long numLeft = v[i];
            for (int j = i-1; j >= 0; j--) {
                if (evils[j]) {
                    noEvil = 0;
                }
                if (level[j] <= level[i+1]) {
                    // reached level to give away everything left
                    if (level[i] - v[i] == level[j]) {
                        // perfect amount, get pastSegs and let this pastSegs be 1 higher
                        pastSegs[i] = pastSegs[j] + 1;
                        ans += numLeft + noEvil * pastSegs[j];
                    } else if (level[j] < level[i+1]) {
                        // there are still more (, don't add pastSegs 
                        pastSegs[i] = 1;
                        ans += numLeft;
                    } else {
                        // we overdid it with the ),
                        pastSegs[i] = 0;
                        ans += min(level[j]+1, numLeft) + noEvil * pastSegs[j];
                    }
                    break;
                } else if (level[j] <= level[i+1] + numLeft - 1) {
                    // can give away some
                    ans += level[i] - level[j] - (v[i] - numLeft) + noEvil * pastSegs[j];
                    numLeft = level[j] - level[i+1];
                }
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}