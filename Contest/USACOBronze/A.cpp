#include <bits/stdc++.h>

using namespace std;


long long countLessThan3(vector<int> v) {
	// cerr << v.size() << endl;
	long long res = 0;
	for (int i = 1; i < (int)v.size() - 1; i++) {
		int smallestGap = min(v[i]-v[i-1], v[i+1]-v[i]);
		int largestGap = max(v[i] - v[i-1], v[i+1]-v[i]);
		int largestSeq = smallestGap + largestGap - 1;
		// cerr << "sGap: " << smallestGap << " lGap: " << largestGap << " lSeq: " << largestSeq << endl;
		for (int k = 3; k <= largestSeq ;k++) {
			res += min(smallestGap, min(largestSeq-k+1, k));
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
    	char c;
    	cin >> c;
    	v[i] = (c == 'G') ? 1 : 0;
    }

    vector<int> ones {-1};
    vector<int> zeroes {-1};
    for (int i = 0; i < N; i++) {
    	if (v[i] == 1) {
    		ones.push_back(i);
    	} else {
    		zeroes.push_back(i);
    	}
    }
    ones.push_back(N);
    zeroes.push_back(N);
    long long ans = 0;
    ans += countLessThan3(ones) + countLessThan3(zeroes);
    cout << ans << endl;



	return 0;
}