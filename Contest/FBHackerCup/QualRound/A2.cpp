#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1000;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream in;
    in.open("inA2.txt", ios::in);
    ofstream out;
    out.open("outA2.txt", ios::trunc);

    int T;
    in >> T;
    for (int i = 1; i <= T; i++) {
        vector<vector<int>> board(26, vector<int>(26, INF));
        string s;
        int K;
        in >> s >> K;
        unordered_map<int, int> has;
        for (int i = 0; i < s.size(); i++) {
            has[s[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            board[i][i] = 0;
        }
        while (K--) {
            string edge;
            in >> edge;
            board[edge[0]-'A'][edge[1]-'A'] = 1;
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (board[i][j] > board[i][k] + board[k][j]) {
                        board[i][j] = min(board[i][k] + board[k][j], INF);
                    }
                }
            }
        }
        int bestSum = INF;
        for (int j = 0; j < 26; j++) {
            int currSum = 0;
            for (int i = 0; i < 26; i++) {
                currSum += has[i] * board[i][j];
            }
            bestSum = min(bestSum, currSum);
        }
        out << "Case #" << i << ": ";
        if (bestSum >= INF) {
            out << -1 << endl;
        } else {
            out << bestSum << endl;
        }
    }

    return 0;
}