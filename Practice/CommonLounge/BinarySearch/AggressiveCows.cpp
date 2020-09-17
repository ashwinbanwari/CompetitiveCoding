// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int minDistance(vector<int>& barns, int numCows);
static bool ok(vector<int>& barns, int numCows, int distance);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, C, min;
        cin >> N >> C;
        vector<int> barns;
        while (N--) {
            int position;
            cin >> position;
            barns.push_back(position);
        }
        cout << minDistance(barns, C) << endl;
    }
}

static int minDistance(vector<int>& barns, int numCows) {
    sort(barns.begin(), barns.end());
    int lo = 1;
    int hi = barns.back() - barns.front();
    int ans = 0;
    int mid = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (ok(barns, numCows, mid)) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}
static bool ok(vector<int>& barns, int numCows, int distance) {
    int addedCows;
    int last;
    addedCows = 1;
    last = barns[0];
    for (int i : barns) {
        if (i - last >= distance) {
            last = i;
            addedCows++;
        }
    }
    return (addedCows >= numCows);
}