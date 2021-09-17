#include <bits/stdc++.h>

using namespace std;

long long mod = pow(10,9) + 7;

class Matrix {
public:
	vector<vector<long long>> mat = vector<vector<long long>>(2, vector<long long>(2));
	Matrix operator*(Matrix& other) {
		Matrix result;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					result.mat[i][k] += mat[i][j] * other.mat[j][k];
					result.mat[i][k] %= mod;
				}
			}
		}
		return result;
	}
};

Matrix modpow(Matrix& m, long long pow) {
	Matrix result {{{1,0},{0,1}}};
	while (pow != 0) {
		if (pow % 2 == 1) {
			result = result * m;
		}
		pow /= 2;
		m = m * m;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n;
	cin >> n;
	if (n==0) {
		cout << 0 << endl;
		return 0;
	}
    Matrix m{{{0,1},{1,1}}};

    Matrix res = modpow(m, n);
    cout << res.mat[0][1];


	return 0;
}