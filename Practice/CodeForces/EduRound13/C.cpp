#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    long long numRed, numBlue, numEither;
    numEither = n/lcm(static_cast<long long>(a),b);
    numRed = n/a - numEither;
    numBlue = n/b - numEither;
    cout << max((numRed+numEither)*p + numBlue*q, numRed*p + (numBlue+numEither)*q) << endl;


	return 0;
}