#include <iostream>
using namespace std;

int main() {
    int x = 0, y = 0, z = 0;
    int forces;
    cin >> forces;
    for (int i = 0; i < forces; i++) {
        int newX,newY,newZ;
        cin >> newX >> newY >> newZ;
        x += newX;
        y += newY;
        z += newZ;
    }
    if (x == 0 && y == 0 && z == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    exit(0);
}