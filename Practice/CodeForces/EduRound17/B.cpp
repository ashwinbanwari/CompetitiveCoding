#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    vector<pair<int, int>> ports(n); // cost, type(0=usb, 1=ps2)
    for (int i = 0; i < n; i++) {
    	cin >> ports[i].first;
    	string type;
    	cin >> type;
    	if (type == "USB") {
    		ports[i].second = 0;
    	} else {
    		ports[i].second = 1;
    	}
    }

    long long totalCost = 0;
    long long thingsBought = 0;
    sort(ports.begin(), ports.end());
    for (auto& p : ports) {
    	if (a > 0 && p.second == 0) {
    		// usb
    		a--;
    		totalCost += p.first;
    		thingsBought++;
    	} else if (b > 0 && p.second == 1) {
    		b--;
    		totalCost += p.first;
    		thingsBought++;
    	} else if (c!=0) {
    		c--;
    		totalCost += p.first;
    		thingsBought++;
    	}
    }
    cout << thingsBought << " " << totalCost << endl;

	return 0;
}