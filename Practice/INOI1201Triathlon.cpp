#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std; 

bool comp(const pair<int, int>& a, const pair<int, int>& b);

int main(int argc, char** argv) {
    int N, x, y, z;
    cin >> N;
    pair<int, int> people[N];
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> z;
        people[i] = make_pair(x, y+z);
    }
    sort(people, people + N, comp);
    int timeTaken = 0;
    int maxTime = INT_MIN;
    for (int i = 0; i < N; i++) {
        maxTime = max(maxTime, people[i].first + people[i].second + timeTaken);
        timeTaken += people[i].first;
    }
    cout << maxTime << endl;
}
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second > b.second) {
        return true;
    }
    return false;
}