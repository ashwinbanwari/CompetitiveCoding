#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> a, b;

    int x;
    bool as = false;
    while (cin >> x) {
        if (!as)
            a.push_back(x);
        else
            b.push_back(x);
        as = !as;
    }

    unordered_map<int, int> cnt;

    for (int i : b) {
        cnt[i]++;
    }

    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * cnt[a[i]];
    }

    cout << sum << endl;

    return 0;
}