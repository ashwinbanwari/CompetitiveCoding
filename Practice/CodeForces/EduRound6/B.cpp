#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    unordered_map<int, int> m {{0,6}, {1,2}, {2,5}, {3,5}, {4,4}, {5,5}, {6,6}, {7,3}, {8,7}, {9,6}};
    int a, b;
    cin >> a >> b;
    long long res = 0;
    for (int i = a; i <= b; i++) {
    	int curr = i;
    	res += m[curr%10];
    	while (curr/=10) {
    		res += m[curr%10];
    	}
    }
    cout << res << endl;

	return 0;
}