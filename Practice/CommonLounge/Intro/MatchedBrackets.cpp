// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>

using namespace std;

int main() {
    int currDepth = 0;
    int maxDepth = -1, maxDepthIdx;
    int currSymbolsIdx = 1;
    int maxSymbols = -1, maxSymbolsIdx;
    int N, curr;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> curr;
        if (curr == 1) {
            currDepth++;
            if (currSymbolsIdx == -1) {
                currSymbolsIdx = i;
            }
            if (currDepth > maxDepth) {
                maxDepth = currDepth;
                maxDepthIdx = i;
            }
        } else {
            currDepth--;
            if (currDepth == 0 && i - currSymbolsIdx + 1 > maxSymbols) {
                maxSymbols = i - currSymbolsIdx + 1;
                maxSymbolsIdx = currSymbolsIdx;
                currSymbolsIdx = -1;
            } else if (currDepth == 0) {
                currSymbolsIdx = -1;
            }
        }
    }
    cout << maxDepth << " " << maxDepthIdx << " " << maxSymbols << " " << maxSymbolsIdx << endl;
}
