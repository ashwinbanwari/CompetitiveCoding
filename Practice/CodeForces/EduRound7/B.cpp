#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string time;
 	int a;
 	cin >> time >> a;
 	int hour = stoi(time.substr(0,2));
 	int min = stoi(time.substr(3, 2));
 	int hoursToAdd = a / 60;
 	int minsToAdd = a % 60;
 	min += minsToAdd;
 	if (min >= 60) {
 		min %= 60;
 		hoursToAdd++;
 	}
 	hour = (hour + hoursToAdd) % 24;
 	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << min << endl;

	return 0;
}