// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <climits>
#include <algorithm>


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
    unordered_map<int, list<int>> idx;
    unordered_set<int> seated;
    // O(M)
    for (int i = 0; i < M; i++) {
        cin >> orders[i];
        idx[orders[i]].push_back(i);
    }
    int counter = 0;
    int startIdx = 0;
    while (seated.size() != N && startIdx < M) {
        if (seated.insert(orders[startIdx]).second) {
            counter++;
        }
        idx[orders[startIdx]].pop_front();
        startIdx++;
    }
    for (int i = startIdx; i < M; i++) {
        if (!seated.count(orders[i])) {
            counter++;
            int maxi = INT_MIN;
            int minId = -1;
            // not already seated
            for (int id : seated) {
                if (idx[id].empty()) {
                    minId = id;
                    break;
                }
                if (idx[id].front() > maxi) {
                    maxi = idx[id].front();
                    minId = id;
                }
            }
            seated.erase(minId);
            seated.insert(orders[i]);
        }
        idx[orders[i]].pop_front();
    }
    cout << counter << endl;
}
