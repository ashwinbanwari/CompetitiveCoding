#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    vector<bool> isPrime(2*pow(10,6)+1, true);
    for (int i = 2; i <= 2*pow(10, 6); i++) {
    	if (isPrime[i]) {
    		long long sq = (long long)i*i;
    		for (long long j= sq; j <= 2*pow(10, 6); j+= i) {
    			isPrime[j] = false;
    		}
    	}
    }

    int numOnes = 0;
    for (int i = 0; i < n; i++) {
    	if (v[i] == 1) numOnes++;
    }
    vector<int> ans;
    if (numOnes > 1) {
    	ans.insert(ans.begin(), numOnes, 1);
    	for (int i = 0; i < n; i++) {
    		if (v[i] != 1 && isPrime[v[i]+1]) {
    			ans.push_back(v[i]);
    			break;
    		}
    	}
    } else {
    	for (int i = 0; i < n; i++) {
    		for (int j = i+1; j < n; j++) {
    			if (isPrime[v[i]+v[j]]) {
    				ans = {v[i], v[j]}; 
    				goto fin;
    			}
    		}
    	}
    	ans = {v[0]};
    	fin: {}
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] << " ";
    }



	return 0;
}




/*
vector<int> isPrime(10^6);
// what its supposed to do: isPrime[i] = 1 if i is prime, else 0

fill(isPrime.begin()+1, isPrime.end(), 1);
for (int i = 2; i < 10^6; i++) {
	if (isPrime[i]) {
		for (int j = i^2; j < 10^6; j+=i) {
			isPrime[j] = 0;
		}
	}
}


[1, 1, 1, 1, 1, 1, 1, 1]

[1, 1, 1, 0, 1, 0, 1, 0]

[1, 1, 1, 0, 1, 0, 1, 0]

O(n^2) 


vector<int> isPrime(10^6);

for (int i = 0; i < 10^6; i++) {
	if (this i is prime) isPrime[i] = 1;
}

O(n^2) = O((10^6)^2) = O(10^12)

How to fill an array from 1 to 10^6 of whether that number is prime






*/