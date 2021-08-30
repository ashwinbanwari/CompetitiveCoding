#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;
    int i = 0, j = 0, k = 0;
    int turn = 0;
    while (true) {
        switch(turn) {
            case 0:
                if (i == a.size()) {
                    cout << "A" << endl;
                    return 0;
                }
                switch(a[i]) {
                    case 'a':
                        turn = 0;
                        break;
                    case 'b':
                        turn = 1;
                        break;
                    default:
                        turn = 2;
                }
                i++;
                break;
            case 1:
                if (j == b.size()) {
                    cout << "B" << endl;
                    return 0;
                }
                switch(b[j]) {
                    case 'a':
                        turn = 0;
                        break;
                    case 'b':
                        turn = 1;
                        break;
                    default:
                        turn = 2;
                }
                j++;
                break;
            case 2:
                if (k == c.size()) {
                    cout << "C" << endl;
                    return 0;
                }
                switch(c[k]) {
                    case 'a':
                        turn = 0;
                        break;
                    case 'b':
                        turn = 1;
                        break;
                    default:
                      turn = 2;
                }
                k++;
                break;
        }
    }

    return 0;
}