#include <bits/stdc++.h>

using namespace std;

int H, W;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_set<pair<int, int>, hash_pair> seen;


void process(vector<pair<int, int>>& pairs, pair<int, int>& val, vector<long long>& ans) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int currX = val.first+i;
            int currY = val.second+j;
            if (((bool)seen.count(make_pair(currX, currY)) || currX < 1 || currY < 1 || currX >= H-1 || currY >= W-1)) {
                continue;
            }
            seen.insert(make_pair(currX, currY));
            int sum = 0;
            for (int a = -1; a < 2; a++) {
                for (int b = -1; b < 2; b++) {
                    int x = currX+a;
                    int y = currY+b;
                    sum += binary_search(pairs.begin(), pairs.end(), make_pair(x, y));
                }
            }
            ans[sum]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    seen.clear();
    cin >> H >> W >> N;
    vector<pair<int, int>> v;
    while (N--) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a-1,b-1));
    }
    sort(v.begin(), v.end());
    vector<long long> ans(10);
    for (int i = 0; i < v.size(); i++) {
        process(v, v[i], ans);
    }
    long long total = accumulate(ans.begin()+1, ans.end(), 0ll);
    ans[0] = (H-2ll) * (W-2) - total;
    for (long long i : ans) {
        cout << i << endl;
    }
    return 0;
}