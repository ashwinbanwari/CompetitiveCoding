#include <bits/stdc++.h>

using namespace std;

int lowest1(long long a) 
{
	if (a==0) {
		return 0;
	}
	int res = 0;
	while ((a & 1) == 0) {
		res++;
		a >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, q;
    cin >> n >> q;
    while (q--) {
    	long long curr;
    	cin >> curr;
    	string s;
    	cin >> s;
    	for (int i = 0; i < s.size(); i++) {
    		int lowest;
    		switch(s[i]) {
    			case 'U':
    				if (curr * 2 - 1 == n) {
    					// top
    					break;
    				}
    				lowest = lowest1(curr);
    				curr ^= (1LL << lowest);
    				curr |= (1LL << lowest+1);
    				break;
    			case 'R':
    				lowest = lowest1(curr);
    				if (lowest == 0) {
    					// leaf
    					break;
    				}
    				curr += (1LL << lowest-1);
    				break;
    			case 'L':
    				lowest = lowest1(curr);
    				if (lowest == 0) {
    					// leaf
    					break;
    				}
    				curr -= (1LL << lowest-1);
    				break;
    		}
    	}
    	cout << curr << endl;
    }
    

	return 0;
}