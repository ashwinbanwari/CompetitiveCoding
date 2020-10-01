// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(int N, vector<pair<int,int>> v);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<pair<int,int>> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> v[i].second;
        }
        solve(N, v);
    }
}

void solve(int N, vector<pair<int,int>> v) {
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return (abs(a.first + a.second)) > (abs(b.first + b.second));
    });
    int winning = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            winning += v[i].first;
        } else {
            winning -= v[i].second;
        }
    }
    if (winning > 0) {
        cout << "First" << endl;
    } else if (winning < 0) {
        cout << "Second" << endl;
    } else {
        cout << "Tie" << endl;
    }
}
