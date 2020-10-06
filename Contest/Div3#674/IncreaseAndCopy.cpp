// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <climits>

using namespace std;
void solve(int minBound);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int in;
        cin >> in;
        solve(in);
    }
}

void solve(int minBound) {
    int addVal = -1;
    int least = INT_MAX;
    while (true) {
        int curr = (minBound + (addVal + 2) - 1) / (addVal + 2) + addVal;
        if (curr > least) {
            cout << least << endl;
            return;
        }
        least = curr;
        addVal++;
    }
}
