#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	vector<int> v {x, y, z};
    	sort(v.begin(), v.end());
    	bool conditionOne = (v[0]==v[1] && v[2]%2 == 0);
    	bool conditionTwo = (v[0]+v[1] == v[2]);
    	bool conditionThree = (v[1] == v[2] && v[0]%2 == 0);
    	cout << ((conditionOne || conditionTwo || conditionThree) ? "YES" : "NO");
    	cout << endl;
    }

	return 0;
}