#include <bits/stdc++.h>

using namespace std;

bool works(int dollarCost, int poundCost, vector<int>& dollarGadgets, vector<int>& poundGadgets, int needed, int burles) {
	int a = 0;
	int b = 0;
	while (a+b < needed) {
		if (a == dollarGadgets.size()) {
			burles -= poundGadgets[b] * poundCost;
			b++;

		} else if (b == poundGadgets.size()) {
			burles -= dollarGadgets[a] * dollarCost;
			a++;
		} else {
			if (dollarGadgets[a] * dollarCost < poundGadgets[b] * poundCost) {
				burles -= dollarGadgets[a] * dollarCost;
				a++;
			} else {
				burles -= poundGadgets[b] * poundCost;
				b++;
			}
		}
		if (burles < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int days, numGadgets, needed, burles;
    cin >> days >> numGadgets >> needed >> burles;
    vector<int> dollarCosts(days);
    vector<int> poundCosts(days);
    for (int i = 0; i < days; i++) {
    	cin >> dollarCosts[i];
    }
    for (int i = 0; i < days; i++) {
    	cin >> poundCosts[i];
    }

    vector<int> dollarGadgets;
    vector<int> poundGadgets;
    for (int i = 0; i < numGadgets; i++) {
    	int type, cost;
    	cin >> type >> cost;
    	if (type == 1) {
    		dollarGadgets.push_back(cost);
    	} else {
    		poundGadgets.push_back(cost);
    	}
    }
    sort(dollarGadgets.begin(), dollarGadgets.end());
    sort(poundGadgets.begin(), poundGadgets.end());
    vector<int> bestDollarDay(days);
    vector<int> bestPoundDay(days);
    for (int i = 0; i < days; i++) {
    	if (i != 0) {
    		if (dollarCosts[i] < dollarCosts[i-1]) {
    			bestDollarDay[i] = i;
    		} else {
    			dollarCosts[i] = dollarCosts[i-1];
    			bestDollarDay[i] = bestDollarDay[i-1];
    		}
    		if (poundCosts[i] < poundCosts[i-1]) {
    			bestPoundDay[i] = i;
    		} else {
    			poundCosts[i] = poundCosts[i-1];
    			bestPoundDay[i] = bestPoundDay[i-1];
    		}
    		dollarCosts[i] = min(dollarCosts[i], dollarCosts[i-1]);
    		poundCosts[i] = min(poundCosts[i], poundCosts[i-1]);
    	}
    }
    int x = -1;
    for (int b = days; b >= 1; b/=2) {
    	if ((x+b) < days && !works(dollarCosts[x+b], poundCosts[x+b], dollarGadgets, poundGadgets, needed, burles)) {
    		cerr << (x+b) << " is still bad " << endl;
    		x += b;
    	} else {
    		cerr << (x+b) << " worked " << endl;
    	}
    }
    int bestDay = x+1; // 0-indexed
    print(dollarCosts[bestDay], poundCosts[bestDay], dollarGadgets, poundGadgets, needed, burles, bestDay);


	return 0;
}