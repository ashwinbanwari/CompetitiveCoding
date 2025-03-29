#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, c;
	cin >> a >> b >> c;
	if (a == b + c || b == a + c || c == a + b) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
    
	return 0;
}
