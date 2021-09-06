#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n;
	cin >> n;
    int i = 1;
    long long curr = 0;
    while(curr + i < n) {
    	curr += i;
    	i++;
    }
    cout << (n-curr) << endl;



	return 0;
}