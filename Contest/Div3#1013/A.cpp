#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool verify(unordered_map<int, int>& m) {
    return (m[0] >= 3 && m[1] >= 1 && m[2] >= 2 && m[3] >= 1 && m[5] >= 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        unordered_map<int, int> m;
        bool good = false;
        int i;
        for (i = 0; i < n; i++) {
            m[v[i]]++;
            if (verify(m)) {
                good = true;
                break;
            }
        }
        if (good) {
            cout << i + 1 << endl;
        } else {
            cout << 0 << endl;
        }


	}

	return 0;
}
