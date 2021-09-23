#include <bits/stdc++.h>

using namespace std;

void trim(string& s) {
	int i;
    for (i = 0; i < s.size()-1; i++) {
    	if (s[i] != '0') break;
    }
    s = s.substr(i);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    string res;
    long long sum = 0;
    for (int i = 0; i < s.size(); i++) {
    	sum += s[i] - '0';
    }
    if (sum % 3 == 0) {
    	res = s;
    	trim(res);
    } else if (sum % 3 == 2){
    	string res1, res2;
    	if (s.size() > 1) {
			for (int i = s.size() - 1; i >= 0; i--) {
				if ((s[i] - '0') % 3 == 2) {
					res1 = s;
					res1.erase(res1.begin() + i);
					trim(res1);
					break;
				}
			}
		}
		if (s.size() > 2) {
			int otheridx = -1;
			for (int i = s.size() - 1; i >= 0; i--) {
				if ((s[i] - '0') % 3 == 1) {
					if (otheridx == -1) {
						otheridx = i;
					} else {
						res2 = s;
						res2.erase(res2.begin()+otheridx);
						res2.erase(res2.begin()+i);
						trim(res2);
						break;
					}
				}
			}
		}
		// cerr << res1 << " " << res2 << endl;
		res = (res1.size() > res2.size()) ? res1 : res2;
		if (res.size() == 0) {
			cout << -1 << endl;
			return 0;
		}
    	
	} else {
		string res1, res2;
		if (s.size() > 1) {
			for (int i = s.size()-1; i >= 0; i--) {
				if ((s[i] - '0')%3 == 1) {
					res1 = s;
					res1.erase(res1.begin() + i);
					trim(res1);
					break;
				}
			}
		}
		if (s.size() > 2) {
			int otheridx = -1;
			for (int i = s.size() - 1; i >= 0; i--) {
				if ((s[i] - '0') % 3 == 2) {
					if (otheridx == -1) {
						otheridx = i;
					} else {
						res2 = s;
						res2.erase(res2.begin()+otheridx);
						res2.erase(res2.begin()+i);
						trim(res2);
						break;
					}
				}
			}
		}
		// cerr << res1 << " " << res2 << endl;
		res = (res1.size() > res2.size()) ? res1 : res2;
		if (res.size() == 0) {
			cout << -1 << endl;
			return 0;
		}
    }
    fin:
    
    cout << res << endl;
	return 0;
}