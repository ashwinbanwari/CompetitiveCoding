#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string str;
    cin >> str;
    string target = "hello";
    int element = 0;
    for (char c : str) {
        if (element == 5) {
            break;
        }
        if (c == target[element]) {
            element++;
        }
    }
    cout << ((element == 5) ? "YES" : "NO") << "\n";
    return EXIT_SUCCESS;
}

