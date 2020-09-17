#include <iostream>
#include <string>

using namespace std;

void DoCase(int len, string str);

int main() {
    int numCases;
    cin >> numCases;
    for (int i = 0; i < numCases; i++) {
        int length; string str;
        cin >> length >> str;
        DoCase(length, str);
    }
}

void DoCase(int len, string str) {
    string a = "",b ="";
    for (int i = 0; i < len; i++) {
        if (str[i] == '1') {
            break; 
        } else {
            a+='0';
        }
    }
    for (int i = len-1; i >= 0; i--) {
        if (str[i] == '0') {
            break; 
        } else {
            b+='1';
        }
    }
    cout << a << (a.size() + b.size() == len ? "" : "0") << b << "\n";
}

