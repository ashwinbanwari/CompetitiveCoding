#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> odds;
    vector<int> evens;
    for (int i = 0; i < n; i++) {
    	int temp;
    	cin >> temp;
    	if (temp & 1) {
    		odds.push_back(temp);
    	} else {
    		evens.push_back(temp);
    	}
    }
    sort(odds.begin(), odds.end(), greater<int>());
    sort(evens.begin(), evens.end(), greater<int>());
    int sum = odds[0];
    for (int i = 2; i < odds.size(); i+= 2) {
    	if (odds[i] + odds[i-1] > 0) {
    		sum += odds[i] + odds[i-1];
    	}
    }
    for (int i = 0; i < evens.size(); i++) {
    	if (evens[i] > 0) {
    		sum += evens[i];
    	}
    }
    cout << sum << endl;

	return 0;
}