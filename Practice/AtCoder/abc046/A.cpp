#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    unordered_set<int> s{a, b, c};
    cout << s.size() << endl;

	return 0;
}