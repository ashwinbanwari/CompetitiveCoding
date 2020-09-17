// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
// store competitions in vector and sort
// for each competition, binary search the highest and lowest that satisfy
// return the lowest difference
int main() {
    int N, X, Y, minDifference, temp1, temp2;
    cin >> N >> X >> Y;
    vector<pair<int, int>> comps;
    vector<int> start;
    vector<int> end;
    // O(N)
    for (int i = 0; i < N; i++) {
        cin >> temp1 >> temp2;
        comps.push_back(make_pair(temp1, temp2));
    }
    // O(X)
    for (int i = 0; i < X; i++) {
        cin >> temp1;
        start.push_back(temp1);
    }
    sort(start.begin(), start.end());
    // O(Y)
    for (int i = 0; i < Y; i++) {
        cin >> temp1;
        end.push_back(temp1);
    }
    sort(end.begin(), end.end());
    minDifference = INT_MAX;
    // O(N(logX+logY))
    for (int i = 0; i < N; i++) {
        auto bestStart = upper_bound(start.begin(), start.end(), comps[i].first);
        auto bestEnd = lower_bound(end.begin(), end.end(), comps[i].second);
        if (bestStart == start.begin() || bestEnd == end.end()) {
            continue;
        }
        int diff = -*(--bestStart) + *bestEnd + 1;
        minDifference = min(diff, minDifference);
    }
    cout << minDifference << endl;
}