#include <bits/stdc++.h>

using namespace std;

bool isLeapYear(int a) {
	return (a%400 == 0) || (a % 4 == 0 && a%100 != 0);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int year;
    cin >> year;
    int res = 0;
    bool shudBeLeapYear = isLeapYear(year);
    int ans = year;
    while (res != 0 || ans == year || shudBeLeapYear != isLeapYear(ans)) {
    	if (isLeapYear(ans)) {
    		res+=2;
    	} else {
    		res++;
    	}
    	res %= 7;
    	ans++;
    }
    cout << ans << endl;

	return 0;
}