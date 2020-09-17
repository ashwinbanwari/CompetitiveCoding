// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int W, H, move, ptr = 0;
    bool holding = false;
    cin >> W >> H;
    vector<int> game(W, 0);
    for (int i = 0; i < W; i++) {
        cin >> game[i];
    }
    while (true) {
        cin >> move;
        switch(move) {
            case 0:
                goto end;
            case 1:
                ptr = max(ptr - 1, 0);
                break;
            case 2:
                ptr = min(ptr + 1, W-1);
                break;
            case 3:
                if (game[ptr] > 0 && !holding) {
                    game[ptr]--;
                    holding = true;
                }
                break;
            case 4:
                if (game[ptr] != H && holding) {
                    game[ptr]++;
                    holding = false;
                }
        }
    }
    end:
    for (int i = 0; i < game.size(); i++) {
        cout << game[i] << " ";
    }
    cout << endl;
}