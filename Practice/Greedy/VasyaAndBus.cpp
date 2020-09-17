#include <iostream>

using namespace std;

int main() {
    int adults, children;
    cin >> adults >> children;
    if (adults == 0 && children == 0) {
        cout << 0 << " " << 0 << "\n";
        return 0;
    }
    if (adults == 0) {
        cout << "Impossible" << "\n";
        return 0;
    }
    if (children == 0) {
        cout << adults << " " << adults << "\n";
        return 0;
    }
    int max = adults + children - 1;
    int min = adults + (children - adults > 0 ? (children-adults) : 0);
    cout << min << " " << max << "\n";
    return 0;


}