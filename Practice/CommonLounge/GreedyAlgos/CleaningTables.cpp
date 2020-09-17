// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void solve();

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

void solve() {
    // M = 4 * 10^2
    int N, M;
    cin >> N >> M;
    vector<int> orders(M);
    unordered_set<int> unique;
    // O(M)
    for (int i = 0; i < M; i++) {
        cin >> orders[i];
        unique.insert(orders[i]);
    }
    int counter = 0;
    // O(M^2)
    for (int i : unique) {
        unordered_map<int, int> freq;
        int startIdx;
        bool counting = false;
        for (int j = 0; j < M; j++) {
            if (orders[j] == i && freq.size() >= N) {
                counter++;
                freq.clear();
            } else if (orders[j] == i) {
                freq.clear();
                counting = true;
            } else if (counting) {
                freq[orders[j]]++;
            }
        }
    }
    cout << counter + unique.size() << endl;
}
