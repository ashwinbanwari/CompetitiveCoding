#include <bits/stdc++.h>

using namespace std;

long long mod = pow(2,32);

class Matrix {
public:
	vector<vector<unsigned>> mat = vector<vector<unsigned>>(65, vector<unsigned>(65));
	Matrix operator*(Matrix& other) {
		Matrix result;
		for (int i = 0; i < 65; i++) {
			for (int j = 0; j < 65; j++) {
				for (int k = 0; k < 65; k++) {
					result.mat[i][k] += mat[i][j] * other.mat[j][k];
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
	Matrix result;
	for (int i = 0; i < 65; i++) {
		result.mat[i][i] = 1;
	}
	while (p!=0) {
		if (p % 2) {
			result = result * m;
		}
		p/=2;
		m=m*m;
	}
	return result;
}

bool isValid(int i, int j) {
	return (i <= 7 && j <= 7 && i >= 0 && j>= 0);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    n++;
    Matrix m;
    for (int i = 0; i < 64; i++) {
    	int currI = i/8;
    	int currJ = i%8;
    	m.mat[i][64] = 1;
    	static vector<pair<int,int>> possibles {{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-2,-1},{-1,-2}};
    	for (auto& p : possibles) {
    		if (isValid(currI+p.first, currJ+p.second)) {
    			m.mat[i][(currI+p.first) * 8 + (currJ+p.second)] = 1;
    		}
    	}
    }
    m.mat[64][64]=1;
    Matrix res = modpow(m, n);
    cout << res.mat[0][64] << endl;

	return 0;
}