#include <bits/stdc++.h>

using namespace std;

int compare(const string& a, const string& b) {
	return a+b < b+a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    sort(v.begin(), v.end(), compare);

    string res;
    for (int i = 0; i < n; i++) {
    	res += v[i];
    }
    cout << res << endl;

	return 0;
}