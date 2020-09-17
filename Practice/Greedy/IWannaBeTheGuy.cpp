#include <iostream>
#include <unordered_set>
#include <cstdlib>
using namespace std;

int main() {
    unordered_set<int> levels;
    int numLevels, Xlevels, Ylevels, temp;
    cin >> numLevels >> Xlevels;
    for (int i = 0; i < Xlevels; i++) {
        cin >> temp;
        levels.insert(temp);
    }
    cin >> Ylevels;
    for (int i = 0; i < Ylevels; i++) {
        cin >> temp;
        levels.insert(temp);
    }
    for (int i = 1; i <= numLevels; i++) {
        unordered_set<int>::iterator it = levels.find(i);
        if (it == levels.end()) {
            cout << "Oh, my keyboard!";
            exit(0);
        }
    }
    cout << "I become the guy.";
    return 0;
}