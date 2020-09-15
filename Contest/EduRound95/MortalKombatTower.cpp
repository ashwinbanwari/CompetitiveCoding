// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int minSkipPoints = 0;
        bool myTurn = false;
        for (int i = 0; i < N; i++) {
            if (i == N-1) {
                if (!myTurn && arr[i] == 1)
                    minSkipPoints++;
                break;
            }
            if (myTurn) {
                if (arr[i+1]) {
                    i++;
                }
                myTurn = false;
                continue;
            } else if (!myTurn) {
                minSkipPoints += arr[i];
                if (!arr[i+1]) {
                    i++;
                }
                myTurn = true;
            }
        }
        cout << minSkipPoints << endl;
    }
}