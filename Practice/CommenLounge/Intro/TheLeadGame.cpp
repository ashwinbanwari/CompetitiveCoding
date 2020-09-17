// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, temp1, temp2;
    cin >> N;
    int aSum = 0;
    int bSum = 0;
    int maxLead = 0;
    int leader = 1;
    while (N--) {
        cin >> temp1 >> temp2;
        aSum += temp1;
        bSum += temp2;
        int diff = abs(aSum - bSum);
        if (diff > maxLead) {
            maxLead = diff;
            leader = (aSum > bSum) ? 1 : 2;
        }
    }
    cout << leader << " " << maxLead << endl;
}