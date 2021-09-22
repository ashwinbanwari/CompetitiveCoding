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

vector<int> keepIncreasing(vector<int> a, vector<int> b) {
	for (int i : a) {
		cerr << i << " ";
	}
	cerr << endl;
	for (int i : b) {
		cerr << i << " ";
	}
	cerr << endl;

	auto bSegment = lower_bound(b.begin(), b.end(), a.back());
	auto aSegment = lower_bound(a.begin(), a.end(), b.front());
	
	// cerr << *aSegment << endl;
	// cerr << *bSegment << endl;
	int aSegLen = distance(aSegment, a.end());
	int bSegLen = distance(b.begin(), bSegment);
	if (aSegment == a.begin()) {
		aSegLen = 0;
	}
	cerr << aSegLen << " " << bSegLen << endl;
	vector<int> ans;
	if (aSegLen < bSegLen) {
		if (aSegLen != 0) {
			ans.insert(ans.end(), a.begin(), aSegment);
		}
		ans.insert(ans.end(), b.begin(), b.end());
	} else {
		ans.insert(ans.end(), a.begin(), a.end());
		ans.insert(ans.end(), bSegment, b.end());
	}
	return ans;
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
    vector<int> resultIdxes;
    cerr << "bestLeft size " << bestLeft.size() << " bestRight size " << bestRight.size() << endl;
    if (bestLeft.empty() && bestRight.empty()) {
    	cout << "-" << endl;
    	return 0;
    } else if (bestLeft.empty()) {
    	resultIdxes = bestRight;
    } else if (bestRight.empty()) {
    	resultIdxes = bestLeft;
    } else {
    	resultIdxes = keepIncreasing(bestLeft, bestRight);
    }
    auto last = unique(resultIdxes.begin(), resultIdxes.end());
    resultIdxes.erase(last, resultIdxes.end());
    for (int i : resultIdxes) {
    	cerr << i << " ";
    	cout << a[i];
    }
    cerr << endl;

    

	return 0;
}