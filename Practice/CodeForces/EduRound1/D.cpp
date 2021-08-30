#include <bits/stdc++.h>

using namespace std;


int dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& seen) {
    if (!(x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && !seen[x][y])) {
        return 0;
    }
    if (board[x][y] == '*') {
        return 1;
    } else {
        int ret = 0;
        seen[x][y] = true;
        ret += dfs(x+1, y, board, seen);
        ret += dfs(x, y+1, board, seen);
        ret += dfs(x-1, y, board, seen);
        ret += dfs(x, y-1, board, seen);
        return ret;
    }
}

void updateEls(int x, int y, vector<vector<char>>& board, vector<vector<int>>& results, int ans) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || results[x][y] != -1 || board[x][y] == '*') {
        return;
    }
    results[x][y] = ans;
    updateEls(x+1, y, board, results, ans);
    updateEls(x, y+1, board, results, ans);
    updateEls(x-1, y, board, results, ans);
    updateEls(x, y-1, board, results, ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> museum(n, vector<char>(m));
    vector<vector<int>> answers(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> museum[i][j];
        }
    }
    vector<pair<int, int>> inputs;
    while (k--) {
        int x, y;
        cin >> x >> y;
        inputs.push_back(make_pair(x,y));
    }
    vector<vector<bool>> seen(n, vector<bool>(m));
    for (pair<int, int>& p : inputs) {
        int x = p.first - 1;
        int y = p.second - 1;
        if (answers[x][y] != -1) {
            cout << answers[x][y] << "\n";
            continue;
        }
        int res = dfs(x, y, museum, seen);
        updateEls(x, y, museum, answers, res);
        cout << res << "\n";
    }

    return 0;
}