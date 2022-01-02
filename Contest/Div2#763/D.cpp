#include <bits/stdc++.h>

using namespace std;

int sol(int n, int m, int& srcA, int& srcB, int dstA, int dstB) {
	int time1 = 0;
	if  (dstA < srcA) {
		time1 += n-srcA;
		time1 += n -dstA;
	} else  {
		time1 = dstA-srcA;
	}

	int time2 = 0;
	if (dstB < srcB) {
		time2 += m-srcB;
		time2 += m-dstB;
	} else {
		time2 = dstB-srcB;
	}
	int timeToReach = min(time1, time2);
	srcA += timeToReach;
	srcB += timeToReach;
	if (srcA > n) {
		int extra = srcA-n;
		srcA = n-extra;
	}
	if (srcB > m) {
		int extra = srcB - m;
		srcB = m - extra;
	}
    return timeToReach;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, m, srcA, srcB, dstA, dstB, probability;
    	cin >> n >> m >> srcA >> srcB >> dstA >> dstB >> probability;
    	double p = probability / 100.0;
    	int idx = roundl(1 / p);
    	vector<int> sols;
    	for (int i = 0; i < idx; i++) {
    		sols.push_back(sol(n,m, srcA,srcB,dstA, dstB));
    		if (i!=0) {
    			sols.back()++;
    			sols.back()+= *(sols.end() - 2);
    		}
    		srcA++;
    		if (srcA > n) {
    			srcA = n-1;
    		}
    		srcB++;
    		if (srcB > n) {
    			srcB = n-1;
    		}
    	}
    	cout << sols.back() << endl;
    }

	return 0;
}