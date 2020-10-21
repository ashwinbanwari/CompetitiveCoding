// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int arr[5001][5001];

int recurse(string& s, int i, int j) {
    if (arr[i][j] != -1) {
        return arr[i][j];
    }
    if (i >= j) {
        return 0;
    } 
    if (s[i] == s[j]) {
        return arr[i][j] = recurse(s, i+1, j-1);
    } else {
        return arr[i][j] = 1 + min(recurse(s, i+1, j), recurse(s, i, j-1));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string s;
    cin >> N >> s;
    memset(arr, -1, sizeof(arr));
    cout << recurse(s, 0, s.size()-1) << endl;
}
