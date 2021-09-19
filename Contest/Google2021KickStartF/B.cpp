#include <bits/stdc++.h>

using namespace std;

class Attraction {
public:
	int happiness;
	int start;
	int end;
	bool operator==(Attraction& other) {
		return happiness == other.happiness && start == other.start && end == other.end;
	}
	
};

struct happiComparator {
	int operator()(const Attraction& a, const Attraction& b) const {
		if (a.happiness == b.happiness) {
			return a.end < b.end;
		}
		return a.happiness > b.happiness;
	}
};

struct startComparator {
	int operator()(const Attraction& a, const Attraction& b) const {
		return a.start < b.start;
	}
};

struct endComparator {
	int operator()(const Attraction& a, const Attraction& b) const {
		return a.end < b.end;
	}
};




int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
    	int D, N, K;
    	cin >> D >> N >> K;

    	multiset<Attraction, startComparator> attractions;
    	for (int i = 0; i < N; i++) {
    		int a, b, c;
    		cin >> a >> b >> c;
    		attractions.insert(Attraction{a, b, c});
    	}
    	multiset<Attraction, endComparator> attractionsToRemove;
    	multiset<Attraction, happiComparator> bestAttractions;
    	multiset<Attraction, happiComparator> nextBestAttractions;
    	long long currTotal = 0;
    	long long currBest = 0;
    	auto startPtr = attractions.begin();
    	for (int i = 1; i <= D; i++) {
    		while(startPtr != attractions.end() && startPtr->start == i) {
    			Attraction curr = *startPtr;
    			attractionsToRemove.insert(curr);
    			if (bestAttractions.size() == K) {
    				Attraction lastEle = *(--bestAttractions.end());
    				if (curr.happiness > lastEle.happiness) {
    					bestAttractions.insert(curr);
    					bestAttractions.erase(--bestAttractions.end());
    					nextBestAttractions.insert(lastEle);
    					currTotal += curr.happiness - lastEle.happiness;
    				} else {
    					nextBestAttractions.insert(curr);
    				}
    			} else {
    				bestAttractions.insert(curr);
    				currTotal += curr.happiness;
    			}
    			startPtr++;
    		}
    		while (!attractionsToRemove.empty() && attractionsToRemove.begin()->end < i) {
    			Attraction curr = *attractionsToRemove.begin();
    			if (nextBestAttractions.count(curr)) {
    				nextBestAttractions.erase(curr);
    			} else if (bestAttractions.count(curr)) {
    				/*auto it = bestAttractions.begin();
    				while (it != bestAttractions.end()) {
    					cerr << it->start << " " << it->end << " " << it->happiness << endl;
    					it++;
    				}*/
    				int removed = bestAttractions.erase(curr);
    				currTotal -= removed * curr.happiness;
    				// cerr << removed << endl;
    				// add from nextBest
    				for (int i = 0; i < removed && !nextBestAttractions.empty(); i++) {
    					Attraction nextBest = *nextBestAttractions.begin();
    					bestAttractions.insert(nextBest);
    					nextBestAttractions.erase(nextBestAttractions.begin());
    					currTotal += nextBest.happiness;
    				}
    			} 
    			attractionsToRemove.erase(attractionsToRemove.begin());
    		}
    		// cerr << "Day " << i << ", we have " << currTotal << endl;
    		currBest = max(currBest, currTotal);
    	}
    	cout << "Case #" << i << ": " << currBest << endl;

    }

	return 0;
}