// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>
#include <string>

using namespace std;

void solve(int n, int m);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }
}

void solve(int n, int m) {
    string answer = "NO";
    while (n--) {
        int unused, bl, tr;
        cin >> unused >> tr;
        cin >> bl >> unused;
        if (tr == bl) {
            answer = "YES";
        }
    }
    if (m % 2) {
        answer = "NO";
    }
    cout << answer << endl;
}
