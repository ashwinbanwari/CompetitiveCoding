#include <iostream>

using namespace std;

int main() {
    int weight;
    cin >> weight;
    if (weight == 2) {
        cout << "NO";
        return 0;
    }
    cout << (weight % 2 == 0 ? "YES" : "NO");
}