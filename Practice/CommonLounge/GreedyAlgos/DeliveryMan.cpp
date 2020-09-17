// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@uw.edu

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    int needToRemove = N - Y;
    int a[N];
    int b[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    vector<int> heap;
    int currentCost = 0;
    for (int i = 0; i < N; i++) {
        heap.push_back(a[i] - b[i]);
        push_heap(heap.begin(), heap.end());
        currentCost += b[i];
    }
    int removed = 0;
    while (removed < needToRemove) {
        currentCost += heap.front();
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        X--;
        removed++;
    }
    while (heap.front() > 0 && X > 0) {
        currentCost += heap.front();
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        X--;
    }
    cout << currentCost << endl;
}
