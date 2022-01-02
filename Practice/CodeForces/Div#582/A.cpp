#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int numEven = 0;
    int numOdd = 0;
    for (int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	(a % 2) ? numOdd++ : numEven++;
    }
    cout << min(numOdd, numEven) << endl;

	return 0;
}