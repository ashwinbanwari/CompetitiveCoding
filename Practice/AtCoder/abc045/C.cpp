#include <bits/stdc++.h>

using namespace std;
long long sum = 0;

void addToSum(vector<int>& bitMask, string& S) {
    int idxStart = 0;
    for (int i = 0; i < bitMask.size(); i++) {
        if (bitMask[i]) {
            string numStr;
            while (idxStart <= i) {
                numStr += S[idxStart];
                idxStart++;
            }
            sum += stoll(numStr);
        }
    }
    string numStr = "";
    while (idxStart <= S.size()) {
        numStr += S[idxStart];
        idxStart++;
    }
    sum += stoll(numStr);
}

void recurse(string& S, vector<int>& bitMask, int position) {
    if (position == bitMask.size()) {
        addToSum(bitMask, S);
        return;
    }
    bitMask[position] = 0;
    recurse(S, bitMask, position+1);
    bitMask[position] = 1;
    recurse(S, bitMask, position+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    sum = 0;
    string S;
    cin >> S;
    vector<int> bitMask(S.size()-1);
    recurse(S, bitMask, 0);
    cout << sum << endl;


    return 0;
}