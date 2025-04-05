#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <climits>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k;
	cin >> n >> k;

	ll a = (n / 2) / (k + 1);
	cout << a << " " << k * a << " " << n - (a + k * a) << endl;
    
	return 0;
}
