#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    multiset<long long> others(arr.begin(), arr.end());
    multiset<long long> have;
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    if (sum % 2 == 1) {
    	cout << "NO";
    	return 0;
    }
    long long goal = sum / 2;
    long long currSum = 0;
    for (int i = 0; i < n; i++) {
    	others.erase(others.find(arr[i])); // erase 1 of
    	have.insert(arr[i]);
    	// cerr << others.size() << " " << have.size() << endl;
    	currSum += arr[i];
    	long long need = goal - currSum;
    	if (others.find(need) != others.end() || have.find(-need) != have.end()) {
    		cout << "YES" << endl;
    		return 0;
    	}
    }
    cout << "NO" << endl;

	return 0;
}