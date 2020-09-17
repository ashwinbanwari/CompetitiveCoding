#include <iostream>

using namespace std;

void NumMoves(string k);

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int chars;
        cin >> chars;
        string k;
        cin >> k;
        NumMoves(k);
    }
}

void NumMoves(string k) {
    int error = 0;
    int opens = 0;
    for (char i : k) {
        switch(i) {
            case '(':
               opens++;
               break;
            case ')':
                if (opens == 0) {
                    error++;
                } else {
                    opens--;
                }
        }
    }
    cout << error << "\n";
}