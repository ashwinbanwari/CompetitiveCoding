#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, m, srcA, srcB, dstA, dstB;
    	cin >> n >> m >> srcA >> srcB >> dstA >> dstB;
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
    	cout << min(time1, time2) << endl;
    }

	return 0;
}