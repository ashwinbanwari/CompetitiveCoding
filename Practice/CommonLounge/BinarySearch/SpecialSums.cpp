// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    long a[N];
    long b[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        if (i != 0) {
            b[i] += b[i-1];
        }
    }
    // find best i for each j
    long bestI[N];
    bestI[0] = a[0] - b[0];
    for (int i = 1; i < N; i++) {
        bestI[i] = max(bestI[i-1], a[i] - b[i]);
    }
    // find best i for each j reverse
    long bestIRev[N];
    bestIRev[N-1] = a[N-1] - b[N-1];
    for (int i = N - 2; i >= 0; i--) {
        bestIRev[i] = max(bestIRev[i+1], a[i] - b[i]);
    }
    long maxSum = LONG_MIN;
    for (int j = 0; j < N; j++) {
        long currSum;
        maxSum = max(maxSum, a[j]);
        if (j != 0) {
            // i < j
            currSum = currSum = a[j] + b[j-1] + bestI[j-1];
            maxSum = max(maxSum, currSum);
        }
        if (j != N - 1) {
            // i > j
            currSum = bestIRev[j + 1] + a[j] + b[N-1];
            if (j != 0) {
                currSum += b[j-1];
            }
            maxSum = max(maxSum, currSum);
        }
    }
    cout << maxSum << endl;
}