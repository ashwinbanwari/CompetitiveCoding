#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    long long d,k,a,b,t;
    cin >> d >> k >> a >> b >> t;
    if (d <= k) {
    	cout << a*d << endl;
    } else {
    	long long numCycles = d / k;
    	long long timePerDriveCycle = a*k+t;
    	long long allDrive = a*k + timePerDriveCycle * (numCycles-1) + t + (d%k) * a;
    	long long driveMinusLast = a*k + timePerDriveCycle * (numCycles-1) + (d%k) * b;
    	long long allWalk = a*k + (d-k) * b;
    	// cerr << allDrive << " allDrive "  << endl;
    	// cerr << driveMinusLast << " driveMinusLast " <<  endl;
    	// cerr << allWalk << " allWalk " <<  endl;
    	cout << min(min(allDrive, driveMinusLast), allWalk) << endl; 
    }


	return 0;
}