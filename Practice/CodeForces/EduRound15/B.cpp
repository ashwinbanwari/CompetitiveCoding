#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }

    unordered_set<int> powsOfTwo;
    long long i = 1;
    while (i < 2*pow(10,9)+1) {
    	powsOfTwo.insert(i);
    	i *= 2;
    }
    unordered_map<int, int> vals;
    long long res = 0;
    for (int i = 0; i < n; i++) {
    	for (int twoPow : powsOfTwo) {
    		int count = vals[twoPow-v[i]];
    		res += count;
    	}
    	vals[v[i]]++;
    }


    cout << res << endl;

	return 0;
}