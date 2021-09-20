#include <bits/stdc++.h>

using namespace std;

class Matrix {
public:
	vector<vector<long long>> mat;
	Matrix(int n) {
		mat.resize(n, vector<long long>(n, LLONG_MAX));
	}

	Matrix operator*(Matrix& other) {
		int n = mat.size();
		assert(n==other.mat.size());
		Matrix res(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res.mat[i][j] = LLONG_MAX;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (mat[i][j] == LLONG_MAX || other.mat[j][k] == LLONG_MAX) continue;
					res.mat[i][k] = min(res.mat[i][k], mat[i][j] + other.mat[j][k]);
				}
			}
		}
		return res;
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

Matrix modpow(Matrix m, int pow) {
	int n = m.mat.size();
	Matrix res(n);
	for (int i = 0; i < n; i++) {
		res.mat[i][i] = 0;
	}
	while (pow != 0) {
		if (pow % 2) {
			res = res * m;
		}
		m = m * m;
		pow /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    Matrix mat(n);
    for (int i = 0; i < m; i++) {
    	int a, b, weight;
    	cin >> a >> b >> weight;
    	a--;
    	b--;
    	mat.mat[a][b] = weight;
    }

    Matrix res = modpow(mat, k);
    
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		ans = min(ans, res.mat[i][j]);
    	}
    }
    if (ans == LLONG_MAX) {
    	cout << "IMPOSSIBLE" << endl;
    } else {
    	cout << ans << endl;
    }

	return 0;
}