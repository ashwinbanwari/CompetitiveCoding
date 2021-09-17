#include <bits/stdc++.h>

using namespace std;

long long mod = pow(10,9) + 7;

class Matrix {
public:
	vector<vector<long long>> mat;
	Matrix(int n) {
		mat.resize(n, vector<long long>(n));
	}
	Matrix operator*(Matrix& other) {
		int n = other.mat.size();
		Matrix result(n);
		assert(other.mat.size() == mat.size());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					result.mat[i][k] += mat[i][j] * other.mat[j][k];
					result.mat[i][k] %= mod;
				}
			}
		}
		return result;
	}
	void print() {
		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat.size(); j++) {
				cerr << mat[i][j] << " ";
			}
			cerr << endl;
		}
	}
};

Matrix modpow(Matrix m, int p) {
	Matrix result(m.mat.size());
	for (int i = 0; i < m.mat.size(); i++) {
		result.mat[i][i] = 1;
	}
	while (p!=0) {
		if (p%2) {
			result = result * m;
		}
		m = m * m;
		p /= 2;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    Matrix mat(n);
    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	mat.mat[a-1][b-1] = 1;
    }
    Matrix res = modpow(mat, k);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		ans += res.mat[i][j];
    		ans %= mod;
    	}
    }
    cout << ans << endl;



	return 0;
}