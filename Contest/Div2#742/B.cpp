#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> preComputed(3*pow(10,5)+1);
	int curr = 0;
	preComputed[0] = 0;
	preComputed[1] = 0;
	for (int i = 2; i < preComputed.size(); i++) {
		preComputed[i] = (i-1)^preComputed[i-1];
	}
    int t;
    cin >> t;
    while (t--) {
    	int a, b;
    	cin >> a >> b;
    	int curr = 0;
    	curr = preComputed[a];
    	int needed = curr^b;
    	if (curr == b) {
    		cout << a << endl;
    		continue;
    	}
 		if (needed == a) {
 			cout << a+2 << endl;
 		} else {
 			cout << a+1 << endl;
 		}
    }

	return 0;
}