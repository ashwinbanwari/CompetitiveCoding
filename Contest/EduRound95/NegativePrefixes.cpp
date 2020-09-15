// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y, k;
        cin >> x >> y >> k;
        ll neededSticks = k * y + k - 1;
        ll currSticks = 1;
        ll trades = k;
        if (neededSticks % (x-1)) {
            trades += neededSticks/(x-1) + 1;
        } else {
            trades += neededSticks/(x-1);
        }
        cout << trades << endl;
    }
}