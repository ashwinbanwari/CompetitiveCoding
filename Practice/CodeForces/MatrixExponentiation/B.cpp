#include <bits/stdc++.h>

using namespace std;

long long mod = pow(10,9)+7;

class Matrix {
public:
	vector<vector<long long>> mat = vector<vector<long long>>(2, vector<long long>(2));
	Matrix operator*(Matrix& other) {
		Matrix res;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					res.mat[i][k] += mat[i][j] * other.mat[j][k];
					res.mat[i][k] %= mod;
				}
			}
		}
		return res;
	}
};

Matrix modpow(Matrix& m, long long pow) {
	Matrix result = {{{1,0},{0,1}}};
	while (pow != 0) {
		if (pow % 2) {
			result = result * m;
		}
		m = m * m;
		pow /= 2;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    long long n;
    cin >> n;
    Matrix m{{{19,7},{6,20}}};
    Matrix res = modpow(m, n);
    cout << res.mat[0][0] << endl;


	return 0;
}