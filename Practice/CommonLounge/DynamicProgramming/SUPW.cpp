// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> work(N);
    for (int i = 0; i < N; i++)  {
        cin >> work[i];
    }
    if (N == 1) {
        cout << work[0] << endl;
        return 0;
    } else if (N == 2) {
        cout << min(work[0], work[1]) << endl;
        return 0;
    }
    vector<int> ans(N);
    ans[0] = work[0];
    ans[1] = work[1];
    ans[2] = work[2];
    for (int i = 3; i < N; i++) {
        ans[i] = min(work[i] + ans[i-1], min(work[i] + ans[i-2], work[i] + ans[i-3]));
    }
    cout << min(ans[N-1], min(ans[N-2], ans[N-3])) << endl;
    return 0;
}
