#include <bits/stdc++.h>

using namespace std;

int timeAdd(int a, int b) {
	int numHours = b/60;
	int numMin = b%60;
	a += numHours * 100;
	if (numMin+(a%100) >= 60) {
		a += 100;
		a+= (numMin-60);
	} else {
		a += numMin;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int a, timeA, b, timeB;
    cin >> a >> timeA >> b >> timeB;
    string startTime;
    cin >> startTime;
    startTime.erase(2,1);
    int leaveAt = stoi(startTime);
    int currStart = 500;
    int res = 0;
    while (currStart < 2400) {
    	if (leaveAt < timeAdd(currStart, timeB) && timeAdd(leaveAt, timeA) > currStart) {
    		// cerr << currStart << endl;
    		res++;
    	}
    	currStart = timeAdd(currStart, b);
    }
    cout << res << endl;

	return 0;
}