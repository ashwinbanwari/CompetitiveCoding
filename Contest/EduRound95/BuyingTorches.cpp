// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n, int arr[], int bit[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int bit[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bit[i];
        }
        solve(n, arr, bit);
    }
}

void solve(int n, int arr[], int bit[]) {
    vector<int> unlocked;
    int totalSum;
    for (int i = 0; i < n; i++) {
        if (!bit[i]) {
            unlocked.push_back(arr[i]);
        }
        totalSum += arr[i];
    }
    if (totalSum >= 0) {
        sort(unlocked.begin(), unlocked.end(), greater<>());
    } else {
        sort(unlocked.begin(), unlocked.end());
    }
    int vectorPtr = 0;
    for (int i = 0; i < n; i++) {
        if (!bit[i]) {
            arr[i] = unlocked[vectorPtr];
            vectorPtr++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
