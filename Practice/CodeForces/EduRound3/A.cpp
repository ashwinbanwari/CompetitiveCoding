#include <bits/stdc++.h>

using namespace std;

int myGreatFunc(const int& a, const int& b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> sizes(n);
    for (int i = 0; i < n; i++) {
    	cin >> sizes[i];
    }
    sort(sizes.begin(), sizes.end(), myGreatFunc);
    int total = 0;
    for (int i = 0; i < sizes.size(); i++) {
    	if (total >= m) {
    		cout << i << endl;
    		return 0;
    	}
    	total += sizes[i];
    }
    cout << sizes.size() << endl;

	return 0;
}