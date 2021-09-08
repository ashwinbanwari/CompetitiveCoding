#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		swap(a,b);
	}
	while (a != 0 && b != 0) {
		int temp = b;
		b = a%b;
		a = temp;
	}
	return max(a,b);
}

bool isCoprime(int a, int b) {
	return gcd(a, b) == 1;
}

void print(vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    vector<int> idxes;
    for (int i = 1; i < n; i++) {
    	if (!isCoprime(arr[i], arr[i-1])) {
    		idxes.push_back(i);
    	}
    }
    for (int i = idxes.size()-1; i >= 0; i--) {
    	arr.insert(arr.begin()+idxes[i], 1);
    }
    cout << idxes.size() << endl;
    print(arr);

	return 0;
}