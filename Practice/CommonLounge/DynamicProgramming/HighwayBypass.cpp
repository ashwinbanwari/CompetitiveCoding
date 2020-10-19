// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int R, C, d;
    cin >> R >> C >> d;
    // first vector for right moving bois
    int valid[R][C];
    pair<vector<long>, vector<long>> grid[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> valid[i][j];
            grid[i][j].first.resize(d+1);
            grid[i][j].second.resize(d+1);
        }
    }
    grid[R-1][0].first[0] = 1;
    for (int i = R-1; i >= 0; i--) {
        for (int j = 0; j < C; j++) {
            // cout << "(" << i << ", " << j << ") " << endl;
            if (valid[i][j] == 0) {
                continue;
            }
            // handle ones on left
            if (j != 0) {
                pair<vector<long>, vector<long>>& left = grid[i][j-1];
                vector<long>& toDaRight = left.first; // have been moving right;
                for (int a = 0; a < d; a++) {
                    grid[i][j].first[a+1] = toDaRight[a];
                    // grid[i][j].first[a+1] %= 20011;
                }
                vector<long>& newbies = left.second; // just turned
                for (int a = 0; a < d+1; a++) {
                    grid[i][j].first[1] += newbies[a];
                    // grid[i][j].first[1] %= 20011;
                }
            }

            // handle ones moving down
            if (i != R-1) {
                pair<vector<long>, vector<long>>& top = grid[i+1][j];
                vector<long>& toDaBottom = top.second; // have been moving down;
                for (int a = 0; a < d; a++) {
                    grid[i][j].second[a+1] = toDaBottom[a];
                    // grid[i][j].second[a+1] %= 20011;
                }
                vector<long>& newbies = top.first; // just turned
                for (int a = 0; a < d+1; a++) {
                    grid[i][j].second[1] += newbies[a];
                    // grid[i][j].second[1] %= 20011;
                }
            }
            /*int res = 0;
            for (int i = 0; i < d+1; i++) {
                res += grid[i][j].first[i];
                res += grid[i][j].second[i];
            }
            cout << res << endl;*/
        }
    }
    long res = 0;
    for (int i = 0; i < d+1; i++) {
        res += grid[0][C-1].first[i];
        res %= 20011;
        res += grid[0][C-1].second[i];
        res %= 20011;
    }
    cout << res << endl;
    return 0;
}