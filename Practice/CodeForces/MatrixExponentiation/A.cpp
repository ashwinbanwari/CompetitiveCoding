#include <bits/stdc++.h>

using namespace std;

class Matrix {
public:
	vector<vector<double>> mat = vector<vector<double>>(2, vector<double>(2));
	Matrix operator*(Matrix& other) {
		Matrix new_mat;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					new_mat.mat[i][k] += mat[i][j] * other.mat[j][k];
				}
			}
		}
		return new_mat;
	}
};

Matrix modpow(Matrix& a, int pow) {
	Matrix result = {{{1,0},{0,1}}};
	while (pow != 0) {
		if (pow % 2) {
			result = result * a;
		}
		a = a * a;
		pow /= 2;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    double p;
    cin >> n >> p;
    Matrix m{{{1-p,p},{p, 1-p}}};
    Matrix ans = modpow(m, n);
    cout << ans.mat[0][0] << endl;


	return 0;
}