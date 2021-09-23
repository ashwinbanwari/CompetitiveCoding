#include <bits/stdc++.h>

using namespace std;

vector<int> best(string a, string b) {
	int currIdx = 0;
	vector<int> indexes;
    for (int i = 0; i < b.size(); i++) {
    	while (currIdx != a.size() && b[i] != a[currIdx]) {
    		currIdx++;
    	}
    	if (currIdx == a.size()) {
    		return indexes;
    	}
    	indexes.push_back(currIdx);
    	currIdx++;
    }
    return indexes;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b;
    cin >> a >> b;
    string aRev(a);
    string bRev(b);
    reverse(aRev.begin(), aRev.end());
    reverse(bRev.begin(), bRev.end());
    vector<int> bestLeft = best(a, b);
    vector<int> bestRight = best(aRev, bRev);
    for (int i = 0; i < bestRight.size(); i++) {
    	bestRight[i] = a.size() - bestRight[i] - 1;
    }
    reverse(bestRight.begin(), bestRight.end());

    int bestMax = 0;
    int bestSzLeft = 0;
    int bestSzRight = 0;
    /*for (int i : bestLeft) {
    	cerr << i << " ";
    }
    cerr << endl;
    for (int i : bestRight) {
    	cerr << i << " ";
    }
    cerr << endl;*/
    for (int i = -1; i < (int)a.size(); i++) {
    	int szLeft = distance(bestLeft.begin(), upper_bound(bestLeft.begin(), bestLeft.end(), i));
    	int szRight = distance(lower_bound(bestRight.begin(), bestRight.end(), i+1), bestRight.end());
    	int len = szLeft + szRight;
    	// cerr << szLeft << " " << szRight << endl;
    	if (len > bestMax) {
    		bestMax = len;
    		bestSzLeft = szLeft;
    		bestSzRight = szRight;
    	}
    }
    if (bestMax == 0) {
    	cout << "-" << endl;
    } else if (bestMax >= b.size()) {
    	cout << b << endl;
    } else {
    	cout << b.substr(0, bestSzLeft) << b.substr(b.size() - bestSzRight) << endl;
    }
    
    

    

	return 0;
}