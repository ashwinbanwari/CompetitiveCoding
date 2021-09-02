#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> inp(n);
    vector<pair<int, int>> out;
    vector<int> heap;
    for (int i = 0; i < n; i++) {
    	cin >> inp[i].first >> inp[i].second;
    }
    sort(inp.begin(), inp.end(), [](const pair<int,int>& a, const pair<int, int>& b) {return a.first < b.first;});
    int currStart = -1;
    for (int i = 0; i < n; i++) {
    	while (!heap.empty() && heap[0] < inp[i].first) {
    		pop_heap(heap.begin(), heap.end(), greater<int>());
    		int last = heap.back();
    		heap.pop_back();
    		if (heap.size() == k-1) {
    			out.push_back(make_pair(currStart, last));
    		}
    	}
    	if (heap.size() == k-1) {
    		currStart = inp[i].first;
    	}
    	heap.push_back(inp[i].second);
    	push_heap(heap.begin(), heap.end(), greater<int>());
    }
    if (heap.size() >= k) {
    	while (heap.size() != k) {
    		pop_heap(heap.begin(), heap.end(), greater<int>());
    		heap.pop_back();
    	}
    	out.push_back(make_pair(currStart, heap[0]));
    }
    cout << out.size() << endl;
    for (int i = 0; i < out.size(); i++) {
    	cout << out[i].first << " " << out[i].second << endl;
    }

	return 0;
}