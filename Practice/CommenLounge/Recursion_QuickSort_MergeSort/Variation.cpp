// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int N, K, curr;
    cin >> N >> K;
    vector<int> nums(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long count = 0;
    for (int i = 0; i < N; i++) {
        count += distance(lower_bound(nums.begin(), nums.end(), nums[i]+K), nums.end());
    }
    cout << count << endl;
}