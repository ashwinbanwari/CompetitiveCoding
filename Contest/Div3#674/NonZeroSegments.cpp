// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int arr[n];
    int pref[n+1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> seen;
    vector<vector<int>> intervals;
    pref[0] = 0;
    seen[pref[0]] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + arr[i-1];
        if (seen.find(pref[i]) == seen.end()) {
            seen[pref[i]] = i;
        } else {
            vector<int> interval = {seen[pref[i]], i};
            intervals.push_back(interval);
        }
    }
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) -> bool {
        return a[0] < b[0];
    });
    cout << intervals.size() << endl;
    int distinct = 0;
    int largest = INT_MIN;
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] > largest) {
            largest = intervals[i][1];
            distinct++;
        } else {
            largest = max(largest, intervals[i][1]);
        }
    }
    // cout << distinct << endl;
}
