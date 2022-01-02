#include <bits/stdc++.h>

using namespace std;

int count(vector<int>& v, int x) {
	int count = 0;
	for (int i : v) {
		if (i == x) {
			count++;
		}
	}
	return count;
}

long long nChooseK(long long c, long long numAppear) {
	if (numAppear == 3) {
		return c * (c-1) * (c-2) / (3 * 2);
	} else if (numAppear == 2) {
		return c * (c-1) / (2);
	} else {
		return c;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    sort(v.begin(), v.end());
   	int last = v[0];
   	int last2 = v[1];
   	int last3 = v[2];

   	long long ans;
   	long long a = count(v, last);
   	long long b = count(v, last2);
   	long long c = count(v, last3);

   	multiset<long long> s = {last, last2, last3};
   	int numAppear = s.count(last3);
   	ans = nChooseK(c, numAppear);
   	cout << ans << endl;

   	/*
   	if (last == last2 && last2 == last3) {
   		// ans = count choose 3
   		ans = (a * (a-1) * (a-2)) / (3*2);
   	} else if (last == last2) {
   		// ans = a choose 2 * c 
   		ans = (a * (a-1)) / (2) * c;
   	} else if (last2 == last3) {
   		ans = a * (b * (b-1)) / (2);
   	} else {
   		ans = a * b * c;
   	}
   	cout << ans << endl;
   	*/

    

	return 0;
}