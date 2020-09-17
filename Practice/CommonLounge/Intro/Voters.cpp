// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C, curr;
    cin >> A >> B >> C;
    set<int> seen;
    set<int> output;
    for (int i = 0; i < A + B + C; i++) {
        cin >> curr;
        if (seen.count(curr) == 0) {
            seen.insert(curr);
            continue;
        }
        output.insert(curr);
    }
    cout << output.size() << endl;
    for (int i : output) {
        cout << i << endl;
    }
}