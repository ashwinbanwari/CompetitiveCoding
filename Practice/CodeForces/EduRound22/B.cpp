#include <bits/stdc++.h>

using namespace std;

long long power(long long a, long long b) {
	if (b==0) {
		return 1;
	}
	return a * pow(a, b-1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    long long x,y,l,r;
    cin >> x >> y >> l >> r;

    set<long long> unluckyYears;
    for(long long i=1;;i*=x) {
		for(long long j=1;;j*=y) {
			if(i+j>=l&&i+j<=r)unluckyYears.insert(i+j);
			if(j>r/y) break;
		} if(i>r/x)break;
	}
    unluckyYears.insert(l-1);
    unluckyYears.insert(r+1);
    long long largestDiff = 0;
    long long prev = l-1;
    for (long long l : unluckyYears) {
    	largestDiff = max(largestDiff, l - prev - 1);
    	prev = l;
    }

    cout << largestDiff << endl;
	return 0;
}