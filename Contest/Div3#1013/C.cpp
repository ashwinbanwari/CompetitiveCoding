#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << -1 << endl;
        } else {
            for (int i = 1; i <= n; i+=2) { 
                cout << i << " ";
            }
            for (int i = 2; i <= n; i += 2) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    
	return 0;
}
